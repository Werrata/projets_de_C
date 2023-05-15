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
    int i = 0;
    for(i=0; i<1000000000; i++);
    return 59;
}