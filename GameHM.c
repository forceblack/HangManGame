
#include <stdlib.h>
#include <time.h>

#include "GameHM.h"
#include "Dico.h"
#include "DisplayHM.h"
#include "LogicHM.h"

void HangMan()
{
        srand(time(NULL));	    //lancement du compte a rebours necessaire a la fonction rand
        Dico monDico;           //on creer un dictionnaire (une liste de mot contenu dans un fichier)
        initDico(&monDico);     //On l'initialise, on rempli ce dictionnaire de tout les mots du fichier .txt

        int continuerPartie=1;
        while (continuerPartie==1)	//On joue tant que continuer Partie vaut 1
        {
        Partie maPartieHM;                       //on commence par creer une partie (les elements necessaire a une partie
        initPartie(&maPartieHM,&monDico);        //on initilalise cette partie

// petit print pour voir si tout ce passe bien
        printString(&maPartieHM.MotMystere);
        printString(&maPartieHM.MotDuJoueur);

        do			//on joue
		{
		gameTurn(&maPartieHM);
		}while(gameEnding(&maPartieHM)==0);


        releasePartie(&maPartieHM);                 //on libere la memoire utilisé dans le Partie
        continuerPartie=toContinu(continuerPartie); //on demande si le joueur veut faire une autre partie
        }

        releaseDico(&monDico);                      //fin du jeu, plus de parti, on peut liberer la memoire de notre dictionnaire


}


/////////////////////////////////INIT DE PARTIE/////////////////////////////////////////////////////////////



void initPartie(Partie* maPartieHM,Dico* monDico)
{
    int i=0;
    for (i=0 ; i<TAILLE_ALPHABET ; i++)
    {maPartieHM->lettreDejaTeste[i]=0;}	//pour l'instant que des 0

    maPartieHM->compteurDeTour=0;	//tour 0
    maPartieHM->compteurErreur=0;	//pas d'erreur

    initMotMystere(&maPartieHM->MotMystere,monDico);
    initMotDuJoueur(&maPartieHM->MotMystere,&maPartieHM->MotDuJoueur);
}

void initMotMystere(String* ioString,Dico* inDico)
{
    int ligneMystere = rand() % (inDico->nWords);       //on determine un chiffre alleatoire en fonction du nombre de mot dans le dico

    initString(ioString,inDico->nWords);
    stringCopy(&inDico->Dictionnaire[ligneMystere],ioString);

//    printString(ioString);
}

void initMotDuJoueur(String* MotMystere,String* MotDuJoueur)
{
    initString(MotDuJoueur,MotMystere->size);

    int i=0;
    for (i=0 ; i<(MotMystere->size -1); i++)
    {
        MotDuJoueur->word[i]='*';
    }

    MotDuJoueur->word[i]='\0';     //ne pas oublier le caractere de fin de chaine

 //   printString(MotDuJoueur);
}

void releasePartie(Partie* maPartieHM)
{
    releaseString(&maPartieHM->MotMystere);
    releaseString(&maPartieHM->MotDuJoueur);
    int i=0;
    for(i=0;i<TAILLE_ALPHABET;i++)
    {
      maPartieHM->lettreDejaTeste[i]='0';
    }

    maPartieHM->compteurDeTour=0;
	maPartieHM->compteurErreur=0;
}

//////////////////////////////////LE DEROULEMENT D UN TOUR//////////////////////////////////////////////////////////////////////////

void gameTurn(Partie* ioPartie)
{
    //les differents affichage

	afficheLettreDejaTeste(ioPartie->lettreDejaTeste);	//les lettres deja essaye
	affichageMotMystere(ioPartie->MotDuJoueur.word);		//le mot
	printf("dans gameturn compteur erreur=%d",ioPartie->compteurErreur);


	lireCaractere(ioPartie);				//lecture au clavier

	comparaison(ioPartie);                  //comparaison motMystere mot

    ioPartie->compteurDeTour++;
	failCount(ioPartie);

	affichePendu(ioPartie->compteurErreur);			//le pendu
}






