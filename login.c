#include "bibliotecas.h"
#include "login.h"
#include "menuprincipal.h"
#include "auxiliares.h"

void telaLogin(int parametro)
{
    //***In�cio do login, a verifica��o do usu�rio na base de dados***
    FILE *file = fopen("dbfuncionarios.txt", "r"); //Abertura de base de dados de colaboradores para verifica��o se existe o usu�rio e senha informada
    if(file == NULL)//Verificar se o arquivo foi aberto com sucesso, se n�o, finalizar programa
    {
        FILE *file = fopen("dbfuncionarios.txt", "w");

        fprintf(file, "%d\n", 1);
        fprintf(file, "%i;%s;%s;%s;%s;%s;%s;%s;%s;%s;%.2f;%s;\n", 1, "root", "root", "123456", "Ativo","TI", " ", " ", " ", " ", 0.00," ");
        printf("PRIMEIRO ACESSO - Usuario root cadastrado, consultar manual!");
        fclose(file);
        getch();
    }

    FILE *file1 = fopen("dbdepartamentos.txt", "r"); //Abertura de base de dados de colaboradores para verifica��o se existe o usu�rio e senha informada
    if(file1 == NULL)//Verificar se o arquivo foi aberto com sucesso, se n�o, finalizar programa
    {
        FILE *file1 = fopen("dbdepartamentos.txt", "w");

        fprintf(file1, "%d\n", 1);
        fprintf(file1, "%i,%s,%s,%s,\n", 0,"TI","Ativo","01/01/1970");
        fclose(file1);
    }
    fclose(file1);

    cls();
    if(parametro == 0)
    {
        printf("------------------------------------------------------------------------------------------------------------------------");
        printf("		                                        Dados invalidos\n");
        printf("		                                        Tente novamente!\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }
    else
    {
        printf("------------------------------------------------------------------------------------------------------------------------");
        printf("		                                        Login\n");
        printf("                                                RCM Software Development\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }

    char usuarioDigitado[20];
    char senhaDigitada[30];

    printf("Usuario: ");
    scanf("%s", usuarioDigitado);
    getchar();

    printf("Senha: ");
    int i = 0;
    do
    {
        senhaDigitada[i] = getch();//Solicita do caractere do atual loop

        if(senhaDigitada[i] == BACKSPACE && i > 0)//Verifica��o se o caractere digitado � backspace
        {
            printf("\b");//retorna visualmente o cursor de digita��o
            putchar(' ');//coloca o espa�o vazio para que a * suma
            printf("\b");//novamente retorna visualmente o cursor de digita��o

            senhaDigitada[i] = '\0';//Troca caratete na posi��o [i] por um \0 que significa nulo ou final de vetor
            senhaDigitada[i-1] = '\0';//Troca caratete na posi��o [i - 1] por um \0 que significa nulo
            i--;//Retorna o [i] para que seja digitado um novo caractere apos a exclus�o
        }

        if((senhaDigitada[i] > 32 && senhaDigitada[i] < 127)) //Engloba todos os caracteres az-09-simbolos e a tecla enter
        {
            putchar('*');//coloca um * visual no console
            i++;//sobe para a pr�xima posi��o [i] para que seja digitado um novo char
        }
        else if (senhaDigitada[i] == ENTER)
        {
            i++;
        }
    }
    while(senhaDigitada[i-1] != ENTER);
    senhaDigitada[i-1] = '\0';//Ap�s o fim do loop, o enter � substituido por um \0 que significa nulo

    FILE *login;
    login = fopen("dbfuncionarios.txt", "r"); //Abertura de base de dados de colaboradores para verifica��o se existe o usu�rio e senha informada

    char linha[256];//Reservar espa�o para armazenamento das linhas do loop abaixo
    fgets(linha, 256, login);//Fun��o auxiliar para pular a primeira linha do arquivo de funcionarios

    while(fgets(linha, 256, login) != NULL)//Loop para retirar conte�do das linhas e jogar na variavel acima, enquando a linha for diferente de null
    {
        strtok(linha, ";");//Inicia��o de fun��o strtok que separa o conte�do da variavel at� o delimitador
        strtok(NULL, ";");//Separa o conte�do da variavel anterior at� o pr�ximo delimitador (Os dois primeiros dados da linha n�o s�o utilizados)

        char* usuarioDb = decriptarValor(strtok(NULL, ";"));
        char* senhaDb = decriptarValor(strtok(NULL, ";"));
        strtok(NULL, ";");
        char* departamentoDb = decriptarValor(strtok(NULL, ";"));

        //Verifica��o se o usu�rio e senha batem com algum colaborador do banco de dados
        //Se for verdadeiro chama o menu principal passando os parametros nome do usu�rio e o nivel de permiss�es
        if (strcmp(usuarioDb, usuarioDigitado) == 0 && strcmp(senhaDb, senhaDigitada) == 0)
        {
            cls();
            printf("------------------------------------------------------------------------------------------------------------------------");
            printf("		                                   Logado com sucesso!\n");
            printf("		                                   Bem-vindo(a) %s\n", usuarioDb);
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");

            printf("Pressione a qualquer tecla para continuar!");
            getch();

            fclose(login);
            menuPrincipal(usuarioDb, departamentoDb);
            break;
        }
    }
    //Se o while acabar na �ltima linha, significa que nenhum colaborador da base de dados atendeu a condi��o acima
    //Ent�o volta para a fun��o telaLogin passando o parametro 0 (Dados inv�lidos)
    fclose(login);
    telaLogin(0);
}
