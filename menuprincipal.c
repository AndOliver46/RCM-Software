#include "bibliotecas.h"
#include "menuprincipal.h"
#include "auxiliares.h"
#include "funcionarios.h"
#include "clientes.h"
#include "fornecedores.h"
#include "departamentos.h"
#include "projetos.h"

void menuPrincipal(char usuarioLogado[], char nivelPermissao[])
{
    int opcao;
    do
    {
        cls();
        printf("********************************************************************************************************************\n");
        printf("\t\t\t\t\t\tRCM SOFTWARE DEVELOPMENT\n");
        printf("\t\t\t\t\t\tUsu�rio logado: %s\n", usuarioLogado);
        printf("\t\t\t\t\t\tN�vel de permiss�o: %s\n", nivelPermissao);
        printf("\t\t\t\t\t\tData: %s\n", dataAtual());
        printf("********************************************************************************************************************\n\n");

        printf(" M�dulos: \n\n");
        printf(" [0]Sair\n [1]Funcion�rios\n [2]Clientes\n [3]Fornecedores\n [4]Departamentos\n [5]Projetos\n\n");

        printf(" Op��o: ");
        scanf("%i", &opcao);

        switch(opcao)
        {
        case 0:
            cls();
            exit(0);
            break;
        case 1:
            cls();
            if(strcmp(nivelPermissao,"RH") == 0 || strcmp(nivelPermissao,"TI") == 0 || strcmp(nivelPermissao,"CEO") == 0)
            {
                telaFuncionarios();
                break;
            }
            else
            {
                cls();
                printf("Voc� n�o possui permiss�o para acessar esse m�dulo!\n\n");
                getch();
                cls();
                break;
            }
        case 2:
            cls();
            if(strcmp(nivelPermissao,"COMERCIAL") == 0 || strcmp(nivelPermissao,"TI") == 0 || strcmp(nivelPermissao,"CEO") == 0)
            {
                clientes();
                break;
            }
            else
            {
                cls();
                printf("Voc� n�o possui permiss�o para acessar esse m�dulo!\n\n");
                getch();
                cls();
                break;
            }
        case 3:
            cls();
            if(strcmp(nivelPermissao,"COMPRAS") == 0 || strcmp(nivelPermissao,"TI") == 0 || strcmp(nivelPermissao,"CEO") == 0)
            {
                fornecedores();
                break;
            }
            else
            {
                cls();
                printf("Voc� n�o possui permiss�o para acessar esse m�dulo!\n\n");
                getch();
                cls();
                break;
            }
        case 4:
            cls();
            if(strcmp(nivelPermissao,"RH") == 0 || strcmp(nivelPermissao,"TI") == 0 || strcmp(nivelPermissao,"CEO") == 0)
            {
                telaDepartamentos();
                break;
            }
            else
            {
                cls();
                printf("Voc� n�o possui permiss�o para acessar esse m�dulo!\n\n");
                getch();
                cls();
                break;
            }
        case 5:
            cls();
            if(strcmp(nivelPermissao,"COMERCIAL") == 0 || strcmp(nivelPermissao,"TI") == 0 || strcmp(nivelPermissao,"CEO") == 0)
            {
                telaProjetos();
                break;
            }
            else
            {
                cls();
                printf("Voc� n�o possui permiss�o para acessar esse m�dulo!\n\n");
                getch();
                cls();
                break;
            }
        default:
            cls();
            printf("\n Digite uma op��o v�lida!\n\n");
            getch();
            cls();
            break;
        }
    }
    while (opcao != 0);
}
