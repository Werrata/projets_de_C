#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define DIMX 20
#define DIMY 11
#define PA 5
#define D 4
#define F 3
#define C 2


// déclaration de nouveaux types de variables
typedef unsigned char indice;
typedef char* Vect;
typedef Vect* Grid;
typedef enum boolean {false,true} boolean;


// prototypes
Grid createGrid(void);
void dispGrid(Grid G);
void locateShip(indice* ord, indice* abs, indice* orient, indice len);
boolean testShip(Grid G, indice i, indice j, indice o, indice len);
void placeShips(Grid G);

