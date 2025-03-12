#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX_TITRE);
lireChaine("EDITEUR :",(ptrL->editeur),MAX_TITRE);
ptrL->emprunteur.nomemprunteur[0]='\0';
}


void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("CODE :", (ptrL->code));
printf(" - ");
afficherChaine("EMPRUNTEUR :",(ptrL->emprunteur.nomemprunteur));
printf( " - ");
afficherChaine("EDITEUR :",(ptrL->editeur));
printf( " - ");
printf("ANNEE : %d",(ptrL->annee));
printf("\n");


}

