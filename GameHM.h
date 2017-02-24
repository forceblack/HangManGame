#ifndef GAMEHM_FILE	//protection contre les inclusions infinies
#define GAMEHM_FILE

//include
#include "Dico.h"

//define
#define TAILLE_ALPHABET 26


//struct
typedef struct
{
	String MotMystere;	//le mot a trouver
	String MotDuJoueur;	//mot du joueur de la meme taille
	char lettreDejaTeste[TAILLE_ALPHABET];	//On placera les lettre essayé par le joueur dans ce tableau

	int compteurDeTour;
	int compteurErreur;

}Partie;


//prototype
void HangMan();
void initPartie(Partie* maPartieHM,Dico* monDico);
void initMotMystere(String* ioString,Dico* inDico);
void initMotDuJoueur(String*,String*);

void releasePartie(Partie* maPartieHM);


#endif			//protection contre les inclusions infinies

