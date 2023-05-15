
#include "fonctions_TP1.h"


char* toUpperCase(char* entree)
{
  char* sortie = calloc(strlen(entree)+1,1);
  char* index = sortie;

  while (*entree != '\0')
  {
    if( (*entree >= 'a')&&(*entree <= 'z') )
    { 
      *index = *entree - 32;
    }
    else *index = *entree;
    index++;
    entree++;
  }
  return sortie;

}



char * backwardString(char * entree)
{
  char *sortie = calloc(strlen(entree) + 1,1);
  char *index = sortie + strlen(entree) - 1;
  
  while (*entree != '\0')
  {
    *index = *entree;
    entree = entree + 1;
    index = index - 1;
  }
  
  return sortie;
}


  
char * stripSpace(char * entree)
{
  char *sortie = calloc(strlen(entree) + 1,1);
  char *index = sortie;
  while (*entree != '\0')
  {
    if( ((*entree >= 'a')&&(*entree <= 'z'))||((*entree >= 'A')&&(*entree <= 'Z')) )
    {
       *index = *entree;
       index++;
    }
    entree++;
  }
  return sortie;
}


  
bool isPalindrom(char * str)
{
  char * copie = stripSpace(str);
  copie = toUpperCase(copie);
  char * reverse_copie = backwardString(copie);
  return (0 == strcmp(copie, reverse_copie));
}






int wordCount(char * s, char * toBeFind)
{
  int count = 0;
  int detectionCommencee = 0;
  char * ptr = toBeFind; // Copie obligatoire pour ne pas perdre
 
  while (*toBeFind != '\0')
  {
    if *ptr == *s
    {
      detectionCommencee = 1;
    }
    while( (detectionCommencee == 1)&&(*s == *ptr) ) 
    {
      if (ptr == '\0')
      {
        count++;
        detectionCommencee = 0;
      }
      s++;
      ptr++;
    }
    s++;
    toBeFind = ptr;
  }
  return count;
}
      

















