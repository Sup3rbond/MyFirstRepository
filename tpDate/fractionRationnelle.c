#include <stdio.h>
#include <stdlib.h>

struct {int numerateur;
        int denominateur;} typedef FractionRationnelle;

int pgcd(int a, int b) {
    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;
    }
    return a;
}

void simplifie (FractionRationnelle* fraction){
    int temppgcd = pgcd((fraction->denominateur),(fraction->numerateur));
    (fraction->denominateur)/=temppgcd;
    (fraction->numerateur)/= temppgcd; 
}

int main (void){
    FractionRationnelle frac;
    frac.numerateur = 6;
    frac.denominateur = 4;
    simplifie(&frac);
    printf("%hu",frac.numerateur);
    printf("%hu",frac.denominateur);
    return 0;
}