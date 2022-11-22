#include "bibliotecas.h"
#include "login.h"
#include "menuprincipal.h"
#include "auxiliares.h"

void telaLogin(int parametro)
{
    FILE *file = fopen("dbfuncionarios.txt", "r");
    if(file == NULL)
    {
        FILE *file = fopen("dbfuncionarios.txt", "w");

        fprintf(file, "%d\n", 1);
        fprintf(file, "%i;%s;%s;%s;%s;%s;%s;%s;%s;%s;%.2f;%s;\n", 1, "Root", "tqqv", "345678", "Ativo","TI", "pwnn", "null", "null", "null", 0.00,dataAtual());
        printf("PRIMEIRO ACESSO - Usuario root cadastrado!");
        fclose(file);
        getch();
    }

    FILE *file1 = fopen("dbdepartamentos.txt", "r");
    if(file1 == NULL)
    {
        FILE *file1 = fopen("dbdepartamentos.txt", "w");

        fprintf(file1, "%d\n", 1);
        fprintf(file1, "%i,%s,%s,%s,\n", 0,"TI","Ativo",dataAtual());
        fclose(file1);
    }
    fclose(file1);

    cls();
    if(parametro == 0)
    {
        cabecalhoErro();
    }
    else
    {
        cabecalho();
    }

    char usuarioDigitado[20];
    char senhaDigitada[30];

    printf(" Usuario: ");
    scanf("%s", usuarioDigitado);
    getchar();

    printf(" Senha: ");
    int i = 0;
    do
    {
        senhaDigitada[i] = getch();

        if(senhaDigitada[i] == BACKSPACE && i > 0)
        {
            printf("\b");
            putchar(' ');
            printf("\b");

            senhaDigitada[i] = '\0';
            senhaDigitada[i-1] = '\0';
            i--;
        }

        if((senhaDigitada[i] > 32 && senhaDigitada[i] < 127))
        {
            putchar('*');
            i++;
        }
        else if (senhaDigitada[i] == ENTER)
        {
            i++;
        }
    }
    while(senhaDigitada[i-1] != ENTER);
    senhaDigitada[i-1] = '\0';

    FILE *login;
    login = fopen("dbfuncionarios.txt", "r");

    char linha[256];
    fgets(linha, 256, login);

    while(fgets(linha, 256, login) != NULL)
    {
        strtok(linha, ";");
        strtok(NULL, ";");
        char* usuarioDb = decriptarValor(strtok(NULL, ";"));
        char* senhaDb = decriptarValor(strtok(NULL, ";"));
        char* statusDb = strtok(NULL, ";");
        char* departamentoDb = strtok(NULL, ";");

        if (strcmp(usuarioDb, usuarioDigitado) == 0 && strcmp(senhaDb, senhaDigitada) == 0 && strcmp(statusDb, "Ativo") == 0)
        {
            cls();
            cabecalhoLoginSucesso(usuarioDb);
            getch();

            fclose(login);
            menuPrincipal(usuarioDb, departamentoDb);
            break;
        }
    }
    fclose(login);
    telaLogin(0);
}
