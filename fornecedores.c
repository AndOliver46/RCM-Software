#include "bibliotecas.h"
#include "fornecedores.h"

typedef struct //Aqui temos a definição da Struct. Uma vez definida, podemos declarar qualquer
//variável com ela(struct cadastro cliente ou struct cadastro funcionario)
{
    char nome[40], rua[40], bairro[20],cidade[15], uf[4],
         numero[8], codigo[6], fone[17], cpf[15], status[9];

} Cadastro;
Cadastro forn; //declaração da variável "forn" como sendo do tipo struct cadastro.

void cadfornecedor()
{
    cabecalho();

    FILE *cadforn;

    cadforn = fopen("cad_fornecedor.txt", "ab");

    if(cadforn == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");

    }
    else
    {
        int opcao = 0;
        system("cls");
        cabecalho();

        printf("\nCNPJ........: %s\n",forn.cpf);

        printf("Codigo..........: ");
        scanf("%s",forn.codigo);
        getchar();

        printf("Razão Social:.......: ");
        scanf("%40[^\n]",forn.nome);
        getchar();

        printf("Telefone........: ");
        scanf("%s",forn.fone);
        getchar();

        printf("Endereco........: ");
        scanf("%40[^\n]",forn.rua);
        getchar();

        printf("Numero..........: ");
        scanf("%s",forn.numero);
        getchar();

        printf("Bairro..........: ");
        scanf("%20[^\n]",forn.bairro);
        getchar();

        printf("Cidade..........: ");
        scanf("%15[^\n]",forn.cidade);
        getchar();

        printf("Estado..........(UF): ");
        scanf("%s",forn.uf);
        getchar();

        strcpy(forn.status,"ATIVO");

        fwrite(&forn, sizeof(Cadastro),1,cadforn);

        printf("\nDeseja Cadastrar Novo Fornecedor(1-Sim / 2-Não)? ");
        scanf("%d",&opcao);
        getchar();

        if(opcao == 1)
        {
            fclose(cadforn);
            testeCnpj();
        }
        if (opcao == 2)
        {
            fclose(cadforn);
            fornecedores();
        }
        else
        {
            printf("\n\n****************************************************************\n");
            printf("                            OPÇÃO INVÁLIDA.                           ");
            printf("\n\n****************************************************************\n");
            system("pause");
        }
    }

}

void consulta()
{
    int erro = 0;
    cabecalho();

    FILE *cadforn;

    cadforn = fopen("cad_fornecedor.txt", "rb");

    if(cadforn == NULL)
    {
        printf("NÃO HÁ REGISTROS.\n");
        getch();
    }
    else
    {
        char cnpj[15];
        printf("Digite o CNPJ: ");
        scanf("%s", cnpj);
        getchar();

        while(fread(&forn, sizeof(Cadastro),1,cadforn) == 1)
        {
            if(strcmp(cnpj,forn.cpf)==0)
            {

                printf("\n\n****************************************************************\n");
                printf("Código: %s\n", forn.codigo);
                printf("Razão Social: %s\n", forn.nome);
                printf("CNPJ: %s\n", forn.cpf);
                printf("Telefone: %s\n", forn.fone);
                printf("Endereço: %s\n", forn.rua);
                printf("Número: %s\n", forn.numero);
                printf("Bairro: %s\n", forn.bairro);
                printf("Cidade: %s\n", forn.cidade);
                printf("Estado: %s\n\n", forn.uf);
                printf("Status: %s\n\n", forn.status);
                system("pause");
                erro = 1;
                break;
            }
        }
        if(erro == 0)
        {
            printf("\nCNPJ NÃO ENCONTRADO.");
            getch();
        }

    }
    fclose(cadforn);
}
void inativaForn()
{
    char cnpj[15];
    int opcao = 0;
    cabecalho();

    FILE *cadforn;

    cadforn = fopen("cad_fornecedor.txt", "rb");

    FILE *tempArq;
    tempArq = fopen("temp.txt", "ab");
    if(cadforn == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO");
    }
    else
    {
        printf("Digite o CNPJ: ");
        scanf("%s", cnpj);
        getchar();

        while(fread(&forn, sizeof(Cadastro),1,cadforn) == 1)
        {
            if(strcmp(cnpj,forn.cpf)==0)
            {
                printf("\n\n****************************************************************\n");
                printf("Código: %s\n", forn.codigo);
                printf("Razão Social: %s\n", forn.nome);
                printf("CNPJ: %s\n", forn.cpf);
                printf("Telefone: %s\n", forn.fone);
                printf("Endereço: %s\n", forn.rua);
                printf("Número: %s\n", forn.numero);
                printf("Bairro: %s\n", forn.bairro);
                printf("Cidade: %s\n", forn.cidade);
                printf("Estado: %s\n\n", forn.uf);
                printf("Status: %s\n\n", forn.status);
                printf("Você Tem Certeza Que Deseja INATIVAR Este Contato? (1-Sim / 2-Não) ");
                scanf("%d", &opcao);
                getchar();

                switch(opcao)
                {
                case 1:
                    strcpy(forn.status,"INATIVO");
                    fwrite(&forn, sizeof(Cadastro),1,tempArq);
                    printf("\nCADASTRO INATIVADO COM SUCESSO!\n");
                    break;

                case 2:
                    printf("OPERAÇÃO CANCELADA!");
                    fclose(cadforn);
                    fclose(tempArq);
                    return;
                    break;
                }
            }
            else
            {
                fwrite(&forn, sizeof(Cadastro),1,tempArq);
            }
        }
    }
    fclose(cadforn);
    fclose(tempArq);
    remove("cad_fornecedor.txt");
    rename("temp.txt","cad_fornecedor.txt");

    getch();
}

