#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��es de espa�o na memoria
#include <string.h> //Biblioteca de manipula��o das strings
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o

int cadastroUsuario(){ 

    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobreNome[50];
    char cargo[50];

    system("cls");

    printf ("Cadastro de Usu�rio EBAC!\n\n");//Istru��o para o usu�rio
    printf ("Digite o CPF a ser cadastrado:");
    scanf ("%s", &cpf);
    strcpy(arquivo,cpf); //Copia a string
    

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf (file,"CPF: %s\n",cpf);
    fclose (file);//Feichar o arquivo

    printf("Digite o nome do usu�rio: ");//Istru��o para o usu�rio
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,"Nome: %s\n",nome);
    fclose(file);

    printf("Digite o sobrenome: ");
    scanf("%s",sobreNome);

    file = fopen(arquivo, "a");
    fprintf(file,"Sobrenome: %s\n", sobreNome);
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

    system("cls");

    printf("\n\t\tConsulta de Usu�rio\n\nPor favor digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if (file == NULL){
        printf("CPF n�o encontrado!\n");
    }
    printf("\n\tInforma��es do usu�rio!\n\n");
    while (fgets(conteudo,200,file)!= NULL)
    {
        printf("\t%s",conteudo);     
    }
    system("pause");
    

    return 0;
}
int deletarUsuario(){

    return 0;
}

int main (){
    setlocale(LC_ALL, "portuguese"); // Define o texto em Portugues.

    int menu = 0; // menu do usu�rio.
    int escolha = 0; 

    for (; menu == 0;){ // Op�ao do menu para o usu�rio escolher. 
        system("cls"); // Limpa as mensangem anterio

        printf ("\t\t## BEM VINDO ##\n"); //Tela de boas vimda para os usuario
        printf ("Sistema de cadastro de anunos e fucionario.\n\n");
        printf ("\t1 - Cadastro usu�rio\n");//Menu de escolha do usu�rio
        printf ("\t2 - Consultar usu�rio\n");
        printf ("\t3 - Deletar usu�rio\n\n");
        printf ("Por favor escolha uma op��o: ");

        scanf ("%d", &escolha); // Entra da escolha que o usu�rio vai fazer.

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