#ifndef DICO_FILE	//protection contre les inclusions infinies
#define DICO_FILE

#include <stdio.h>

//define

//struct

typedef struct
{
	char* word;	//déclaration du mot
	int size;	//la longueur de ce mot
}String;



typedef struct
{
    int nWords;             //nombre de mot dans le Dico
    String* Dictionnaire;   //tableau de String contenant tout les mots du Dico
}Dico;


//prototype

void initString(String* ioString,int inSize);
void stringCopy (String* in,String* out);
void releaseString(String* ioString);
void printString(String* inString);

void initDico(Dico* ioDico);
void releaseDico(Dico* ioDico);

int computeList (FILE* liste);
void gotoLine(int i, FILE* liste);
int letterCount(int i, FILE* liste);
void fillString(int i,String* myString,FILE* liste);


#endif			//protection contre les inclusions infinies
