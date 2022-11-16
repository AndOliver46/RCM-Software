#include "bibliotecas.h"
#include "auxiliares.h"
#include "clientes.h"

Cliente ctt;

void consultarCliente()
{
    system ("cls");
    cabecalho();

    int erro = 0;

    FILE *arquivo;
    arquivo = fopen ("cadastro.txt","r");

    if (arquivo == NULL)
    {
        printf ("Arquivo não encontrado\n");
    }
    else
    {
        char ddcpfcnpj[15];
        printf("Digite o CPF/CNPJ: ");
        scanf("%s",ddcpfcnpj);
        getchar();

        while (fread(&ctt, sizeof(Cliente),1,arquivo) == 1)
        {
            if (strcmp(ddcpfcnpj,ctt.cpfcnpj) == 0)
            {
                erro = 1;
                printf("\n\n**********************\n");
                printf("Código: %s\n", ctt.codigo);
                printf("Nome: %s\n", ctt.nome);
                printf("Cpf/Cnpj: %s\n", ctt.cpfcnpj);
                printf("Endereço: %s\n", ctt.endereco);
                printf("Email: %s\n", ctt.email);
                printf("Telefone: %s\n", ctt.telefone);
                printf("Status: %s\n", ctt.status);
                getch();
            }

        }
        if (erro == 0)
        {
            printf ("Cpf/Cnpj não encontrado\n");
        }
        fclose(arquivo);
    }
    system ("pause");
}



void telacadastro()
{
    system ("cls");
    cabecalho();

    FILE *arquivo;
    arquivo = fopen("cadastro.txt", "a");

    if (arquivo == NULL)
    {
        printf("Arquivo não encontrado");
    }
    else
    {
        printf("\n Cadastro de Cliente\n\n");

        do
        {
            fflush(stdin);
            printf("Código: ");
            scanf("%40[^\n]",ctt.codigo);
            getchar();
        }
        while(numerico(ctt.codigo) != 1);

        do
        {
            fflush(stdin);
            printf("Nome completo: ");
            scanf("%40[^\n]",ctt.nome);
            getchar();
        }
        while(alfabeto(ctt.nome) != 1);



        do
        {
            fflush(stdin);
            printf("CPF/CNPJ: ");
            scanf("%s", ctt.cpfcnpj);
            getchar();
        }
        while(numerico(ctt.cpfcnpj) != 1);



        fflush(stdin);
        printf("Endereço: ");
        scanf("%40[^\n]",ctt.endereco);
        getchar();

        do
        {
            fflush(stdin);
            printf("Numero de telefone: ");
            scanf("%s",ctt.telefone);
            getchar();
        }
        while(numerico(ctt.cpfcnpj) != 1);


        fflush(stdin);
        printf("Email: ");
        scanf("%s",ctt.email);
        getchar();

        strcpy (ctt.status,"ativo");

        printf("\n Cadastro realizado com sucesso!\n\n");
        system ("pause");

        fwrite(&ctt,sizeof(Cliente),1,arquivo);

        fclose(arquivo);
    }
}

void Catualizar()
{
    system ("cls");
    cabecalho();

    char dadocpf[15];
    int opcao =0;

    FILE *arquivo;
    arquivo = fopen("cadastro.txt", "r");

    FILE *arqTem;
    arqTem = fopen ("temp.txt","w");

    printf("Digite o cpf/cnpj: ");
    scanf("%s", dadocpf);
    getchar();

    while (fread(&ctt, sizeof(Cliente),1, arquivo) == 1)
    {
        if (strcmp(dadocpf,ctt.cpfcnpj)==0)
        {
            printf("\n\n**********************\n");
            printf("Código: %s\n", ctt.codigo);
            printf("Nome: %s\n", ctt.nome);
            printf("Cpf/Cnpj: %s\n", ctt.cpfcnpj);
            printf("Endereço: %s\n", ctt.endereco);
            printf("Email: %s\n", ctt.email);
            printf("Telefone: %s\n", ctt.telefone);
            printf("Status: %s\n", ctt.status);


            printf("\tO que deseja alterar?\t\n");
            printf("[1]Código\n[2]Nome\n[3]CPF/CNPJ\n[4]Endereço\n[5]Telefone\n[6]Email\n");
            scanf("%i", &opcao);
            getchar();

            switch(opcao)
            {
            case 1:
                printf("Código: ");
                scanf("%s", ctt.codigo);
                getchar();
                break;


            case 2:

                do
                {
                    printf("Nome completo: ");
                    scanf("%50[^\n]", ctt.nome);
                    getchar();
                }
                while(alfabeto(ctt.nome) != 1);
                break;


            case 3:

                do
                {
                    printf("CPF/CNPJ: ");
                    scanf("%s", ctt.cpfcnpj);
                    getchar();
                }
                while(numerico(ctt.cpfcnpj) != 1);
                break;


            case 4:
                do
                {
                    printf("Endereço: ");
                    scanf("%s", ctt.endereco);
                    getchar();


                case 5:
                    printf("Telefone: ");
                    scanf("%s", ctt.telefone);
                    getchar();
                }
                while(numerico(ctt.telefone) != 1);
                break;

            case 6:
                printf("Email: ");
                scanf("%s", ctt.email);
                getchar();
                break;

            default:
                printf("Digite uma opcao valida.");
                break;
            }

            fwrite(&ctt, sizeof(Cliente),1,arqTem);

        }

        else
        {
            fwrite(&ctt, sizeof(Cliente),1,arqTem);
        }
    }
    fclose(arquivo);
    fclose(arqTem);
    remove("cadastro.txt");
    rename("temp.txt","cadastro.txt");

    getch();
}


