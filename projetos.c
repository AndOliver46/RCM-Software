#include "bibliotecas.h"
#include "projetos.h"
#include "clientes.h"
#include "auxiliares.h"

Projeto proj; //declaração da variável "proj" como sendo do tipo struct Projeto.
Cliente ctt;

void telaProjetos()
{
    system ("cls");
    int opcao = 0;

    do
    {
        cabecalho();
        printf("\n Projetos\n\n");

        printf(" [0]Voltar\n");
        printf(" [1]Novo\n");
        printf(" [2]Consultar\n");
        printf(" [3]Atualizar\n");
        printf(" [4]Gerar relatório\n");

        printf("\n Opção: ");
        scanf("%d",&opcao);
        getchar();

        switch(opcao)
        {
        case 1:
            chamaCliente();
            break;
        case 2:
            consultaProj();
            break;
        case 3:
            telaAtualiza();
            break;
        case 4:
            projRelatorio();
            break;
        case 0:
            return;
            break;
        default:
            printf(" \nOPÇÃO INVÁLIDA!\n\n");
            getch();
            break;
        }
    }
    while(opcao != 0);
}

void cadProjeto()
{
    system("cls");
    cabecalho();

    int opcao = 0, option = 0, conf = 0, optstatus = 0;

    FILE *cadproj;
    cadproj = fopen("projetos.txt", "a");

    if(cadproj == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");
    }
    else
    {
        printf("Razão Social: %s\n",proj.cliente);
        printf("CPF/CNPJ: %s\n", proj.cpf);

        printf("Numero do projeto: ");
        scanf("%s",proj.projetoN);
        getchar();

        printf("Titulo: ");
        scanf("%30[^\n]",proj.titulo);
        getchar();

        printf("Linguagem: ");
        scanf("%25[^\n]",proj.linguagem);
        getchar();

        printf("Status(1-ANALISE / 2-PROCESSO): ");
        scanf("%d",&optstatus);
        getchar();

        if(optstatus == 1)
        {
            strcpy(proj.status,"EM ANALISE");
        }
        if(optstatus == 2)
        {
            strcpy(proj.status,"EM PROCESSO");
        }

        printf("Data de Inicio: ");
        scanf("%d/%d/%d",&proj.inicio[0],&proj.inicio[1],&proj.inicio[2]);
        getchar();

        printf("Previsao de Entrega: ");
        scanf("%d/%d/%d",&proj.previsao[0],&proj.previsao[1],&proj.previsao[2]);
        getchar();

        printf("Valor do Projeto: ");
        scanf("%f",&proj.valor);
        getchar();


        printf("Qual a Forma de Pagamento?\n");
        printf("(1-A Vista(5%%) / 2-Parc. 2X / 3-Parc. 3X) ");
        scanf("%d",&option);
        getchar();

        switch(option)
        {

        case 1:
            proj.fPag = proj.valor*0.95;
            strcpy(proj.tPag,"A Vista(Desc. 5%)");
            printf("Forma de Pagamento: %s R$%.2f\n",proj.tPag,proj.fPag);
            break;
        case 2:
            proj.fPag = proj.valor/2;
            strcpy(proj.tPag,"2x");
            printf("Forma de Pagamento: %s R$%.2f\n",proj.tPag,proj.fPag);
            break;
        case 3:
            proj.fPag = proj.valor/3;
            strcpy(proj.tPag,"3x");
            printf("Forma de Pagamento: %s R$%.2f\n",proj.tPag,proj.fPag);
            break;
        default:
            printf("****** FORMA DE PAGAMENTO INVALIDA ******");
            getch();
            break;
        }


        printf("Descricao do Projeto: ");
        scanf("%120[^\n]",proj.descricao);
        getchar();

        system ("cls");
        cabecalho();

        printf("\n\nProjeto Numero: %s\n", proj.projetoN);
        printf("Titulo: %s\n", proj.titulo);
        printf("Cliente: %s\n", proj.cliente);
        printf("CPF/CNPJ: %s\n", proj.cpf);
        printf("Linguagem: %s\n", proj.linguagem);
        printf("Inicio: %d/%d/%d\n", proj.inicio[0],proj.inicio[1],proj.inicio[2]);
        printf("Previsao: %d/%d/%d\n", proj.previsao[0],proj.previsao[1],proj.previsao[2]);
        printf("Valor do Projeto: %.2f\n", proj.valor);
        printf("Forma de Pagamento: %s R$%.2f\n",proj.tPag,proj.fPag);
        printf("Descricao: %s\n\n", proj.descricao);
        printf("Status do Projeto: %s\n\n",proj.status);

        printf("Todas as informacoes estao corretas? (1-SIM / 2-NAO) ");
        scanf("%d",&conf);

        if(conf == 1)
        {
            fwrite(&proj, sizeof(Projeto),1,cadproj);
            printf("\n\n****** PROJETO CADASTRADO COM SUCESSO! ******\n\n");
        }
        else
        {
            printf("\n\n****** PROJETO NAO CADASTRADO. ******\n\n");
        }

        printf("Deseja cadastrar um novo projeto? (1-SIM / 2-NAO) ");
        scanf("%d",&opcao);
        getchar();


        if(opcao == 1)
        {
            fclose(cadproj);
            chamaCliente();
        }
        if (opcao == 2)
        {
            fclose(cadproj);
            telaProjetos();
        }
        else
        {
            printf("\n\n****************************************************************\n");
            printf("                         OPCAO INVALIDA                               ");
            printf("\n\n****************************************************************\n");
            getch();

        }
        fclose(cadproj);
        telaProjetos();
    }
}

