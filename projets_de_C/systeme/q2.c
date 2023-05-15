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
        buffer[lenBuffer-1] = 0;
        //Si une commande shell linux est rentree, on la fait executer par un fils
        id = fork();
        if(0==id) {
            if(-1 == execlp(buffer, buffer, (char*) NULL)) exit(EXIT_FAILURE);
        }
        //Le pere attend la fin de l'execution du fils
        else wait(&status);
    }
    return EXIT_SUCCESS;
}