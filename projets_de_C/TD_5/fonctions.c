
#include "fonctions.h"


ptNINJA createNINJA(char nom[NBLETTRES + 1], int chakra, ptNINJA previous, ptNINJA next)
{
  NINJA * nin = malloc(sizeof(NINJA));
  int i = 0;
  do 
  {
    nin->nom[i] = nom[i];
    i++;
  }
  while(nom[i] =! '\0');
    
  nin->chakra = chakra;
  nin->previous = previous;
  nin->next = next;
  
  return nin;
}


CLAN* createClan(char nom[NBLETTRES+1],NINJA* hokage)
{
  CLAN* clan;
  clan=(CLAN*)malloc(sizeof(CLAN));
  strcpy(clan->nom, nom);
  if(hokage!=NULL)
  {
    clan->nombre=1;		
    clan->hokage = hokage;
    clan->genin = hokage;
  }
  else
  {
    clan->nombre=0;		
    clan->hokage = NULL;
    clan->genin = NULL;		
  }
  return clan;
}



int isClanEmpty(CLAN* clan) //verifie si le clan est vide
{
  if(clan->hokage==NULL) return 1;
  else return 0;
}


NINJA* searchNinjaByName(CLAN* clan, char nom[NBLETTRES+1])//trouve le ninja concerné
{
  NINJA *found=NULL;
  if(clan!=NULL)
  {
    NINJA *cur=clan->hokage;
    while(cur!=NULL)
    {
      if(strcmp(cur->nom,nom)==0)
      {
        found=cur;
        break;
      }
      cur=cur->next;
    }
  }
  return found;
}



void fonction01(CLAN* clan)//efface un clan
{
  NINJA *cur=clan->genin;
  NINJA *previous;
  while(cur!=NULL)
  {
    previous=cur->previous;
    free(cur);
    clan->nombre--;
    cur=previous;
  }
  free(clan);
}


void fonction02(CLAN* clan, NINJA* hokage)//Change d'hokage
{
  if(clan!=NULL)
  {
    if(!isClanEmpty(clan))
    {
      hokage->next=clan->hokage;
      clan->hokage->previous=hokage;
      clan->hokage=hokage;
    }
    else
    {
      clan->hokage=hokage;
      clan->genin=hokage;
    }
    clan->nombre++;
  }
}


void fonction03(CLAN* clan, NINJA* genin)
{
  if(clan!=NULL)
  {
    if(!isClanEmpty(clan))
    {
      genin->previous=clan->genin;
      clan->genin->next=genin;
      clan->genin=genin;
    }
    else
    {
      clan->hokage=genin;
      clan->genin=genin;
    }
    clan->nombre++;
  }
}



int fonction04(CLAN* clan, NINJA* nin, char nom[NBLETTRES+1])
{
  NINJA* found=NULL;
  NINJA* previous=NULL;
  found=searchNinjaByName(clan,nom);
  if(found!=NULL)
  {
    if(found!=clan->hokage)
    {
      previous=found->previous;
      found->previous=nin;
      nin->next=found;
      previous->next=nin;
      nin->previous=previous;
      clan->nombre++;
    }
    else
    {
      function02(clan,nin);
    }
    return 0;
  }
  else
  {
    printf("insertion impossible car aucun Ninja de ce nom.\n");
    return -1;
  }
}
























