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
        printf("                                Usuário logado: %s\n", usuarioLogado);
        printf("                                Nível de permissão: %s\n", nivelPermissao);
        printf("                                Data: %s\n", dataAtual());
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");

        printf("Módulos: \n\n");
        printf("[0]Sair\n[1]Funcionários\n[2]Clientes\n[3]Fornecedores\n[4]Departamentos\n[5]Projetos\n\n");

        printf("Opção: ");
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
                printf("Você não possui permissão para acessar esse módulo!\n\n");
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
                printf("Você não possui permissão para acessar esse módulo!\n\n");
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
                printf("Você não possui permissão para acessar esse módulo!\n\n");
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
                printf("Você não possui permissão para acessar esse módulo!\n\n");
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
                printf("Você não possui permissão para acessar esse módulo!\n\n");
                getch();
                cls();
                break;
            }
        default:
            cls();
            printf("\nDigite uma opção válida!\n\n");
            getch();
            cls();
            break;
        }
    }
    while (opcao != 0);
}

#endif // MENUPRINCIPAL_H_INCLUDED
