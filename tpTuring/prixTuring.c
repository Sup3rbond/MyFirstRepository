/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>


typedef struct{
	unsigned short year;
	char* name;// ne pas oublier les \0
	char * topic;
}Winner;


void miseEnMemoire(char* fileName, char* outputFilename){
	FILE* f = fopen(fileName,"r");
	FILE* out = fopen(outputFileName,"w");
	bool finAtteinte = false;
	char* ligneEnMemoire;
	while (!finAtteinte){

		ligneEnMemoire = fgets(ligneEnMemoire,500,f);
		finAtteinte = (fgets==NULL);
		
	}




}







// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
    // TODO
	fclose();
	return EXIT_SUCCESS;
}
