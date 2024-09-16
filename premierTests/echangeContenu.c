#include <stdio.h>

void echangeContenu(int* p1, int* p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int main (void){
    int a = 20;
    int b = 10;
    echangeContenu(&a,&b);
    printf("a = %d",a);
}