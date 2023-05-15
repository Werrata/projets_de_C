#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define DIMX 5

#define DIMY 5


typedef struct etat
{
  int tableau[DIMX][DIMY];
  int fourmiDirection;
  int x;
  int y;
  struct etat* next;
}ETAT;


typedef ETAT * ptETAT;



ETAT * createFirstState(int direction, int x, int y);
ETAT * createNewState(int direction, int x, int y);
void displayState(ETAT * e);
ETAT * createNextState(ETAT * tete);







