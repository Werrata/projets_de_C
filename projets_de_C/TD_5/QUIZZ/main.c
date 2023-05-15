


#include "fonctions.h"


int main()
{
  ListStructEleve data;
  int n;

  printf("Nombre d'etudiants (max=20)? : ");
  scanf("%d", &n);

  entrerDonnees(data, n);
  afficherDonnees(data, n);
  trierDonneesNote(data, n);
  trierDonneesNoteNom(data, n);
  return 0;
}
