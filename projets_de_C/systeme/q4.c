#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
    char buffer[300];
    int lenBuffer;
    int id, status;
    int lenShellMessage = strlen("enseash % ");
    int type_ShellMessage = 0;
    char exit_message[20];
    char signal_message[20];


    while(1) {
        //Selection du type d'affichage en fonction de la fin de la derniere commande
        if(1 == type_ShellMessage){
            if(-1 == write(STDOUT_FILENO, exit_message, strlen(exit_message))) exit(EXIT_FAILURE);
            type_ShellMessage = 0;
        }
        else if(2 == type_ShellMessage){
            if(-1 == write(STDOUT_FILENO, signal_message, strlen(signal_message))) exit(EXIT_FAILURE);
            type_ShellMessage = 0;
        }
        else {
            if(-1 == write(STDOUT_FILENO, "enseash % ", lenShellMessage)) exit(EXIT_FAILURE);
            type_ShellMessage = 0;
        }

        // Attente de l'entree
        if(-1 == (lenBuffer = read(STDOUT_FILENO, buffer, 300))) exit(EXIT_FAILURE);

        // Condtions de sortie particulieres
        if(0 == lenBuffer) {
            if(-1 == write(STDOUT_FILENO, "Bye bye...\n", strlen("\nBye bye...\n"))) exit(EXIT_FAILURE);
            return EXIT_SUCCESS;
        }
        buffer[lenBuffer-1] = 0;
        if(0 == strcmp(buffer, "exit")){
            if(-1 == write(STDOUT_FILENO, "Bye bye...\n", strlen("\nBye bye...\n"))) exit(EXIT_FAILURE);
            return EXIT_SUCCESS;
        }

        //Si une commande shell linux est rentree, on la fait executer par un fils
        id = fork();
        if(0==id) {
            if(-1 == execlp(buffer, buffer, (char*) NULL)) exit(EXIT_FAILURE);
        }
        else {
            wait(&status);
            if(WIFEXITED(status)) {
                sprintf(exit_message, "enseash [exit:%d] %% ", WEXITSTATUS(status));
                type_ShellMessage = 1;
            }
            else if(WIFSIGNALED(status)) {
                sprintf(signal_message, "enseash [sign:%d] %% ", WTERMSIG(status));
                type_ShellMessage = 2;
            }
        }
    }
    return EXIT_SUCCESS;
}