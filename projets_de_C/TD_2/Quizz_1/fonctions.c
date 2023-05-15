

#include "fonctions.h"

void displayDices(int dices[3])
{
  printf("%d  ",dices[0]);
  printf("%d  ",dices[1]);
  printf("%d  \n",dices[2]);
}
  

int isWinning(int dices[3])
{
  if dices[0], dices[1], dices[2] == 4,2,1 return 1;
  else if dices[0], dices[1], dices[2] == 4,1,2 return 1;
  else if dices[0], dices[1], dices[2] == 1,2,4 return 1;
  else if dices[0], dices[1], dices[2] == 1,4,2 return 1;
  else if dices[0], dices[1], dices[2] == 2,4,1 return 1;
  else if dices[0], dices[1], dices[2] == 2,1,4 return 1;
}



