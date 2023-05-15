
#include <stdio.h>
#include <string.h>


#define MAX_NOM_LENGHT 50
#define MAX_LIST_SIZE 20


typedef struct eleve
{
  int id;
  char nom[MAX_NOM_LENGHT];
  int note;

}StructEleve;

typedef StructEleve ListStructEleve[MAX_LIST_SIZE];


void entrerDonnees(ListStructEleve list, int s);
void afficherDonnees(ListStructEleve list, int s);
void trierDonneesNote(ListStructEleve list, int s);

int ChercheMin(ListStructEleve tab, int indice_debut, int indice_fin);
int CompareNom(*PremierNom, *DeuxiemeNom);
int ChercheMinNoteNom(ListStructEleve tab, int indice_debut, int indice_fin);

void trierDonneesNoteNom(ListStructEleve list, int s);
