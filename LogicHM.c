
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "LogicHM.h"
#include "GameHM.h"
#include "DisplayHM.h"

int gameEnding(Partie* maPartie)
{
    int next=0;
    if(strcmp(maPartie->MotMystere.word,maPartie->MotDuJoueur.word) == 0)
    {
        win();
        next=1;
    }
    else if(maPartie->compteurErreur>=10) //si on fait plus de 10 erreurs
    {
        loose();
        next=1;                                //on change la condition
    }

    return next;
}


void lireCaractere(Partie* maPartie)
{
	char lettreDuTour = 0;

	printf("\nProposez une Lettre :");

	do			//verification si on a deja essaye la lettre
	{
	lettreDuTour = getchar();               // On lit le premier caractère
	lettreDuTour = toupper(lettreDuTour);   // On met la lettre en majuscule si elle ne l'est pas déjà
	  // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
	while (getchar() != '\n') ;
	}while(strchr(maPartie->lettreDejaTeste,lettreDuTour)!=NULL);	    //il faut ajouter un message d'erreur

	maPartie->lettreDejaTeste[maPartie->compteurDeTour]=lettreDuTour;	//on ajoute au tableau de lettre deja teste la nouvelle lettre

}


void comparaison (Partie* ioPartie)
{
int i=0,j=0;
int count=0;        //va compter le nombre de lettre deja teste et qui ne sont pas dans le mot mystere

	for (j=0;j<ioPartie->MotMystere.size;j++)		//pour chaque lettre du mot Mystere
	{
		for (i=0;i<strlen(ioPartie->lettreDejaTeste);i++)		//pour toutes les lettres que le joueur a teste
		{
		if (ioPartie->MotMystere.word[j] == ioPartie->lettreDejaTeste[i]) //si la lettre apparait dans le mot Mystere
			{
			//printf("la lettre est dans le mot !");
			ioPartie->MotDuJoueur.word[j]=ioPartie->MotMystere.word[j];		//on remplace * par la bonne lettre
			}
		else
            {
		    count++;
            }
		}
	}
printf ("dans comparaison compteur erreur=%d",count);
ioPartie->compteurErreur=count;     //je le recalcule a chaque tour...
}
