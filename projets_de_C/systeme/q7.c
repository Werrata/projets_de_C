#include <time.h>
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
    char * list_arg_buffer[254]; //nombre d'argument max. d'une commande Linux
    int num_arg = 1;
    int lenBuffer;
    int filename_indicator = 0;
    int id, status;
    int file_descriptor[2]; //Sert pour la communication entre pere et fils avec le pipe
    int lenShellMessage = strlen("enseash % ");
    int type_ShellMessage = 0;
    char exit_message[80];
    char signal_message[80];
    char * filename;
    clockid_t clock_id;
    struct timespec tp;
    FILE * file;
    long tim;
    long tim2;
    int32_t tim_div = 1000000;
    int32_t tim_mult = 1000;

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

        // Conditions de sortie particulieres
        if(0 == lenBuffer) {
            if(-1 == write(STDOUT_FILENO, "Bye bye...\n", strlen("Bye bye...\n"))) exit(EXIT_FAILURE);
            return EXIT_SUCCESS;
        }
        buffer[lenBuffer-1] = 0;
        if(0 == strcmp(buffer, "exit")){
            if(-1 == write(STDOUT_FILENO, "Bye bye...\n", strlen("Bye bye...\n"))) exit(EXIT_FAILURE);
            return EXIT_SUCCESS;
        }

        //gestion du temps pour l'affichage du temps d'execution
        clock_gettime(CLOCK_BOOTTIME, &tp);
        tim = tp.tv_sec*tim_mult + tp.tv_nsec/tim_div;
        
        //On fait executer la commande shell en entree par un fils
        //On cree un pipe pour gérer la communication entre le pere et le fils
        pipe(file_descriptor);
        id = fork();
        if(0==id) {

            list_arg_buffer[0] = strtok(buffer," ");
            num_arg = 1;
            while((NULL != (list_arg_buffer[num_arg] = strtok(NULL," ")))&&(8 != filename_indicator)) {
                
                //Si il y a une redirection vers un fichier, on enregistre le nom du fichier et on sort du while
                if((0 == strcmp(list_arg_buffer[num_arg], ">"))||(0 == strcmp(list_arg_buffer[num_arg], "<"))) {
                    list_arg_buffer[num_arg] = "\0";
                    filename = strtok(NULL,"\0");
                    filename_indicator = 8;
                }
                num_arg++;
            }

            if(8 != filename_indicator) {
                if(-1 == execvp(list_arg_buffer[0], list_arg_buffer)) exit(EXIT_FAILURE);
            }
            else if(8 == filename_indicator) {

                // Il faut dupliquer la sortie du execvp et l'envoyer vers un fichier dup2
            }
        }

        
        else {
            
            //le pere attend la fin d'exectution du fils, et recupere le temps d'execution et les exits status
            wait(&status);

            //On calcule le temps d'execution de la commande
            clock_gettime(CLOCK_BOOTTIME, &tp);
            tim2 = tp.tv_sec*tim_mult + tp.tv_nsec/tim_div;
            tim = tim2 - tim;

            if(8 == filename_indicator) {
                file = fopen(filename, "w+");
            }

            //On construit le message de debut de shield
            if(WIFEXITED(status)) {
                sprintf(exit_message, "enseash [exit:%d|%lims] %% ", WEXITSTATUS(status), tim);
                type_ShellMessage = 1;
            }
            else if(WIFSIGNALED(status)) {
                sprintf(signal_message, "enseash [sign:%d|%lims] %% ", WTERMSIG(status), tim);
                type_ShellMessage = 2;
            }
        }
    }
    return EXIT_SUCCESS;
}


// cours sur les systemes d'exploitations (linux) qui a l'aire pas mal : 
// https://perso.liris.cnrs.fr/pierre-antoine.champin/enseignement/linux/s4.html