void crelatorio()
{

    system ("cls");

    FILE *arquivo;

    arquivo = fopen("cadastro.txt", "r");

    FILE *excel;

    excel = fopen ("relaexcel.csv", "w");


    if(arquivo == NULL)
    {
        printf("Arquivo não encontrado\n");
    }

    else
    {
        fprintf(excel,"Código;Nome;CPF/CNPJ;Endereço;Email;Telefone;Status\n\n");
        while((fread(&ctt, sizeof(Cliente),1,arquivo))==1 )
        {
            fprintf(excel,"%s;%s;%s;%s;%s;%s;%s\n",ctt.codigo,ctt.nome,ctt.cpfcnpj,ctt.endereco,ctt.telefone,ctt.email,ctt.status);
        }
        printf("Relatório em processo, aguarde!");
    }

    fclose(arquivo);
    fclose(excel);
    system("start relaexcel.csv");

    getch();
}


void Telaexclui()
{
    system ("cls");
    cabecalho();

    char dadocpf[15];
    int opcao =0;

    FILE *arquivo;
    arquivo = fopen("cadastro.txt", "r");

    FILE *arqTem;
    arqTem = fopen ("temp.txt","w");

    if (arquivo == NULL)
    {
        printf("Arquivo não encontrado!");
    }
    else
    {

        printf("Digite o cpf/cnpj: ");
        scanf("%s", dadocpf);
        getchar();


        while (fread(&ctt, sizeof(Cliente),1, arquivo) == 1)
        {

            if(strcmp(dadocpf,ctt.cpfcnpj)==0)
            {
                printf("\n\n**********************\n");
                printf("Código: %s\n", ctt.codigo);
                printf("Nome: %s\n", ctt.nome);
                printf("Cpf/Cnpj: %s\n", ctt.cpfcnpj);
                printf("Endereçoo: %s\n", ctt.endereco);
                printf("Email: %s\n",ctt.email);
                printf("Telefone: %s\n", ctt.telefone);
                printf("Status: %s",ctt.status);

                printf("\n\nVocê tem certeza que deseja inativar esse clente? (1-Sim / 2-Não) ");
                scanf("%d", &opcao);
                getchar();


                if (opcao == 2)
                {
                    fwrite(&ctt, sizeof(Cliente),1,arqTem);
                    printf("Operação cancelada!");
                }
                else
                {
                    strcpy (ctt.status,"inativo");
                    fwrite(&ctt, sizeof(Cliente),1,arqTem);
                    printf("\nCadastro inativado com sucesso!\n");
                }

            }
        }

    }
    fclose(arquivo);
    fclose(arqTem);
    remove("cadastro.txt");
    rename("temp.txt","cadastro.txt");

    getch();
}



void clientes()
{
    int opcao = 1;

    while (opcao != 0)
    {
        system ("cls");
        cabecalho();

        printf("\n Clientes");
        printf("\n\n [0]Sair\n [1]Consulta\n [2]Cadastro\n [3]Excluir\n [4]Alterar\n [5]Gerar relatório\n");

        printf("\n Opção: ");
        scanf("%d",&opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            consultarCliente();
            break;

        case 2:
            telacadastro();
            break;

        case 3:
            Telaexclui();
            break;

        case 4:
            Catualizar();
            break;

        case 5:
            crelatorio();
            break;

        default:
            return;

        }
    }
    return;
}
