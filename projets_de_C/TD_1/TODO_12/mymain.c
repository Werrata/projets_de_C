
#include "myfcts.h"

int main(void)
{
  int A;
  int B;
  int C;
  int D;
  printf("Entrer quatre nombres :\n");
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  scanf("%d", &D);
  int min = min2(A,B);"/On appelle la fonction qui renvoie le plus petit des deux/";
  printf("%d\n", min);
  min2_display(A,B);
  int mintot = min4(A,B,C,D);
  printf("%d\n", mintot);
  return 0;
}
