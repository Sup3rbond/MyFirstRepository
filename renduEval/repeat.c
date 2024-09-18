#include <stdio.h>
#include <stdlib.h>

int* repeat (int tab1[] , int tab2[], int taille){
    int sum = 0;
    for(int i=0; i<taille;i++){
        sum+=tab1[i];
    }
    
    int* ptab =(int*) malloc(sum);
    
    int decalage = 0;
    for (int i=0; i<taille;i++){
        for (int j=0;j<tab1[i];j++){
            ptab[decalage+j]=tab2[i];

        }
        decalage = tab1[i];
    }

    return ptab;
}

int main (void){
    int tab1[] ={1,2,4};
    int tab2[] ={10,3,8};
    int taille = 3;
    int* repete= repeat(tab1,tab2,taille);
    for (int i=0;i<7;i++){
        int temp = repete[i];
        printf("%d ",temp);
    }
    free(repete);
    
}