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
        printf("------------------------------------------------------------------------------------------------------------------------");
        printf("\t\t\t\tRCM Software Development LTDA\n");
        printf("\tUsu�rio logado: %s\n", usuarioLogado);
        printf("\tN�vel de permiss�o: %s\n", nivelPermissao);
        printf("\tData: %s\n", dataAtual());
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");

        printf("\tM�dulos: \n\n");
        printf("\t[0]Sair\n\t[1]Funcion�rios\n\t[2]Clientes\n\t[3]Fornecedores\n\t[4]Departamentos\n\t[5]Projetos\n\n");

        printf("\tOp��o: ");
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
            printf("\nDigite uma op��o v�lida!\n\n");
            getch();
            cls();
            break;
        }
    }
    while (opcao != 0);
}
