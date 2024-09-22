/*
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>


typedef struct{
	char* year;
	char* name;// ne pas oublier les \0
	char * topic;
}Winner;


int numberOfLines(FILE* dataFile){
	int count = 0;
	char currentChar = fgetc(dataFile);
	while (currentChar!=EOF){
		if (currentChar=='\n'){
			count+=1;
		}
		currentChar = fgetc(dataFile);
	}
	count+=1;
	return(count);
}


void separationChamps(char* pointeurLigne, Winner* gagnantTraite){
	
	char* decoupe;
	char *ligneModifiee = strdup(pointeurLigne);
	decoupe = strtok(ligneModifiee,";");
	//printf("%s\n", decoupe);
	
	if (decoupe !=NULL){
		(gagnantTraite->year)=strdup(decoupe);
		}
		
	
	decoupe=strtok(NULL,";");
	if (decoupe !=NULL){
		(gagnantTraite->name) = strdup(decoupe);
	}

	decoupe=strtok(NULL,";");
	if (decoupe !=NULL){
		(gagnantTraite->topic) = strdup(decoupe);
	}
	
	free(ligneModifiee);

	

}


void constructionStruct( FILE* dataFile, Winner* listeGagnants,int numberOfTuringWinners){
	for (int i=0; i<numberOfTuringWinners;i++){
		Winner* gagnantTraite = &(listeGagnants[i]);
		char* pointeurLigne = calloc(500, sizeof(char));
		fgets(pointeurLigne,500,dataFile);
		separationChamps(pointeurLigne, gagnantTraite);
		free(pointeurLigne);
		
		


	}
}


Winner* readWinners (FILE* dataFile, int numberOfTuringWinners){
	Winner* listeGagnants = calloc(numberOfTuringWinners,sizeof(Winner));
	constructionStruct(dataFile, listeGagnants, numberOfTuringWinners);
	return(listeGagnants);


}


void reecriture(FILE* outFile, Winner* listeGagnants, int nombreDeGagnants) {
    for (int i = 0; i < nombreDeGagnants; i++) {
        Winner gagnant = listeGagnants[i];

        
        fprintf(outFile, "%s;%s;%s\n", 
                gagnant.year,   
                gagnant.name,  
                gagnant.topic);

}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE* dataFile = fopen(filename,"r");
	FILE* out = fopen(outputFilename,"w");
	int numberOfTuringWinners = numberOfLines(dataFile);
	fseek(dataFile, 0, SEEK_SET);
	Winner* test = readWinners(dataFile, numberOfTuringWinners);
	reecriture(out, test,numberOfTuringWinners);
	free(test);
	fclose(out);
	fclose(dataFile);
	return EXIT_SUCCESS;
}
