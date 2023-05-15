
secure = -g -Wall

program : fonctions.c  main.c
	  gcc fonctions.c main.c $(secure) -o program


smart : fonctions.c  main.c
	gcc fonctions.c main.c -w -o program


clean : program
	rm -f ./program
