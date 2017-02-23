

#include <stdio.h>

#include "DisplayHM.h"


int toContinu (int continuerPartie)
{
	//boucle qui demande si on veut jouer encore
		do
		{
		printf("voulez vous rejouer au Pendu ?\n");
			printf("1-oui     2-non\n");
			scanf("%d",&continuerPartie);

		}while (continuerPartie <1 || continuerPartie > 2);	//repose la question tant qu'on a pas repondu 1 ou 2
	return continuerPartie;
}
