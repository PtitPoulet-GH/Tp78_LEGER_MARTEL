#include "livre.h"
#include <stdlib.h>

void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("COTE :", (ptrL->code ), MAX);
lireChaine("EDITEUR :", (ptrL->editeur), MAX);
printf("ANNEE :");
scanf("%d", &(ptrL->annee));
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("COTE :", (ptrL->code ));
printf(" - ");
afficherChaine("EDITEUR :", (ptrL->editeur));
printf(" - ");
printf("ANNEE: %d", (ptrL->annee) );
printf("\n");
}


