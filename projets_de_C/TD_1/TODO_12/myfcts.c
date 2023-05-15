
#include "myfcts.h"

int min2(int A, int B)
{
  if (A<B) return A;
  else return B;
}


void min2_display(int A, int B)
{
  if (A<B) printf("%d\n", A);
  else printf("%d\n", B);
}



int min4(int U, int Y, int X, int Z)
{
  int Res1 = min2(U,Y);
  int Res2 = min2(X,Z);
  int ResF = min2(Res1,Res2);
  return ResF;
}
