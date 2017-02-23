
#include <stdlib.h>
#include <time.h>

#include "GameHM.h"
#include "Dico.h"
#include "DisplayHM.h"

void HangMan()
{
        srand(time(NULL));	    //lancement du compte a rebours necessaire a la fonction rand
        Dico monDico;           //on creer un dictionnaire (une liste de mot contenu dans un fichier)
        initDico(&monDico);     //On l'initialise, on rempli ce dictionnaire de tout les mots du fichier .txt

        int continuerPartie=1;
        while (continuerPartie==1)	//On joue tant que continuer Partie vaut 1
        {
        Partie maPartieHM;
        initPartie(&maPartieHM,&monDico);

        continuerPartie=toContinu(continuerPartie);
        }

}

void initPartie(Partie* maPartieHM,Dico* monDico)
{
    int i=0;
    for (i=0 ; i<TAILLE_ALPHABET ; i++)
    {maPartieHM->lettreDejaTeste[i]=0;}	//pour l'instant que des 0

    maPartieHM->compteurDeTour=0;	//tour 0
    maPartieHM->compteurErreur=0;	//pas d'erreur

    initMotMystere(maPartieHM->MotMystere,monDico);
    initMotDuJoueur(maPartieHM->MotMystere,maPartieHM->MotDuJoueur);
}
