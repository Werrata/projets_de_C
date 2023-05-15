#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	struct stat sb;
	
	char[] welcome_message = "Bienvenue dans le Shell ENSEA. \nPour quitter, tapez 'exit'.";
	write(STDOUT_FILENO, welcome_message, strln(welcome_message));
	exit(EXIT_SUCCESS);
}
