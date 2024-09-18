#include <stdio.h>
#include <stdlib.h>

int* repeat (int tab1[] , int tab2[], int taille){
    int sum = 0;
    for(int i=0; i<taille;i++){
        sum+=tab1[i];
    }
    
    int* ptab =(int*) malloc(sum);
    
    for (int i=0; i<taille;i++){
        for (int j=0;j<tab1[i];j++){
            *(ptab+j+tab1[i])=tab2[i];

        }

    }

    int* out =ptab;
    free(ptab);
    return(out);

}

int main (void){
    int tab1[] ={1,2,4};
    int tab2[] ={10,3,8};
    int taille = sizeof(tab1);
    printf("%hu",taille);
    int* repete= repeat(tab1,tab2,taille);
    int test = *repete;
    printf("%hu",test);

}