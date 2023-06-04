#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "portuguese");

    int menu = 0;
    int escolha = 0;

    for (int menu = 0; menu == 0;){
        printf ("\t\t## BEM VINDO ##\n");
        printf ("Sistema de cadastro de anunos e fucionario.\n\n");
        printf ("\t1 - Cadastro usuário\n");
        printf ("\t2 - Consultar usuário\n");
        printf ("\t3 - Deletar usuário\n\n");
        printf ("Por favor escolha uma opção: ");
        scanf ("%d", &escolha);
    }

    return 0;
}