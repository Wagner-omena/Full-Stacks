#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int cadastroUsuario(){

    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobreNome[50];
    char cargo[50];

    printf ("Cadastro de Usu�rio EBAC!\n\n");
    printf ("Digite o CPF a ser cadastrado:");
    scanf ("%s", &cpf);
    strcpy(arquivo,cpf);

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf (file,"CPF: %s\n",cpf);
    fclose (file);

    printf("Digite o nome do usu�rio: ");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,"Nome: %s\n",nome);
    fclose(file);

    printf("Digite o sobre nome:");
    scanf("%s",sobreNome);

    file = fopen(arquivo, "a");
    fprintf(file,"Sobre-nome: %s\n", sobreNome);
    fclose(file);

    printf("Digite o Cargo: ");
    scanf("%s",cargo );

    file = fopen(arquivo, "a");
    fprintf(file,"Cargo: %s\n",cargo);
    fclose(file);

    return 0;
}
int consultarUsuario(){
    setlocale(LC_ALL, "portuguese");
    char cpf[50];
    char conteudo[200];
    printf("Consulta de Usu�rio, por favor digite o CPF a ser consultado:");

    return 0;
}
int deletarUsuario(){

    return 0;
}

int main (){
    setlocale(LC_ALL, "portuguese");

    int menu = 0;
    int escolha = 0;

    for (; menu == 0;){
        system("cls");
        printf ("\t\t## BEM VINDO ##\n");
        printf ("Sistema de cadastro de anunos e fucionario.\n\n");
        printf ("\t1 - Cadastro usu�rio\n");
        printf ("\t2 - Consultar usu�rio\n");
        printf ("\t3 - Deletar usu�rio\n\n");
        printf ("Por favor escolha uma op��o: ");
        scanf ("%d", &escolha);

        switch (escolha){
            case 1:
            cadastroUsuario();
            break;
            case 2:
            consultarUsuario();
            break;
            case 3:
            deletarUsuario();
            break;
            default:
            if (escolha < 0 || escolha > 3){
                printf("Por favor escolha uma op��o valida!");
            }
            system("pause");
        }
    }

    return 0;
}