

#include "header.h"



void facteurs_premiers(int x)
{
  int n = 2;
  while(x != 1)
  {
    if (x%n == 0)
    {
      x = x/n;
      printf("%d\n",n);
    }
    else 
    {
      n = n + 1;
    }
  }
}


 
int est_premier(int x) /*renvoie 0 si x est premier*/
{
  int n = 2;
  
  while(n < x)
  {
    if (x%n == 0)
    {
      return 1;
    }
    else 
    {
      n = n + 1;
    }
  }
  return 0;
}




void les_premiers(void)
{
  TABint liste_prem;
  int compteur = 2;
  int n = 0;
  int i;
  int q;
  
  for(i=0 ; i < DIM ; i++)
  {
    liste_prem[i] = 0;
  }
  
  while (n < DIM)
  {
    if (est_premier(compteur) == 0)
      {
        liste_prem[n] = compteur;
        n++;
        compteur++;
      }
    else compteur++;
  }
  
  for(q=0 ; q < DIM ; q++)
  {
    printf("%d\n",liste_prem[q]);
  }
}


void Somme_prem(void)
{
  TABint liste_prem;
  int compteur = 2;
  int n = 0;
  int i;
  int somme = 0;
  
  for(i=0 ; i < DIM ; i++)
  {
    liste_prem[i] = 0;
  }
  
  while (n < DIM)
  {
    if (est_premier(compteur) == 0)
      {
        liste_prem[n] = compteur;
        n++;
        compteur++;
      }
    else compteur++;
  }
  
  for(i=0 ; i<DIM ; i++)
  {
    somme = somme + liste_prem[i];
  }
  printf("%d\n", somme);
}
  




