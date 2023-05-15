

#include "fonctions.h"


int main(void)
{
  int test1[3]={2,6,5};
  int test2[3]={2,4,1};
  printf("*********Simulateur de 421*******\ textbackslash n");
  displayCombinaison(test1);
  displayCombinaison(test2);
  
  printf("Test de la fonction de validation : %d, %d",isWinning(test1),isWinning(test2));
}