void ativaForn()
{
    char cnpj[15];
    int opcao = 0;
    cabecalho();

    FILE *cadforn;

    cadforn = fopen("cad_fornecedor.txt", "rb");

    FILE *tempArq;
    tempArq = fopen("temp.txt", "ab");
    if(cadforn == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO");
    }
    else
    {
        printf("Digite o CNPJ: ");
        scanf("%s", cnpj);
        getchar();

        while(fread(&forn, sizeof(Cadastro),1,cadforn) == 1)
        {
            if(strcmp(cnpj,forn.cpf)==0)
            {
                printf("\n\n****************************************************************\n");
                printf("Código: %s\n", forn.codigo);
                printf("Razão Social: %s\n", forn.nome);
                printf("CNPJ: %s\n", forn.cpf);
                printf("Telefone: %s\n", forn.fone);
                printf("Endereço: %s\n", forn.rua);
                printf("Número: %s\n", forn.numero);
                printf("Bairro: %s\n", forn.bairro);
                printf("Cidade: %s\n", forn.cidade);
                printf("Estado: %s\n\n", forn.uf);
                printf("Status: %s\n\n", forn.status);
                printf("Você Tem Certeza Que Deseja ATIVAR Este Contato? (1-Sim / 2-Não) ");
                scanf("%d", &opcao);
                getchar();

                switch(opcao)
                {
                case 1:
                    strcpy(forn.status,"ATIVO");
                    fwrite(&forn, sizeof(Cadastro),1,tempArq);
                    printf("\nCADASTRO ATIVADO COM SUCESSO!\n");
                    break;

                case 2:
                    printf("OPERAÇÃO CANCELADA!");
                    fclose(cadforn);
                    fclose(tempArq);
                    return;
                    break;
                }
            }
            else
            {
                fwrite(&forn, sizeof(Cadastro),1,tempArq);
            }
        }
    }
    fclose(cadforn);
    fclose(tempArq);
    remove("cad_fornecedor.txt");
    rename("temp.txt","cad_fornecedor.txt");

    getch();
}
void testeCnpj()
{
    cabecalho();

    FILE *cadforn;

    cadforn = fopen("cad_fornecedor.txt", "ab");
    fclose(cadforn);

    cadforn = fopen("cad_fornecedor.txt", "rb");

    if(cadforn == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");

    }
    else
    {
        char cnpj[15];
        printf("Digite o CNPJ: ");
        scanf("%s", cnpj);
        getchar();

        while(fread(&forn, sizeof(Cadastro),1,cadforn) == 1)
        {

            if(strcmp(cnpj,forn.cpf)==0)
            {

                printf("\n\n****************************************************************\n");
                printf("                  Este CNPJ já existe na Base de Dados.               ");
                printf("\n\n****************************************************************\n");
                getch();
                fclose(cadforn);
                return;
            }

        }
        sprintf(forn.cpf,"%s",cnpj);
        fclose(cadforn);
        cadfornecedor();
    }
}


void relatorio()
{
    cabecalho();

    FILE *cadforn;

    cadforn = fopen("cad_fornecedor.txt", "rb");

    if(cadforn == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");


    }
    else
    {
        while(fread(&forn, sizeof(Cadastro),1,cadforn) == 1)
        {
            printf("\n\n****************************************************************\n");
            printf("Código: %s\n", forn.codigo);
            printf("Razão Social: %s\n", forn.nome);
            printf("CNPJ: %s\n", forn.cpf);
            printf("Telefone: %s\n", forn.fone);
            printf("Endereço: %s\n", forn.rua);
            printf("Número: %s\n", forn.numero);
            printf("Bairro: %s\n", forn.bairro);
            printf("Cidade: %s\n", forn.cidade);
            printf("Estado: %s\n\n", forn.uf);
            printf("Status: %s\n\n", forn.status);
        }
    }
    fclose(cadforn);

    getch();
}

