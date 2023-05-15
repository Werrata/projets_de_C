
#include <stdio.h>
#include <string.h>


#define NBLETTRES 20


typedef struct ninja
{
  char nom[NBLETTRES + 1];
  int chakra;
  struct ninja * previous;
  struct ninja * next;
  
} NINJA;

typedef struct ninja * ptNINJA;


typedef struct clan
{
  char nom[NB_LETTRES + 1];
  int nombre;
  NINJA * hokage;
  NINJA * genin;
} CLAN; 

