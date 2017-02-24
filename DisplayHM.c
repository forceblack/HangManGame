
#include <stdio.h>

#include "DisplayHM.h"



///////////////////////////DEBUT FIN DE PARTIE///////////////////////////////////////////////////////////////////////////////////////////

int toContinu (int continuerPartie)
{
	//boucle qui demande si on veut jouer encore
		do
		{
		do
		{
		printf("voulez vous rejouer au Pendu ?\n");
			printf("1-oui     2-non\n");
			scanf("%d",&continuerPartie);
		}while(getchar() != '\n') ;          //protection pour qu'en cas de replay, le premier caractere ne soit pas foire
		}while (continuerPartie <1 || continuerPartie > 2);	//repose la question tant qu'on a pas repondu 1 ou 2
	return continuerPartie;
}

void win()
{
    printf("\nBRAVO\n");
}

void loose()
{
    printf("\nVous avez perdu\n");
}

/////////////////////////////////AU COURS DU JEU////////////////////////////////////////////////////////////////////////////////////////////////


void afficheLettreDejaTeste (char lettreDejaTeste[])
{

	printf("\nvous avez deja essaye :%s",lettreDejaTeste);

}

void affichageMotMystere (char motDuJoueur[])
{
	printf("\nmot Mystere %s\n",motDuJoueur);
}



///////////////////////////////////////// PENDU ////////////////////////////////////////////////////////////////////////////////////////////////////

void affichePendu(int compteurErreur)
{
	switch (compteurErreur)
	{
	case 0:
	printf( "	      \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n");
	break;

	case 1:
	printf( "	      \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n"
		"__________   \n");
	break;

	case 2:
	printf( "	      \n"
		"             \n"
		" |           \n"
		" |           \n"
		" |           \n"
		" |           \n"
		"_|_________  \n");
	break;

	case 3:
	printf( "	      \n"
		"____________ \n"
		" |           \n"
		" |           \n"
		" |           \n"
		" |           \n"
		"_|_________  \n");
	break;

	case 4:
	printf( "	      \n"
		"____________ \n"
		" | /         \n"
		" |/          \n"
		" |           \n"
		" |           \n"
		"_|_________  \n");
	break;

	case 5:
	printf( "	      \n"
		"____________ \n"
		" | /     |   \n"
		" |/          \n"
		" |           \n"
		" |           \n"
		"_|_________  \n");
	break;

	case 6:
	printf( "	      \n"
		"____________ \n"
		" | /     |   \n"
		" |/      O   \n"
		" |           \n"
		" |           \n"
		"_|_________  \n");
	break;

	case 7:
	printf( "	      \n"
		"____________ \n"
		" | /     |   \n"
		" |/      O   \n"
		" |       |   \n"
		" |           \n"
		"_|_________  \n");
	break;

	case 8:
	printf( "	      \n"
		"____________ \n"
		" | /     |   \n"
		" |/    _ O   \n"
		" |       |   \n"
		" |           \n"
		"_|_________  \n");
	break;

	case 9:
	printf(	"	      \n"
		"____________ \n"
		" | /     |   \n"
		" |/    _ O _ \n"
		" |       |   \n"
		" |           \n"
		"_|_________  \n"
		"             \n");

	break;

		case 10:
	printf(	"	      \n"
		"____________ \n"
		" | /     |   \n"
		" |/    _ O _ \n"
		" |       |   \n"
		" |      / \\ \n"
		"_|_________  \n"
		"             \n");

	break;

	default:
	printf(" ");
	break;
	}

}

