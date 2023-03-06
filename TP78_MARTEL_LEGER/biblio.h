#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 100 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherLivre(const T_Bibliotheque  *ptrB);
int recherchelivre_auteur(const T_Bibliotheque *ptrB);
int supprimerLivre(T_Bibliotheque  *ptrB);
int emprunterLivre(T_Bibliotheque  *ptrB, T_Code code);
int restituerLivre(T_Bibliotheque *ptrB, T_Code code);
void lireDateSysteme(T_Emp *E);
int trie_titre(T_Bibliotheque *ptrB);
int trie_auteur(T_Bibliotheque *ptrB);
int trie_annee(T_Bibliotheque *ptrB);
int livreDispo(T_Bibliotheque *ptrB);
int retard(T_Bibliotheque *ptrB);

#endif
