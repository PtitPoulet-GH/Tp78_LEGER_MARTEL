#include <string.h>

# include "biblio.h"


void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

/**********************/
/* Fonction: Ajouter  */
/**********************/

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
return 0;
}

/**********************/
/* Fonction: Afficher */
/**********************/

int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i])  );
			
			}
		return 1;
		}
}

/********************************/
/* Fonction: Rechercher (Titre) */
/********************************/

int rechercherLivre(const T_Bibliotheque  *ptrB)
{ 
  int i=0;
  int ex=0; //nombre d'exemplaire du livre
  char titreRech[MAX_TITRE]; //titre du livre a rechercher
	
  printf("Ecrire le titre du livre a rechercher: ");
  lireChaine("\nTITRE :", titreRech, MAX_TITRE ); 	
  
  for(i=0; i<=ptrB->nbLivres; i++)
  {
	if(strcmp(titreRech, ptrB->etagere[i].titre)==0)
		ex++;
  }
  
  if(ex==0)
  {
	printf("Livre introuvable !");
	return 0;
  }
  
  else 
  {
	printf("Livre trouve !");
	printf("\nNombre d'exemplaire: %d", ex);
	return 1;
  }
}

/****************************************************************/
/* Fonction: rechercher et afficher tous les livres d'un auteur */
/****************************************************************/

int recherchelivre_auteur(const T_Bibliotheque *ptrB)
{
    int i=0;
    int ex=0;
    
    char auteurRech[MAX_TITRE];
    printf("Ecrire l'auteur recherche");
    lireChaine("\n AUTEUR : ",auteurRech, MAX_TITRE);
    
    for(i=0;i<=ptrB->nbLivres; i++){
        if(strcmp(auteurRech, ptrB->etagere[i].auteur)==0)
            {
                printf("-%s\n",ptrB->etagere[i].titre);
                ex++;
            }
    }
    if(ex==0)
        return 0;
    else
        return 1;
}

/***********************/
/* Fonction: Supprimer */
/***********************/
int supprimerLivre(T_Bibliotheque  *ptrB)
{
  int i=0;
  int a=0;	
  char titreSupp[MAX_TITRE]; //titre du livre a supprimer

  printf("Ecrire le titre du live a supprimer: ");
  lireChaine("\nTITRE :", titreSupp, MAX_TITRE );
  
  for(i=0; i<=ptrB->nbLivres; i++)
  {
	if(strcmp(titreSupp, ptrB->etagere[i].titre)==0)
        
	{
        for(a=i;(a+1)!=ptrB->nbLivres;a++)
            ptrB->etagere[a]=ptrB->etagere[a+1];
		ptrB->nbLivres--;
		printf("Suppression reussie !");
        return 1;
	}  	
  }

   return 0;
}


/***********************/
/* Fonction: Emprunter */
/***********************/

int emprunterLivre(T_Bibliotheque* ptrB, T_Code code) 
{
    char jour[13],mois[13];
    int i;
    if (ptrB->nbLivres <= 0) 
        return 0;
    

    printf("Entrez le code du livre à emprunter : ");
    lireChaine("\nCOTE :", code, MAX);

    for (i = 0; i < ptrB->nbLivres; i++) {
        if (strcmp(ptrB->etagere[i].code, code) == 0 && ptrB->etagere[i].emprunteur.lannee == 0) 
	{
            lireChaine("Entrez le nom de l'emprunteur : ", ptrB->etagere[i].emprunteur.nomemprunteur, 50);
            lireDateSysteme(&ptrB->etagere[i].emprunteur);
	    printf("\n  emprunt realise le : ");
	
	switch(ptrB->etagere[i].emprunteur.lejour)
	{
	  case 0 :  strcpy(jour,"lundi");break;
	  case 1 :  strcpy(jour,"mardi");break;
	  case 2 :  strcpy(jour,"mercredi");break;
	  case 3 :  strcpy(jour,"jeudi");break;
	  case 4 :  strcpy(jour,"vendredi");break;
	  case 5 :  strcpy(jour,"samedi");break;
	  case 6 :  strcpy(jour,"dimanche");break;

	  default : strcpy(jour,"jour inconnu");break;
	}
	printf("%s ",jour);

	printf("%d ",ptrB->etagere[i].emprunteur.ladate);


	switch(ptrB->etagere[i].emprunteur.lemois)
	{
	  case 0 :  strcpy(mois,"janvier");break;
	  case 1 :  strcpy(mois,"fevrier");break;
	  case 2 :  strcpy(mois,"mars");break;
	  case 3 :  strcpy(mois,"avril");break;
	  case 4 :  strcpy(mois,"mai");break;
	  case 5 :  strcpy(mois,"juin");break;
	  case 6 :  strcpy(mois,"juillet");break;
	  case 7 :  strcpy(mois,"aout");break;
	  case 8 :  strcpy(mois,"septembre");break;
	  case 	9 :  strcpy(mois,"octobre");break;
	  case 10 :  strcpy(mois,"novembre");break;
	  case 11 :  strcpy(mois,"decembre");break;

	  default : strcpy(jour,"mois inconnu");break;
	}
	printf("%s ",mois);

	printf("%d ",ptrB->etagere[i].emprunteur.lannee);
            return 1; 
        }
    }
    return 0;
}


