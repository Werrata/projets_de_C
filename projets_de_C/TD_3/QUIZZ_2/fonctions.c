
#include "fonctions.h"


Grid createGrid(void)
{
  int i = 0;
  int j = 0;
  
  Grid G; 
  
  G = malloc(sizeof(Vect)*DIMY);
  
  for(j = 0; j < DIMX; i++)
  {
    for(i = 0; i < DIMY; i++)
    {
      G[j][i] = '~';
    }
  }
  return G;
}



void dispGrid(Grid G)
{
  int i = 0;
  int j = 0;
 
  for(i = 0; i < DIMY; i++)
  {
    for(j = 0; j < DIMX; j++)
    {
      printf("%c",G[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
