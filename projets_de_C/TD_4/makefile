
secure = -Wall -Werror

debug = -Wall -g

program: main.o tris.o
	 gcc main.o tris.o -o program
	 rm *.o

main.o: main.c
	gcc main.c -c -o main.o



tris.o: tris.c
	gcc tris.c -c -o tris.o



debug:  tris.c  main.c
	gcc tris.c main.c $(debug) -o program


secure: tris.c  main.c
	gcc tris.c main.c $(secure) -o program


laver: 
	rm program
	rm *.o
	 