void statusA()
{
    cabecalho();
    printf("******************************************** PROJETOS EM ANALISE **************************************************\n");

    FILE *cadproj;

    cadproj = fopen("projetos.txt", "r");

    if(cadproj == NULL )
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");

    }
    else
    {
        while((fread(&proj, sizeof(Projeto),1,cadproj)) == 1)
        {
            if(strcmp(proj.status, "EM ANALISE")== 0)
            {
                printf("\n\nProjeto Numero: %s\n", proj.projetoN);
                printf("Titulo: %s\n", proj.titulo);
                printf("Cliente: %s\n", proj.cliente);
                printf("CPF/CNPJ: %s\n", proj.cpf);
                printf("Linguagem: %s\n", proj.linguagem);
                printf("Inicio: %d/%d/%d\n", proj.inicio[0],proj.inicio[1],proj.inicio[2]);
                printf("Previsao: %d/%d/%d\n", proj.previsao[0],proj.previsao[1],proj.previsao[2]);
                printf("Conclusao: %d/%d/%d\n", proj.conclusao[0],proj.conclusao[1],proj.conclusao[2]);
                printf("Valor do Projeto: %.2f\n", proj.valor);
                printf("Forma de Pagamento: %s R$%.2f\n",proj.tPag,proj.fPag);
                printf("Descricao: %s\n\n", proj.descricao);
                printf("Status do Projeto: %s\n\n",proj.status);
                printf("\n****************************************************************\n\n");
            }
        }
        fclose(cadproj);
    }
    getch();
}
void statusP()
{
    cabecalho();
    printf("******************************************** PROJETOS EM PROCESSO **************************************************\n");

    FILE *cadproj;

    cadproj = fopen("projetos.txt", "r");

    if(cadproj == NULL )
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");

    }
    else
    {
        while((fread(&proj, sizeof(Projeto),1,cadproj)) == 1)
        {
            if(strcmp(proj.status, "EM PROCESSO") == 0)
            {
                printf("\n\nProjeto Numero: %s\n", proj.projetoN);
                printf("Titulo: %s\n", proj.titulo);
                printf("Cliente: %s\n", proj.cliente);
                printf("CPF/CNPJ: %s\n", proj.cpf);
                printf("Linguagem: %s\n", proj.linguagem);
                printf("Inicio: %d/%d/%d\n", proj.inicio[0],proj.inicio[1],proj.inicio[2]);
                printf("Previsao: %d/%d/%d\n", proj.previsao[0],proj.previsao[1],proj.previsao[2]);
                printf("Conclusao: %d/%d/%d\n", proj.conclusao[0],proj.conclusao[1],proj.conclusao[2]);
                printf("Valor do Projeto: %.2f\n", proj.valor);
                printf("Forma de Pagamento: %s R$%.2f\n",proj.tPag,proj.fPag);
                printf("Descricao: %s\n\n", proj.descricao);
                printf("Status do Projeto: %s\n\n",proj.status);
                printf("\n****************************************************************\n\n");
            }
        }
        fclose(cadproj);
    }
    getch();
}
void statusC()
{
    cabecalho();
    printf("******************************************** PROJETOS CONCLUIDOS **************************************************\n");

    FILE *cadproj;

    cadproj = fopen("projetos.txt", "r");

    if(cadproj == NULL )
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");

    }
    else
    {
        while((fread(&proj, sizeof(Projeto),1,cadproj)) == 1)
        {
            if(strcmp(proj.status, "CONCLUIDO") == 0)
            {
                printf("\n\nProjeto Numero: %s\n", proj.projetoN);
                printf("Titulo: %s\n", proj.titulo);
                printf("Cliente: %s\n", proj.cliente);
                printf("CPF/CNPJ: %s\n", proj.cpf);
                printf("Linguagem: %s\n", proj.linguagem);
                printf("Inicio: %d/%d/%d\n", proj.inicio[0],proj.inicio[1],proj.inicio[2]);
                printf("Previsao: %d/%d/%d\n", proj.previsao[0],proj.previsao[1],proj.previsao[2]);
                printf("Conclusao: %d/%d/%d\n", proj.conclusao[0],proj.conclusao[1],proj.conclusao[2]);
                printf("Valor do Projeto: %.2f\n", proj.valor);
                printf("Forma de Pagamento: %s R$%.2f\n",proj.tPag,proj.fPag);
                printf("Descricao: %s\n\n", proj.descricao);
                printf("Status do Projeto: %s\n\n",proj.status);
                printf("\n****************************************************************\n\n");
            }
        }
        fclose(cadproj);
    }
    getch();
}

