
#include "langton.h"


int main(void)
{
  int direction = 0;
  int x = 2;
  int y = 2;
  int nb_etapes = 4;
  int compt = 0;
  
  ETAT * fourmi = createNewState(direction, x, y);
  
  for(compt = 0; compt < nb_etapes; compt++)
  {
    fourmi = createNextState(fourmi);
    displayState(fourmi);
    printf("\n");
  }
}
