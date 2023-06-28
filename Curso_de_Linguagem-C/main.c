#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

int main (){
    setlocale(LC_ALL, "portuguese");

    printf("BEM VINDO coração\n");
    int idade;
    char nome[50];
    double altura;
    float tamanho;
    bool verdade;
    int escolha = 1;

    while (escolha == 1) {
        printf("Digite sua idade: ");
        scanf("%d", &idade);

        printf("Digite seu nome: ");
        scanf("%s", nome);

        printf("Digite sua altura: ");
        scanf("%lf", &altura);

        printf("Digite o tamanho: ");
        scanf("%f", &tamanho);

        if (idade >= 18) {
            verdade = true;
            printf("verdade\n");
        } else {
            verdade = false;
            printf("falso\n");
        }

        printf("Idade: %d\nNome: %s\nAltura: %.2f\nTamanho: %.2f\nVerdade: %d\n", idade, nome, altura, tamanho, verdade);

        printf("Deseja inserir novas informações? (1-Sim, 0-Não): ");
        scanf("%d", &escolha);
    }

    return 0;
}
