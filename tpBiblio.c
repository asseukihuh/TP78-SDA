#include "biblio.h"
#include <time.h>

struct tm * timeEmp;
time_t date ;

//copiçt

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
    T_Code code;
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
    //lire(code,K_MaxCode);
    if (verifCode(ptrB,code)== 1) lireChaine("CODE :",ptrB->etagere[ptrB->nbLivres].code ,K_MaxCode);
}	
	lireAnnee("ANNEE : ",&(ptrB->etagere[ptrB->nbLivres].annee),5);
	ptrB->nbLivres++;
	return 1;
	
	
	
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
			for(i=0;i<ptrB->nbLivres;i++)
			{
				if (strcmp(ptrB->etagere[i].auteur, auteur)==0)
				{
					afficherLivre(&(ptrB->etagere[i]));
				}
			}
			return 1;
		}
}

int supprlivre(T_Bibliotheque *ptrB, char titre[])
{
	if(rechercherTitre(ptrB ,titre)==0)
		return 0;
	else{
		
		if(strcmp(ptrB->etagere[0].titre,titre)==0 && ptrB->nbLivres==1)
		{
			init(ptrB);
			return 1;
		}else
        {
			int i;

			for (i = 0; i < ptrB->nbLivres; i++)
			{
				if (strcmp(ptrB->etagere[i].titre,titre)==0)
				{
					strcpy(ptrB->etagere[i].titre, ptrB->etagere[ptrB->nbLivres-1].titre);
					strcpy(ptrB->etagere[i].auteur, ptrB->etagere[ptrB->nbLivres-1].auteur);
					ptrB->nbLivres--;
				}
			}
			return 1;
			
		}
	}

}


int rechercherCode(T_Bibliotheque *ptrB, T_Code code){
    int i = 0;
    while (strcmp(ptrB->etagere[i].code,code)!=0 && i < ptrB->nbLivres){
        i++;
    }
    if ( i == ptrB->nbLivres) return -1;
    else return i;
}


int empruntLivre(T_Bibliotheque *ptrB, T_Code code, T_Emp emprunteur){
    int posLivre = rechercherCode(ptrB , code);

    if (posLivre == -1) return -1;
    if (strcmp(ptrB->etagere[posLivre].emprunteur.nomemprunteur,"")!= 0) return 0;
    else{
        strcpy(ptrB->etagere[posLivre].emprunteur.nomemprunteur,emprunteur.nomemprunteur);
		setTimeEmp(&(ptrB->etagere[posLivre].emprunteur));
        return 1;
    }
}

int restituerLivre(T_Bibliotheque *ptrB, T_Code code){
	int i = 0;
	if (rechercherCode(ptrB, code)==-1)
	{
		return -1;
	}
	else{
		for (i = 0; i < ptrB->nbLivres; i++)
			{
				if(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, "\0")==0){
					return 0;
				}else{
					strcpy(ptrB->etagere[i].emprunteur.nomemprunteur, "\0");
					printf("Livre restitué par : %s",ptrB->etagere[i].emprunteur.nomemprunteur);
					return 1;
				}
			}
	}
	return 1;
}


int verifCode(T_Bibliotheque *ptrB, const T_Code code){
    int i =0;
    while( code != ptrB->etagere[i].code && i < ptrB->nbLivres) i++;
    if ( i == ptrB->nbLivres) return 1;
    else return -1;


}


int trierLivresTitre(T_Bibliotheque *ptrB) {
    if (ptrB->nbLivres == 0) return 0;

    int i, j, minIndex;
    T_livre temp;

    for (i = 0; i < ptrB->nbLivres - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < ptrB->nbLivres; j++) {
            if (strcmp(ptrB->etagere[j].titre, ptrB->etagere[minIndex].titre) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = ptrB->etagere[i];
            ptrB->etagere[i] = ptrB->etagere[minIndex];
            ptrB->etagere[minIndex] = temp;
        }
    }

    return 1;
}

int trierLivresAuteur(T_Bibliotheque *ptrB){
    if (ptrB->nbLivres == 0) return 0;

    int i, j, minIndex;
    T_livre temp;

    for (i = 0; i < ptrB->nbLivres - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < ptrB->nbLivres; j++) {
            if (strcmp(ptrB->etagere[j].auteur, ptrB->etagere[minIndex].auteur) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = ptrB->etagere[i];
            ptrB->etagere[i] = ptrB->etagere[minIndex];
            ptrB->etagere[minIndex] = temp;
        }
    }

    return 1;
}

int trierLivresAnnee(T_Bibliotheque *ptrB){
    if (ptrB->nbLivres == 0) return 0;

    int i, j, minIndex;
    T_livre temp;

    for (i = 0; i < ptrB->nbLivres - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < ptrB->nbLivres; j++) {
            if (strcmp(ptrB->etagere[j].auteur, ptrB->etagere[minIndex].auteur) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = ptrB->etagere[i];
            ptrB->etagere[i] = ptrB->etagere[minIndex];
            ptrB->etagere[minIndex] = temp;
        }
    }

    return 1;
}


void setTimeEmp(T_Emp * ptrE){
	time_t timestamp; 
    struct tm * t; 
  
    timestamp = time(NULL); 
    t = localtime(&timestamp); 

	printf("\n EMPRUNT \n");
	ptrE->lejour=t->tm_wday;
	printf("JOUR D'EMPRUNT : %d\n",ptrE->lejour);
	ptrE->ledate=t->tm_mday;
	printf("DATE D'EMPRUNT : %d\n",ptrE->ledate);
	ptrE->lemois=t->tm_mon;
	printf("MOIS D'EMPRUNT : %d\n",ptrE->lemois);
	ptrE->lannee=1900 + t->tm_year;
	printf("ANNNE D'EMPRUNT : %d\n",ptrE->lannee);
	
}

int AfficherLivresDispo(T_Bibliotheque *ptrB)
{
	int i;
	if(ptrB->nbLivres==0)
		return 0;
	else
	{
		for(i=0;i<ptrB->nbLivres;i++)
		{
			//printf("%d",strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,""));
			if(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"")== 0){
				afficherLivre( &(ptrB->etagere[i]));
			}
		}
		return 1;

}

int ListerEmpruntsRetard(T_Bibliotheque *ptrB)
{
	int i;
	int retard = 0;
	if(ptrB->nbLivres==0)
		return 0;
	else
	{
		for(i=0;i<ptrB->nbLivres;i++)
		{
			
			if(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"")== 0){
				afficherLivre( &(ptrB->etagere[i]));
			}
		}
		return 1;
	}
	return 1;
}