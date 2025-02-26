#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
ptrL->emprunteur[0]='\0';
}


void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("CODE :", (ptrL->code));
printf(" - ");
afficherChaine("EMPRUNTEUR",(ptrL->emprunteur));
printf("\n");

}

