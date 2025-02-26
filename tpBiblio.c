#include "biblio.h"


// Fonctions rechercher titre 
int rechercherTitre(T_Bibliotheque * B,char title[]){
    int cbnLivre = 0;
    for(int i = 0 ; i < B->nbLivres ; i++){
        if (strcmp(B->etagere[i].titre,title) == 0) cbnLivre = cbnLivre + 1 ;
    }
    return cbnLivre;
}




void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");



	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}



void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}



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


int afficherParAuteur(const T_Bibliotheque *ptrB, char auteur[])
{
	int i=0;
	if (ptrB->nbLivres==0)
		return 0;
		else{
			for (i = 0; i < ptrB->nbLivres; i++)
			{
				if (strcmp(ptrB->etagere[i].auteur ,auteur)== 0)
				{
					afficherLivre(&(ptrB->etagere[i]));
				}
			}
			return 1;
		}
}

int supprlivre(T_Bibliotheque *ptrB, char titre[])
{
	if (rechercherTitre(ptrB ,titre)==0)
		return 0;
		else{
			int i;

			for (i = 0; i < ptrB->nbLivres; i++)
			{
				if (ptrB->etagere[i].titre==titre)
				{
					ptrB->etagere[i]=ptrB->etagere[ptrB->nbLivres];
					ptrB->nbLivres--;
				}
			}
			return 1;
			
		}

}
