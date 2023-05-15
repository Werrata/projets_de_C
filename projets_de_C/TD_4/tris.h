#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TAILLE 10

typedef int TABint[TAILLE];

void randomInitTABint(TABint);
void selectionSortTABint(TABint tab, int N);
int posMinTABint(TABint tab, int indice_debut, int indice_fin);
void sortAndMerge(TABint T1, TABint T2, int idebg1, int iendg1, int idebg2, int iendg2);
void mergeSortTABint(TABint T1);
