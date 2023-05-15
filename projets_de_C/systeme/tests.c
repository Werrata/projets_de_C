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


int main(void){
    char liste[12] = "a b c d -ef";
    char * conc_liste[8];
    char * list_arg[5];
    char * filename;
    int i = 0;
    int j = 1;
    conc_liste[0] = strtok(liste," ");
    while(NULL != (conc_liste[j] = strtok(NULL," "))) {
        j++;
        if(j==3) filename = strtok(NULL,"\0");
    }

    for(i=0;i<2;i++){
        printf(conc_liste[i]);
        printf("\n");
    }
    printf("AA");
    printf(filename);
    printf("\n");

    list_arg[0] = "ping";
    list_arg[1] = "google.com";
    //execvp(list_arg[0],list_arg);
    return 256;
}
