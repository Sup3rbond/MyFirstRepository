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


/*
void initialiserTailleDesChamps(char* ligneEnMemoire,int* tabAModifier){
			int count=0;
			int indiceChampActuel =0;
			char currentChar = ligneEnMemoire[count];
			while (currentChar!="\0"){
				if (currentChar!=";"){
					tabAModifier[indiceChampActuel]++;}
				else{
					indiceChampActuel+=1;
				}
			count+=1;

	
}
*/
Winner* readWinners(FILE* f){
	
	bool finAtteinte = false;
	char* ligneEnMemoire;
	ligneEnMemoire = fgets(ligneEnMemoire,500,f);
	printf("%c",ligneEnMemoire[0]);
	while (!finAtteinte){
		ligneEnMemoire = fgets(ligneEnMemoire,500,f);
		
	}
	Winner out;
	return(&out);
	}












// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE* f = fopen(filename,"r");
	FILE* out = fopen(outputFilename,"w");
	//int numberOfTuringWinners = numberOfLines(dataFile);
	Winner* winners =readWinners(f);
    // TODO
	
	return EXIT_SUCCESS;
}