void fornecedores()

{
    setlocale(LC_ALL, "Portuguese"); //permite o uso de acentos e caracteres específicos do português.

    system("color f1"); //muda as cores da fonte e background no programa.


    int opcao;
    do
    {
        opcao = 0;
        cabecalho();
        printf("                       ***********************\n");
        printf("                       * 1 - Cadastro        *\n");
        printf("                       * 2 - Consulta        *\n");
        printf("                       * 3 - Ativar/Inativar *\n");
        printf("                       * 4 - Relatório       *\n");
        printf("                       * 5 - Voltar          *\n");
        printf("                       ***********************\n\n");
        printf("                       OPÇÃO: ");
        scanf("%d",&opcao);
        getchar();

        system("cls");
        switch (opcao)
        {
        case 1:
            testeCnpj();
            break;
        case 2:
            consulta();
            break;
        case 3:
            ativaInativa();
            break;
        case 4:
            relatorioMenu();
            break;
        case 5:
            break;
        default:
            printf("OPÇÃO INVÁLIDA!\n\n");
            getch();
            break;

        }
    }
    while(opcao != 5);
}

void ativaInativa()
{
    int opcao;
    do
    {
        opcao = 0;
        cabecalho();
        printf("                       **********************\n");
        printf("                       * 1 - Ativar         *\n");
        printf("                       * 2 - Inativar       *\n");
        printf("                       * 3 - Voltar         *\n");
        printf("                       **********************\n\n");
        printf("                       OPÇÃO: ");
        scanf("%d",&opcao);
        getchar();

        system("cls");
        switch (opcao)
        {
        case 1:
            ativaForn();
            break;
        case 2:
            inativaForn();
            break;
        case 3:
            break;
        default:
            printf("OPÇÃO INVÁLIDA!\n\n");
            getch();
            break;

        }
    }
    while(opcao != 3);
}

void relAtivo()
{
    cabecalho();

    FILE *cadforn;

    cadforn = fopen("cad_fornecedor.txt", "rb");

    if(cadforn == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");

    }
    else
    {
        while(fread(&forn, sizeof(Cadastro),1,cadforn) == 1)
        {
            if (strcmp(forn.status,"ATIVO" )== 0)
            {
                printf("\n\n****************************************************************\n");
                printf("Código: %s\n", forn.codigo);
                printf("Razão Social: %s\n", forn.nome);
                printf("CNPJ: %s\n", forn.cpf);
                printf("Telefone: %s\n", forn.fone);
                printf("Endereço: %s\n", forn.rua);
                printf("Número: %s\n", forn.numero);
                printf("Bairro: %s\n", forn.bairro);
                printf("Cidade: %s\n", forn.cidade);
                printf("Estado: %s\n\n", forn.uf);
                printf("Status: %s\n\n", forn.status);
            }
        }
    }
    fclose(cadforn);

    getch();
}

void relInativo()
{
    cabecalho();

    FILE *cadforn;

    cadforn = fopen("cad_fornecedor.txt", "rb");

    if(cadforn == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");
    }
    else
    {
        while(fread(&forn, sizeof(Cadastro),1,cadforn) == 1)
        {
            if (strcmp(forn.status,"INATIVO" )== 0)
            {
                printf("\n\n****************************************************************\n");
                printf("Código: %s\n", forn.codigo);
                printf("Razão Social: %s\n", forn.nome);
                printf("CNPJ: %s\n", forn.cpf);
                printf("Telefone: %s\n", forn.fone);
                printf("Endereço: %s\n", forn.rua);
                printf("Número: %s\n", forn.numero);
                printf("Bairro: %s\n", forn.bairro);
                printf("Cidade: %s\n", forn.cidade);
                printf("Estado: %s\n\n", forn.uf);
                printf("Status: %s\n\n", forn.status);
            }
        }
    }
    fclose(cadforn);

    getch();
}

void relatorioMenu()
{
    int opcao;
    do
    {
        opcao = 0;
        cabecalho();
        printf("                       **********************\n");
        printf("                       * 1 - Ativos         *\n");
        printf("                       * 2 - Inativos       *\n");
        printf("                       * 3 - Total          *\n");
        printf("                       * 4 - Voltar         *\n");
        printf("                       **********************\n\n");
        printf("                       OPÇÃO: ");
        scanf("%d",&opcao);
        getchar();

        system("cls");
        switch(opcao)
        {
        case 1:
            relAtivo();
            break;
        case 2:
            relInativo();
            break;
        case 3:
            relatorio();
            break;
        case 4:
            break;
        default:
            printf("OPÇÃO INVÁLIDA!\n\n");
            getch();
            break;

        }
    }
    while(opcao != 4);
}
