#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocações de espaço na memoria
#include <string.h> //Biblioteca de manipulação das strings
#include <locale.h> //Biblioteca de alocação de texto por região

int cadastroUsuario(){ 

    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobreNome[50];
    char cargo[50];

    system("cls");

    printf ("Cadastro de Usuário EBAC!\n\n");//Istrução para o usuário
    printf ("Digite o CPF a ser cadastrado:");
    scanf ("%s", &cpf);
    strcpy(arquivo,cpf); //Copia a string
    

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf (file,"CPF: %s\n",cpf);
    fclose (file);//Feichar o arquivo

    printf("Digite o nome do usuário: ");//Istrução para o usuário
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

    printf("\n\t\tConsulta de Usuário\n\nPor favor digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if (file == NULL){
        printf("CPF não encontrado!\n");
    }
    printf("\n\tInformações do usuário!\n\n");
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

    int menu = 0; // menu do usuário.
    int escolha = 0; 

    for (; menu == 0;){ // Opçao do menu para o usuário escolher. 
        system("cls"); // Limpa as mensangem anterio

        printf ("\t\t## BEM VINDO ##\n"); //Tela de boas vimda para os usuario
        printf ("Sistema de cadastro de anunos e fucionario.\n\n");
        printf ("\t1 - Cadastro usuário\n");//Menu de escolha do usuário
        printf ("\t2 - Consultar usuário\n");
        printf ("\t3 - Deletar usuário\n\n");
        printf ("Por favor escolha uma opção: ");

        scanf ("%d", &escolha); // Entra da escolha que o usuário vai fazer.

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
                printf("Por favor escolha uma opção valida!");
            }
            system("pause");
        }
    }

    return 0;
}