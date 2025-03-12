#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H

#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef T_livre T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;


//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int afficherBibliotheque(const T_Bibliotheque  *ptrB);
void chargement(T_Bibliotheque *ptrB); //ajouter le 13/02/2025 prototypes des 2 fonctions 
void sauvegarde(T_Bibliotheque *ptrB);
int afficherParAuteur(const T_Bibliotheque *ptrB, char auteur[]);
int supprlivre(T_Bibliotheque *ptrB, char titre[]);
int rechercherTitre(T_Bibliotheque *B ,char titre[]);
int rechercherCode(T_Bibliotheque *ptrB, T_Code code);
int empruntLivre(T_Bibliotheque *ptrB, T_Code code, T_Emp emprunteur);
int restituerLivre(T_Bibliotheque *ptrB, T_Code code);
int verifCode(T_Bibliotheque *ptrB, const T_Code code);
int trierLivresAnnee(T_Bibliotheque *ptrB);
int trierLivresAuteur(T_Bibliotheque *ptrB);
int trierLivresTitre(T_Bibliotheque *ptrB);
int AfficherLivresDispo(T_Bibliotheque *ptrB);
void setTimeEmp(T_Emp * ptrE);

#endif