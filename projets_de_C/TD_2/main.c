

#include "header.h"

int main(void)
{
  facteurs_premiers(1024);
  int a = est_premier(17);
  int b = est_premier(29);
  int c = est_premier(39);
  int d = est_premier(13*13);
  printf("%d\n", a);
  printf("%d\n", b);
  printf("%d\n", c);
  printf("%d\n", d);
  les_premiers();
  Somme_prem();
}
