


#include "fonctions.h"


void entrerDonnees(ListStructEleve list, int s)
{
  
  for(int i = 0; i < s; i++)
  {
    printf("donner dans l'ordre : id, nom, et note de l'élève %d\n", i);
    scanf("%d",&list[i].id);
    scanf("%c",&list[i].nom);
    scanf("%d",&list[i].note);
  }
}


void afficherDonnees(ListStructEleve list, int s)
{ 
  int i;
  int j;
  
  for(i = 0; i < s; i++)
  {
    printf("Informations sur l'élève %c\n", list[i].nom);
    printf("id : %c\n", list[i].id);
    printf("note : %c\n", list[i].note);
  }
}


int ChercheMin(ListStructEleve tab, int indice_debut, int indice_fin)
{
  int i;
  int indice_min = indice_debut;

  for(i = indice_debut + 1; i < indice_fin + 1; i++)
  {
    if(tab[i].note < tab[indice_min].note)
    {
      indice_min = i;
    }
  }
  return indice_min;
}


void trierDonneesNote(ListStructEleve list, int s)
{ 
  int indice = 0;
  int posmin = 0;
  
  int t_id;
  char t_nom;
  int t_note; 
  
  
  for(indice = 0; indice < s-1; indice++)
  {
    
    posmin = ChercheMin(list, indice, s-1);
    
    if(posmin != indice)
    {
      t_id = list[indice].id;
      t_nom = list[indice].nom;
      t_note = list[indice].note;
      
      list[indice].id = list[posmin].id;
      list[indice].nom = list[posmin].nom;
      list[indice].note = list[posmin].note;
      
      list[posmin].id = t_id;
      list[posmin].nom = t_nom;
      list[posmin].note = t_note;
    }
  }
}


int CompareNom(*PremierNom, *DeuxiemeNom) //verifie que PremierNom < DeuxiemeNom (au sens alphabetique)
{
  while(*PremierNom == *DeuxiemeNom)
  {
    PremierNom++;
    DeuxiemeNom++;
  }
  
  (PremierNom < DeuxsiemeNom)?(return 1):(return 0);
}
  


int ChercheMinNoteNom(ListStructEleve tab, int indice_debut, int indice_fin)
{
  int i;
  int indice_min = indice_debut;

  for(i = indice_debut + 1; i < indice_fin + 1; i++)
  {
    if(tab[i].note < tab[indice_min].note)
    {
      indice_min = i;
    }
    
    else if((tab[i].note = tab[indice_min].note) && CompareNom(*tab[i].nom, *tab[indice_min].nom))
    {
      indice_min = i;
    }
  }
  return indice_min;
}
  


void trierDonneesNoteNom(ListStructEleve list, int s)
{ 
  int indice = 0;
  int posmin = 0;
  
  int t_id;
  char t_nom;
  int t_note; 
  
  
  for(indice = 0; indice < s-1; indice++)
  {
    
    posmin = ChercheMinNoteNom(list, indice, s-1);
    
    if(posmin != indice)
    {
      t_id = list[indice].id;
      t_nom = list[indice].nom;
      t_note = list[indice].note;
      
      list[indice].id = list[posmin].id;
      list[indice].nom = list[posmin].nom;
      list[indice].note = list[posmin].note;
      
      list[posmin].id = t_id;
      list[posmin].nom = t_nom;
      list[posmin].note = t_note;
    }
  }
}















