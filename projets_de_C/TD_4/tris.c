

#include "tris.h"



void randomInitTABint(TABint tab) 
{
  int i;
  for (i = 0; i < TAILLE; i++) 
  {
    tab[i] = ((rand() % 100));
  }
}



int posMinTABint(TABint tab, int indice_debut, int indice_fin)
{
  int i;
  int indice_min = indice_debut;

  for(i = indice_debut + 1; i < indice_fin + 1; i++)
  {
    if(tab[i] < tab[indice_min])
    {
      indice_min = i;
    }
  }
  return indice_min;
}



void selectionSortTABint(TABint tab, int N)
{ 
  int indice = 0;
  int posmin = 0;
  int temp = 0;
  
  for(indice = 0; indice < N-1; indice++)
  {
    
    posmin = posMinTABint(tab, indice, N-1);
    
    if(posmin != indice)
    {
      temp = tab[indice];
      tab[indice] = tab[posmin];
      tab[posmin] = temp;
    }
  }
}






void sortAndMerge(TABint T1, TABint T2, int idebg1, int iendg1, int idebg2, int iendg2)
{
  int cptT2 = idebg1;
  int ig1 = idebg1;
  int ig2 = idebg2;
  for(cptT2 = idebg1, cptT2 <= iendg2, cptT2++)
  {
    if((ig1 <= iendg1) && ((ig2 > iendg2) || (T1[ig1]<=T1[ig2])))
    {
      T2[cptT2] = T1[ig1];
      ig1++;
    }
    else
    {
      T2[cptT2] = T1[ig2];
      ig2++;
    }
  }
}






void mergeSortTABint(TABint T1)
{
  TABint T2;
  int q = 0;
  int i;
  
  while((2**(q+1)) < TAILLE)
  {
    for(i = 0, i < TAILLE/(2^q), i++)
    {
      sortAndMerge(T1, T2, i, i+q, i+q+1, i+2*q+1);
    }
    
    q++;
  }
  sortAndMerge(T1, T2, 0, q, q+1, TAILLE);
}












