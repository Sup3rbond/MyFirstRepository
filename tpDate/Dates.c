#include <stdio.h>
#include <stdlib.h>

 typedef enum{
    janvier,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
    } Mois;


 typedef struct {
    int jour;
    int annee;
    Mois mois;
    }Date;

void initialiseDate(Date* d){//on utilise une adresse de date pour la modification des variables (passage par valeur impossible sinon)
    
    printf("jour : ");
    scanf("%hu",&(d->jour));//va remplacer dans la struct de d le champ jour
    printf("mois :");
    scanf("%d",(int*)&d->mois);// on caste le mois* en int*
    printf("annee : ");
    scanf("%hu",&d->annee);


}


Date creerDateParCopie(){// multiplie par 2 l'espace mémoire utilisé
    Date d;
    initialiseDate(&d);
    return(d);
}


Date* newDate(){
    Date* d = (Date*)malloc(sizeof(Date));
    initialiseDate(d);
    return(d);
    

}

int main (void){
    Date d;
    initialiseDate(&d);
    Date* pDate;
    pDate = newDate();
    free(pDate);
    printf("%d",pDate);
}