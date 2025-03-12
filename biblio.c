# include "biblio.h"
#include<time.h>

int menu()
{
	int choix;
// au programme du TP7 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP8 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
printf("\n 11- lister les livres disponibles "); 
printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
//printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ");

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}



int main()
{
int reponse,chx;
T_Bibliotheque B; 
char auteur[50];
init( &B );
char titre[MAX_TITRE];
T_Code code;
T_Emp emprunteur;
do
{
chx= menu();
switch(chx)
	{
	case 15: 
	printf("Chargement en cours");
	chargement(&B);
	printf("Chargement réussie");
	break;
	case 14: 
			printf("Sauvegarde en cours");
			sauvegarde(&B);
			printf("Sauvegarde réussie");
			break;
	
	case  1 : reponse = ajouterLivre(   &B  );
				if (reponse==1)
					printf(" ajout reussi !!\n");
					else
					printf("impossible d ajouter (bibliotheque pleine)\n");
			break;
	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide\n");

			break;
	
	case 3 : 
	
		lire(titre,MAX_TITRE);
		reponse = rechercherTitre(&B , titre );
		printf("Ce livre est présent en %d exemplaires\n",reponse);
		break;

	case 4 :
			if (afficherParAuteur(&B, auteur)==0)	
				printf("Aucun livre avec ce nom d'auteur\n");
				else{
					lire(auteur,50);
					printf("nom auteur : %s",auteur);
					afficherParAuteur(&B, auteur);
				}
			break;

	case 5 :
			lire(titre,MAX_TITRE);
			reponse = supprlivre(&B, titre);
			if(reponse==0)
				printf("Bibliotheque vide");
			else{
				printf("Suppression réussie");
			}
			break;

	case 6 :
			printf("Code du livre : ");
			lire(code, MAX_CODE);
			printf("Nom de L'emprunteur :");
			lire(emprunteur.nomemprunteur, K_MaxEmp);
			reponse = empruntLivre(&B, code, emprunteur);
			if (reponse == -1)
				printf("Code inexistant ou déja");
			else
				if(reponse == 0)
					printf("Livre déja emprunté");
				else
					printf("Nom de l'emprunteur : %s", emprunteur.nomemprunteur);
			break;
	
	case 7 :
			printf("Code du livre : ");
			lire(code, MAX_CODE);
			reponse = restituerLivre(&B, code);
			if (reponse == -1)
				printf("Code inexistant");
			else
				if(reponse == 0){
				printf("Livre déja emprunté");
				}
				else{
					printf("livre bien restitué !");
				}
			break;
			
			
	case 8 :
			reponse = trierLivresTitre(&B);
			if(reponse == 0){
				printf("Impossible de trier");
			}else{
				printf("Bibliothèque triée par titre avec succès");
			}
			break;	

	case 9 :
			reponse = trierLivresAuteur(&B);
			if(reponse == 0){
				printf("Impossible de trier");
			}else{
				printf("Bibliothèque triée par auteur avec succès");
			}
			break;

	case 10 :
			reponse = trierLivresAnnee(&B);
			if(reponse == 0){
				printf("Impossible de trier");
			}else{
				printf("Bibliothèque triée par année avec succès");
			}
			break;
	case 11 :
			reponse=AfficherLivresDispo(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide\n");

			break;

	case 12 :
			reponse=ListerEmpruntsRetard(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide\n");

			break;
	
	}

}while(chx!=0);


return 0;

}




