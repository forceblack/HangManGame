
#include <stdio.h>
#include <stdlib.h>

#include "Dico.h"

////////////////////////STRING/////////////////////////////////////////////////////////////////////////////////////////


void initString(String* ioString,int inSize)
{
	ioString->size=inSize;
	ioString->word=malloc(inSize+1);
}

void stringCopy (String* in,String* out)
{
	int i=0;
	out->size=in->size;
	for (i=0;i<out->size;i++)
	{out->word[i] = in->word[i];}
}

void releaseString(String* ioString)
{
	free(ioString->word);
	ioString->word=NULL;
	ioString->size=0;
}

void printString(String* inString)
{
    printf("voici la taille %d \n",inString->size);
    printf("voici le mot %s \n",inString->word);
}



////////////////////////////DICO///////////////////////////////////////////////////////////////////////////////////////////


void initDico(Dico* ioDico)
{

        //1 On ouvre notre liste de mot dans un .txt
    FILE* liste=NULL;
    liste=fopen ("Words.txt","r");
    if (liste != NULL)          //test d'ouverture
	{
        //printf("\nouverture reussi\n");

        //2 calcule le nombre de mot dans la liste
        ioDico->nWords=computeList(liste);
        //printf("voici le nombre de ligne %d",ioDico->nWords);

        //3 on peut donc allouer notre tableau de String qui va contenir les mots du Dico
        ioDico->Dictionnaire = malloc(ioDico->nWords * sizeof(String*));
            if (ioDico->Dictionnaire == NULL)
            {
                printf("probleme de malloc");
                exit(0);
            }

        //4 la prochaine etape consiste a remplir notre Dico dans chaque String
        int i=0;
        for (i=0 ; i < ioDico->nWords ; i++)             // - pour chaque ligne de notre .txt
            {
 // - on calcule le nombre de lettres avec lettercount initialise notre string (la taille du mot et alloue la memoire )
                initString(&ioDico->Dictionnaire[i],letterCount(i,liste)+1);

                fillString(i,&ioDico->Dictionnaire[i],liste);            // - on copie chaque lettre dans notre string
           //   printString(&ioDico->Dictionnaire[i]);
            }
	}
}


void releaseDico(Dico* ioDico)
{
    int i=0;
    for(i=0;i<ioDico->nWords;i++)
    {
        releaseString(&ioDico->Dictionnaire[i]);
    }

    free(ioDico->Dictionnaire);
    ioDico->nWords=0;
}



///////////////////////////////////////////MANIPULATION////////////////////////////////////////////////////////////////////////////



int computeList (FILE* liste) //fonction qui compte le nombre de lignes d'une liste
{
    int nbLigne=0;

    while (fgetc(liste)!=EOF)
	{
		fseek(liste, -1, SEEK_CUR);		//je recule d'un car j'ai fait un premier test
		if(fgetc(liste)=='\n') nbLigne++;	//je compte le nombre de \n
	}
    rewind(liste);  //on remet le curseur a 0 apres le comptage de lignes (un mot par ligne)

return nbLigne;
}


void gotoLine(int i, FILE* liste)
{
    rewind(liste); //on rembobine pour etre sur

    //aller a la lign N°i
    while (i != 0)
    {
        if(fgetc(liste)=='\n') i--; //on avance notre curseur jusqu'a etre a la bonne ligne
    }
}



int letterCount(int i, FILE* liste)
{
    gotoLine(i,liste);

    int count=0;
    while (fgetc(liste) != '\n')
    {
        count++;                    //on augmente notre conteur de lettre jusqu'as ce qu'on tombe sur un saut de ligne
    }
return count;
}



void fillString(int i,String* dicoWord,FILE* liste)
{
    gotoLine(i,liste);

    int c=0;
    while (fgetc(liste) != '\n')
    {
        {
		fseek(liste, -1, SEEK_CUR);
		dicoWord->word[c]=fgetc(liste);
		c++;
		}
    }
    dicoWord->word[c]='\0';     //ne pas oublier le caractere de fin de chaine
}