void projRelatorio()
{
    cabecalho();

    FILE *cadproj;
    FILE *projexcel;

    cadproj = fopen("projetos.txt", "r");
    projexcel = fopen("RelatorioProjetos.csv", "w");

    if(cadproj == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");

    }
    else
    {
        fprintf(projexcel,"PROJETO N;CLIENTE;CNPJ;TITULO;TECNOLOGIA;STATUS;INICIO;PREVISAO;CONCLUSAO;DESCRICAO\n");
        while((fread(&proj, sizeof(Projeto),1,cadproj)) == 1 )
        {
            fprintf(projexcel,"%s;%s;%s;%s;%s;%s;%d/%d/%d;%d/%d/%d;%d/%d/%d;%s\n",
                    proj.projetoN,proj.cliente,proj.cpf,proj.titulo,proj.linguagem,proj.status,proj.inicio[0],proj.inicio[1],proj.inicio[2],proj.previsao[0],proj.previsao[1],proj.previsao[2],
                    proj.conclusao[0],proj.conclusao[1],proj.conclusao[2],proj.descricao);
        }
        printf("GERANDO O RELATORIO EM MS-EXCEL");
    }
    fclose(projexcel);
    fclose(cadproj);
    system("start RelatorioProjetos.csv");

    getch();
}

void consultaProj()
{
    int opcao = 0;;
    do
    {
        cabecalho();
        printf("\n Consultar\n\n");

        printf(" [0]Voltar\n");
        printf(" [1]Projetos em Analise\n");
        printf(" [2]Projetos em Producão\n");
        printf(" [3]Projetos concluídos\n\n");

        printf(" Opção: ");
        scanf("%d",&opcao);
        getchar();

        system("cls");
        switch (opcao)
        {
        case 1:
            statusA();
            break;
        case 2:
            statusP();
            break;
        case 3:
            statusC();
            break;
        case 0:
            return;
            break;
        default:
            printf("OPÇÃO INVÁLIDA!\n\n");
            getch();
            break;
        }
    }
    while(opcao != 0);
}

