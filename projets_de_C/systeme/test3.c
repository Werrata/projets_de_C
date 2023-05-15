#include <stdlib.h>


int main(int num, char *argv[]){
int * val;
val = (int*)0xFFFFFFF8;
return *val;
}