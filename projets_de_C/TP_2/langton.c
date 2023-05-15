#include "langton.h"




ETAT * createFirstState(int direction, int x, int y){
}


ETAT * createNewState(int direction, int x, int y)
{
  ETAT *etape;
  
  etape = calloc(sizeof(ETAT),1);
  // il y a aussi un tableau initialisé à 0 qui n'est pas affiché 
  (*etape).fourmiDirection = direction;
  etape->x = x;
  etape->y = y;

  return etape;
}
  


ETAT * createNextState(ETAT * tete)
{
  ETAT *old = tete;
  ETAT *new = createNewState(0, 0, 0);
  int i = 0;
  int j = 0;
  
  while ((*old).next != NULL)
  {
    old = createNewState(old->fourmiDirection, old->x, old->y);
  }
  old->next = new;
  
  for(i = 0; i < DIMX; i++)
  {
    for(j = 0; j < DIMY; j++)
    {
      new->tableau[i][j] = (*old).tableau[i][j];
    }
  }
  new->tableau[old->x][old->y] = 1 - (*old).tableau[old->x][old->y];
  
  (old->tableau[old->x][old->y]==0)?((*new).fourmiDirection = ((*new).fourmiDirection + 1)%4):((*new).fourmiDirection = ((*new).fourmiDirection + 1)%4);
  
  switch((*new).fourmiDirection)
  {
    case 0:
    new->x = (*new).x;
    new->y = (*new).y + 1; 
    break;
  
    case 1:
    new->x = (*new).x + 1;
    new->y = (*new).y;
    break;
    
    case 2:
    new->x = (*new).x;
    new->y = (*new).y - 1;
    break;
    
    case 3:
    new->x = (*new).x - 1;
    new->y = (*new).y;
    break;
  }
  return new;
}
    
  

void displayState(ETAT * e)
{
  
  int i;
  int j;
  for(i = 0; i < DIMX; i++)
  {
    for(j = 0; j < DIMY; j++)
    {            
      
      if((i == e->x)&&(j == e->y))
      {
        switch(e->fourmiDirection)
        {
          case 0:
          printf("%c",'^');
          break;
          
          case 1:
          printf("%c",'>');
          break;
          
          case 2:
          printf("%c",'v');
          break;
          
          case 3:
          printf("%c",'<');
          break;
        }
      }
      else
      (e->tableau[i][j]==0)?(printf("B")):(printf("X")); 
    }
  printf("\n");
  }
}
      
 