void chamaCliente()
{
    system("cls");
    cabecalho();

    char ddcpfcnpj[15];

    FILE *arquivo;
    arquivo = fopen ("cadastro.txt","r");

    if (arquivo == NULL)
    {
        printf ("Arquivo não encontrado\n");
    }
    else
    {

        printf("Digite o CPF/CNPJ: ");
        scanf("%s",ddcpfcnpj);
        getchar();
    }

    while (fread(&ctt, sizeof(Cliente),1,arquivo) == 1)
    {
        if (strcmp(ddcpfcnpj,ctt.cpfcnpj) == 0)
        {
            sprintf(proj.cliente,"%s",ctt.nome);
            sprintf(proj.cpf,"%s", ctt.cpfcnpj);
            fclose(arquivo);
            cadProjeto();
            break;
        }

    }
    printf(" CLIENTE NAO CADASTRADO!");
    getch();

    fclose(arquivo);
}
void telaAtualiza()
{
    char prjt[6];
    int opt = 0;
    int optstatus = 0;

    FILE *cadproj;

    cadproj = fopen("projetos.txt", "r");

    FILE *pTemp;

    pTemp = fopen("projtemp.txt", "a");

    if(cadproj == NULL || pTemp == NULL)
    {
        printf("ERRO NA ABERTURA DO ARQUIVO.\n");

    }
    else
    {

        printf("\n Numero do Projeto: ");
        scanf("%s",prjt);
        getchar();

        while((fread(&proj, sizeof(Projeto),1,cadproj)) == 1)
        {

            if(strcmp(proj.projetoN, prjt)== 0)
            {
                system("cls");
                cabecalho();

                printf("\nProjeto Numero: %s\n", proj.projetoN);
                printf("Titulo: %s\n", proj.titulo);
                printf("Cliente: %s\n", proj.cliente);
                printf("CPF/CNPJ: %s\n", proj.cpf);
                printf("Linguagem: %s\n", proj.linguagem);
                printf("Inicio: %d/%d/%d\n", proj.inicio[0],proj.inicio[1],proj.inicio[2]);
                printf("Previsao: %d/%d/%d\n", proj.previsao[0],proj.previsao[1],proj.previsao[2]);
                printf("Conclusao: %d/%d/%d\n", proj.conclusao[0],proj.conclusao[1],proj.conclusao[2]);
                printf("Valor do Projeto: %.2f\n", proj.valor);
                printf("Forma de Pagamento: %s R$%.2f\n",proj.tPag,proj.fPag);
                printf("Descricao: %s\n\n", proj.descricao);

                printf(" Status do Projeto: %s\n\n",proj.status);

                printf(" [0]Sair\n");
                printf(" [1]Atualizar Status\n");
                printf(" [2]Concluir projeto\n");

                printf("\n Opção: ");
                scanf("%d",&opt);

                switch(opt)
                {
                case 1:
                    printf("\n Escolha o novo status do projeto (1-Analise / 2-Processo): ");
                    scanf("%d",&optstatus);
                    getchar();
                    if(optstatus == 1)
                    {
                        strcpy(proj.status, "EM ANALISE");
                        printf("Alteração realizada!");
                        getchar();
                    }
                    if(optstatus == 2)
                    {
                        strcpy(proj.status, "EM PROCESSO");
                        printf("Alteração realizada!");
                        getchar();
                    }
                    fwrite(&proj, sizeof(Projeto),1,pTemp);

                    break;
                case 2:
                    printf("\n Data de entrega: ");
                    scanf("%d/%d/%d",&proj.conclusao[0],&proj.conclusao[1],&proj.conclusao[2]);
                    getchar();

                    strcpy(proj.status, "CONCLUIDO");

                    fwrite(&proj, sizeof(Projeto),1,pTemp);
                    printf(" Alteração realizada!");
                    getchar();

                    break;
                case 0:
                    fclose(cadproj);
                    fclose(pTemp);
                    remove("projtemp.txt");
                    return;
                    break;
                }
            }
            else
            {
                fwrite(&proj, sizeof(Projeto),1,pTemp);
            }
        }
        fclose(cadproj);
        fclose(pTemp);
    }
    remove("projetos.txt");
    rename("projtemp.txt","projetos.txt");

}
