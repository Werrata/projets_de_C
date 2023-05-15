
#include "fonctions_TP1.h"

int main (void)
{
  //test stripSpace
  char exemple[] = "Az&éer&é&&&éty   uio^éé  é'po/.dsz\n";
  char *pointeur = stripSpace(exemple);
  
  printf("%s\n", exemple);
  printf("%s\n", pointeur);
  
  free(pointeur);


  //test toUpperCase
  char demonstration[] = "HelLo WoRlD !\n";
  char* ptr = toUpperCase(demonstration);

  printf("%s\n",demonstration);
  printf("%s\n",ptr);
  free(ptr);
  
  if (isPalindrom("Laval"));
  {
    printf("Laval est un palindrome");
  }
}




