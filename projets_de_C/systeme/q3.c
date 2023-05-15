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

    while(1) {
        if(-1 == write(STDOUT_FILENO, "enseash % ", lenShellMessage)) exit(EXIT_FAILURE);
        if(-1 == (lenBuffer = read(STDOUT_FILENO, buffer, 300))) exit(EXIT_FAILURE);

        //Condtions de sortie particulieres
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
        else wait(&status);
    }
    return EXIT_SUCCESS;
}