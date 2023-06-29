#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��es de espa�o na memoria
#include <string.h> //Biblioteca de manipula��o das strings
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o

int cadastroUsuario(){  //sistema de cadastro de usuario

    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobreNome[50];
    char cargo[50];

    system("cls"); //Limpa as mensagem anterio para deixa o menu limpo de mensagem anterior 

    printf ("Cadastro de Usu�rio EBAC!\n\n");//Istru��o para o usu�rio
    printf ("Digite o CPF a ser cadastrado:");
    scanf ("%s", cpf); // Ler o que o usuario digitar 
    strcpy(arquivo,cpf); //Copia a string
    

    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Abre o arquivo e o "w" significa esvreva
    if(file == NULL){
        printf("Erro ao tenta criar o arquivo!\n");
        return 1;
    }
    fprintf (file,"CPF: %s\n",cpf); //Escreve no arquivo
    fclose (file);//Feichar o arquivo

    printf("Digite o nome do usu�rio: ");//Istru��o para o usu�rio
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    if(file == NULL){ //verifica se o aquivo abril com sucesso
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fprintf(file,"Nome: %s\n",nome);
    fclose(file);

    printf("Digite o sobrenome: ");
    scanf("%s",sobreNome);

    file = fopen(arquivo, "a");
    if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fprintf(file,"Sobrenome: %s\n", sobreNome);
    fclose(file);

    printf("Digite o Cargo: ");
    scanf("%s",cargo );

    file = fopen(arquivo, "a");
    if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
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
    file = fopen(cpf,"r"); //Abre o arquivo e "r" significa ler o arquivo

    if (file == NULL){ //Verifica se o CPF existe
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
int deletarUsuario(){ //Sistema para pode excluir o usuario
    char cpf[50];

    system ("cls");

    printf("\t\tDeletar Usu�rio\n\nDigite o CPF a ser deletado:"); // Menu informativo para poder deletar usuario
    scanf("%s", cpf);

    if(remove(cpf) == 0){ //Remove o CPF escolhido e verifica se o comando foi bem sucedido
        printf("Usu�rio deletado com sucesso!\n");
    }else {
        printf("Usu�rio n�o encontrado.");
    }
    system("pause");
    return 0;
}

int main (){
    setlocale(LC_ALL, "portuguese"); // Define o texto em Portugues.

    int menu = 0; // menu do usu�rio.
    int escolha = 0;
    char senha[] = "a"; //senha para pode acessar o sistema
    int comparacao;

    printf("\t\t### Cart�rio da EBAC ###\n\n");
    printf("Login de adminstrador !\n\n Digite a sua senha: ");
    scanf("%s", senha);

    comparacao = strcmp(senha, "admin"); // strcmp usado para com�ra strings 
    if (comparacao == 0){ // verifica se a senha estar correta

    for (; menu == 0;){ // Op�ao do menu para o usu�rio escolher. 
        system("cls"); // Limpa as mensangem anterio

        printf ("\t\t## BEM VINDO ##\n"); //Tela de boas vimda para os usuario
        printf ("Sistema de cadastro de anunos e fucionario.\n\n");

        printf ("\t1 - Cadastro usu�rio\n");//Menu de escolha do usu�rio
        printf ("\t2 - Consultar usu�rio\n");
        printf ("\t3 - Deletar usu�rio\n\n");
        printf ("\t4 - sair do sistema.\n\n");

        printf ("Por favor escolha uma op��o: ");
        scanf ("%d", &escolha); // Entra da escolha que o usu�rio vai fazer.

        switch (escolha){ //As escolhas que pode ser feitas
            case 1:
            cadastroUsuario();
            break;
            case 2:
            consultarUsuario();
            break;
            case 3:
            deletarUsuario();
            break;
            case 4:
            printf("sistema fechado com sucesso.");
            return 0;
            break;
            default:
            if (escolha < 0 || escolha > 4){ //casa o usu�rio escolha uma op��o n�o existente
                printf("Por favor escolha uma op��o valida!");
            }
            system("pause"); //Pausa o systema e espera que o usu�rio aperte qualquer tecla para continua
        }
    }

    }else {
        printf("Senha errada");//informa que a senha esta errada
    }

    return 0; //Retorna 0 para dizer que a execu��o foi bem sucedida
}