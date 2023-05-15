
#include "tris.h"

int main(void)
{
  TABint tab;
  TABint T1;
  float * t1;
  float * t2;
  
  randomInitTABint(tab);
  randomInitTABint(T1);
  
  gettimeofday(&t1, (void *) NULL);
  selectionSortTABint(tab, TAILLE);
  gettimeofday(&t2, (void *) NULL);
  printf("%d\n",t2 - t1);
  
  gettimeofday(&t1, (void *) NULL);
  mergeSortTABint(T1);
  gettimeofday(&t2, (void *) NULL);
  printf("%d\n",t2 - t1);
  
}
