#include <stdio.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "portuguese");

    int idade;
    char nome[50];
    float dinheiro = 100;
    
    int i;
    float s = 0;
    int vetor[5] = {10,20,30,40,50};

    int n = 1;
    int n2 = 4;
    int n3 = 1;
    n3+=n;

    printf("seu numero e: %d\n", n3);
/*
    for(i=0; i<5; i++){
        s += vetor[i];
    }
*/
    return 0;
}