/***********************/
/* Fonction: Restituer */
/***********************/
int restituerLivre(T_Bibliotheque* ptrB, T_Code code) 
{
    int i;
    int trouve = 0;
    if (ptrB->nbLivres <= 0) 
        return 0;
    
    printf("Entrez le code du livre à restituer : ");
    lireChaine("\nCOTE :", code, MAX);

    for (i = 0; i < ptrB->nbLivres; i++) 
    {
        if (strcmp(ptrB->etagere[i].code, code) == 0 && ptrB->etagere[i].emprunteur.lannee != 0) 
	{
            ptrB->etagere[i].emprunteur.lannee = 0;
            ptrB->etagere[i].emprunteur.ladate = 0;
            ptrB->etagere[i].emprunteur.lejour = lu;
            ptrB->etagere[i].emprunteur.lemois = janv;
            strcpy(ptrB->etagere[i].emprunteur.nomemprunteur, "default");
            trouve = 1;
            break;
        }
    }

    if (trouve == 0) 
        return 0;
    else  
        return 1;
}

/****************************/
/* Fonction: lireDateSystem */
/****************************/

void lireDateSysteme(T_Emp *E)
{
char j[9],m[10],h[9],mer[11],vir[2];
int d,a;


system("date > ladate"	);
FILE * fic=NULL;  // pointeur de fichier
fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

//ici , si fic vaut NULL, alors le fopen a indiquÃ©
//que le fichier ladate n'est pas accessible
if (fic!=NULL)
	{
	while(!feof(fic))	
		{
		fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);		
		if (!feof(fic)) 
			printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);		

		}
	fclose(fic);
	
if (strcmp(j,"lundi")==0) E->lejour=lu;
if (strcmp(j,"mardi")==0) E->lejour=ma;
if (strcmp(j,"mercredi")==0) E->lejour=me;
if (strcmp(j,"jeudi")==0) E->lejour=je;
if (strcmp(j,"vendredi")==0) E->lejour=ve;
if (strcmp(j,"samedi")==0) E->lejour=sa;
if (strcmp(j,"dimanche")==0) E->lejour=di;

E->ladate=d;

if (strcmp(m,"janvier")==0) E->lemois=janv;
if (strcmp(m,"fevrier")==0) E->lemois=fevr;
if (strcmp(m,"mars")==0) E->lemois=mars;
if (strcmp(m,"avril")==0) E->lemois=avri;
if (strcmp(m,"mai")==0) E->lemois=mai;
if (strcmp(m,"juin")==0) E->lemois=juin;
if (strcmp(m,"juillet")==0) E->lemois=juil;
if (strcmp(m,"aout")==0) E->lemois=aout;
if (strcmp(m,"septembre")==0) E->lemois=sept;
if (strcmp(m,"octobre")==0) E->lemois=octo;
if (strcmp(m,"novembre")==0) E->lemois=nove;
if (strcmp(m,"decembre")==0) E->lemois=dece;


E->lannee=a;
	}
	else
	{
		printf("n souci avec la date systeme !!");
		
		//on range une date irrÃ©elle 
		E->lejour=di;
		E->ladate=99;
		E->lemois=dece;
		E->lannee=-999;


	}

}

/************************************/
/* Fonction: trie_titre (par titre) */
/************************************/
int trie_titre(T_Bibliotheque *ptrB)
{
    int ech = 1;
    int i;
    T_livre aux;
    while (ech != 0)
    {
        ech = 0;
        for (i = 0; i < (ptrB->nbLivres) - 1; i++)
        {
            if (strcmp(ptrB->etagere[i].titre, ptrB->etagere[i + 1].titre) > 0)
            {
                aux = ptrB->etagere[i + 1];
                ptrB->etagere[i + 1] = ptrB->etagere[i];
                ptrB->etagere[i] = aux;
                ech++;
            }
        }
    }
    return 0;
}

/**************************************/
/* Fonction: trie_auteur (par auteur) */
/**************************************/
int trie_auteur(T_Bibliotheque *ptrB)
{
    int ech = 1;
    int i;
    T_livre aux;
    while (ech != 0)
    {
        ech = 0;
        for (i = 0; i < (ptrB->nbLivres) - 1; i++)
        {
            if (strcmp(ptrB->etagere[i].auteur, ptrB->etagere[i + 1].auteur) > 0)
            {
                aux = ptrB->etagere[i + 1];
                ptrB->etagere[i + 1] = ptrB->etagere[i];
                ptrB->etagere[i] = aux;
                ech++;
            }
        }
    }
    return 0;
}

/**************************************/
/* Fonction: trie_annee (par annee)   */
/**************************************/
int trie_annee(T_Bibliotheque *ptrB)
{
    int ech = 1;
    int i;
    T_livre aux;
    while (ech != 0)
    {
        ech = 0;
        for (i = 0; i < (ptrB->nbLivres) - 1; i++)
        {
            if (ptrB->etagere[i].annee > ptrB->etagere[i + 1].annee)
            {
                aux = ptrB->etagere[i + 1];
                ptrB->etagere[i + 1] = ptrB->etagere[i];
                ptrB->etagere[i] = aux;
                ech++;
            }
        }
    }
    return 0;
}

/************************/
/* Fonction: livreDispo */
/************************/

int livreDispo(T_Bibliotheque *ptrB)
{
    //int ex;
    int i;
    for(i=0;i<=ptrB->nbLivres; i++)
    {
        if(ptrB->etagere[i].emprunteur.lannee==0)
            {
                printf("-%s\n",ptrB->etagere[i].titre);
                //ex++;
            }
    }
    return 0;
}

/************************/
/* Fonction: retard     */
/************************/

int retard(T_Bibliotheque *ptrB)
{
  int i;
  for(i=0;i<=ptrB->nbLivres; i++)
  {
      if(ptrB->etagere[i].emprunteur.lannee!=0)
	  {
	      lireDateSysteme(&(ptrB->etagere[i].emprunteur));
	  }
  }
  return 0;
}
