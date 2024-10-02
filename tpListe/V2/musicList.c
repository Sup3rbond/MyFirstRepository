#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct {
    char* Name;
    char* Artist;
    char* Album;
    char* Genre;
    int DiscNumber;
    int TrackNumber;
    int year;
} Music;



void afficheElement(Music* e){
    printf("Name : %s\nArtist : %s\nAlbum : %s\nGenre : %s\n",
    e->Name,
    e->Artist,
    e->Album,
    e->Genre
    );
    printf("DiscNumber : %d\nTrackNumber : %d\nyear : %d\n",
    e->DiscNumber,
    e->TrackNumber,
    e->year
    );
}



int numberOfMusics(FILE* f){
    char c = fgetc(f);
    int count =0;
    while (c!=EOF){
        if (c=='\n'){
            count+=1;
            
        }
        c = fgetc(f);
    }
    return count;
}

void decoupage(char* ligneActuelle, Music* uneMusique){
    
    char* decoupe = strtok(ligneActuelle,",");
    uneMusique->Name = strdup(decoupe);

    decoupe = strtok(NULL,",");
    uneMusique->Artist = strdup(decoupe);

    decoupe = strtok(NULL,",");
    uneMusique->Album = strdup(decoupe);

    decoupe = strtok(NULL,",");
    uneMusique->Genre = strdup(decoupe);
    
    decoupe = strtok(NULL,",");
    if (decoupe != NULL){
        uneMusique->DiscNumber = atoi(strdup(decoupe));
    }
    decoupe = strtok(NULL,",");
    if (decoupe != NULL){
        uneMusique->TrackNumber = atoi(strdup(decoupe));
    }
    

    decoupe = strtok(NULL,",");
    if (decoupe != NULL){
        uneMusique->year = atoi(strdup(decoupe));
    }
    
    
}







Music* enregistrementDesMusiques (int nombreDeMusiques, FILE* f){
    
    Music* listeDeMusiques = calloc(nombreDeMusiques, sizeof(Music));
    
    for (int i=1;i<nombreDeMusiques ;i++){
        
        
        char* ligneActuelle = calloc(500,sizeof(char));
        ligneActuelle = fgets(ligneActuelle,500,f);
        
        
        
        
        if (ligneActuelle != NULL) {
            decoupage(ligneActuelle,&listeDeMusiques[i]);
        }
        
        free(ligneActuelle);
        
        
    }
    return listeDeMusiques;
}

int main(void){
    char filename[] = "music.csv" ;
    FILE* musicCSV = fopen(filename,"r");
    int nombreDeMusiques = numberOfMusics(musicCSV);
    printf("%d\n",nombreDeMusiques);
    rewind(musicCSV);
    Music* ListeDeMusiques = enregistrementDesMusiques(nombreDeMusiques,musicCSV);
    afficheElement(&ListeDeMusiques[2000]);
    free(ListeDeMusiques);
    fclose(musicCSV);
}










