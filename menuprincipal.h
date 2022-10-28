#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include "bibliotecas.h"
#include "login.h"
#include "departamentos.h"
#include "clientes.h"
#include "fornecedores.h"
#include "projetos.h"
#include "funcionarios.h"

void menuPrincipal(char usuarioLogado[], char nivelPermissao[])
{
    int opcao;
    do
    {
        cls();
        printf("------------------------------------------------------------------------------------------------------------------------");
        printf("                                RCM Software Development LTDA\n");
        printf("                                Usu�rio logado: %s\n", usuarioLogado);
        printf("                                N�vel de permiss�o: %s\n", nivelPermissao);
        printf("                                Data: %s\n", dataAtual());
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");

        printf("M�dulos: \n\n");
        printf("[0]Sair\n[1]Funcion�rios\n[2]Clientes\n[3]Fornecedores\n[4]Departamentos\n[5]Projetos\n\n");

        printf("Op��o: ");
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

#endif // MENUPRINCIPAL_H_INCLUDED
