
#include "fonctions.h"



void countCharStatic(String a)
{
  
  char * indice = a;
  
  while(*indice != '\0')
  {
    dictionnaire[*indice]++;
    indice++;
  }
}
