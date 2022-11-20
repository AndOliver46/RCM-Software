#include "bibliotecas.h"
#include "departamentos.h"
#include "auxiliares.h"
#include "funcionarios.h"

int cadastrarDepartamento(Departamento **vetor, int quant, int tam)
{
    cls();
    cabecalho();
    printf("\n Cadastrar departamento\n\n");

    if(quant < tam)
    {
        Departamento *novo = malloc(sizeof(Departamento));

        novo->dId = quant;

        printf("Nome: ");
        strcpy(novo->dNome,alfabeticoLimite(19));
        strcpy(novo->dNome,maiusculo(novo->dNome));

        strcpy(novo->dStatus,"Ativo");
        strcpy(novo->dDataCadastro,dataAtual());

        vetor[quant] = novo;

        cls();
        cabecalho();
        printf("\n Informações do novo departamento:\n\n");

        printf(" Código do departamento: %d\n", vetor[quant]->dId+1001);
        printf(" Nome..................: %s\n", vetor[quant]->dNome);
        printf(" Funcionarios..........: %i\n", quantidadeDeFuncionarios(vetor[quant]->dNome));
        printf(" Folha de pagamento....: R$ %.2f\n", custoDepartamento(vetor[quant]->dNome));
        printf(" Status................: %s\n", vetor[quant]->dStatus);
        printf(" Data de cadastro......: %s\n", vetor[quant]->dDataCadastro);

        printf("\n Departamento cadastrado com sucesso!");
        getch();

        return 1;
    }
    else
    {
        cls();
        printf("\n\tImpossível realizar novo cadastro, lista de departamentos cheia!");

        return 0;
    }
}

void consultarDepartamento(Departamento **vetor, int quant)
{
    cls();
    cabecalho();

    printf("\n----------------------------------------------------------------------------------------------------------------\t\n");
    printf("%-7s%-20s%-15s%-15s%-10s%-13s\n", "Id", "Nome", "Funcionarios", "Folha","Status", "Data Cadastro");

    int i;
    for (i=0; i < quant; i++)
    {
        printf("%-7i%-20s%-15iR$ %-12.2f%-10s%-13s\n", vetor[i]->dId+1001, vetor[i]->dNome, quantidadeDeFuncionarios(vetor[i]->dNome), custoDepartamento(vetor[i]->dNome), vetor[i]->dStatus, vetor[i]->dDataCadastro);
    }
    printf("\n----------------------------------------------------------------------------------------------------------------\t\n\n\n");
}

void deletarDepartamento(Departamento **vetor, int quant)
{
    cls();
    consultarDepartamento(vetor,quant);

    printf("\n Deletar registros\n\n");

    int id;
    printf("\n Digite o Id do deparamento que deseja desativar: ");
    scanf("%d", &id);
    getchar();
    id -= 1001;

    if(id >= 0 && id < quant)
    {
        if(quantidadeDeFuncionarios(vetor[id]->dNome) != 0)
        {
            printf("\n Não é possível desativar um departamento com funcionários!\n");
            getch();
        }
        else
        {
            strcpy(vetor[id]->dStatus,"Inativo");

            printf("\n Departamento desativado com sucesso!\n");
            getch();
        }
    }
    else
    {
        printf("\n Código inválido!\n");
        getch();
    }

    cls();
}

void relatorioDepartamento(Departamento **vetor, int quant)
{
    int opcao = 0;

    do
    {
        consultarDepartamento(vetor, quant);

        printf(" Qual tipo de relatório deseja exportar?\n\n [0]Voltar\n [1]Relatório individual (TXT)\n [2]Relatório geral (TXT)\n [3]Relatório geral (Excel)\n\n Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
        case 0:
            cls();
            return;
            break;
        case 1:
            ;
            int id;
            printf(" Digite o código do departamento desejado: ");
            scanf("%d", &id);
            getchar();
            id -= 1001;

            FILE *file = fopen("RelatorioIndividualDepartamento.txt", "w");
            fprintf(file, "Código do departamento: %d\n", vetor[id]->dId+1001);
            fprintf(file, "Nome..................: %s\n", vetor[id]->dNome);
            fprintf(file, "Funcionarios..........: %i\n", quantidadeDeFuncionarios(vetor[id]->dNome));
            fprintf(file, "Folha de pagamento....: R$ %.2f\n", custoDepartamento(vetor[id]->dNome));
            fprintf(file, "Status................: %s\n", vetor[id]->dStatus);
            fprintf(file, "Data de cadastro......: %s\n", vetor[id]->dDataCadastro);

            printf("\nRelatório gerado com sucesso!");
            fclose(file);
            getch();
            cls();
            system("start RelatorioIndividualDepartamento.txt");

            break;
        case 2:
            ;
            FILE *txtFile = fopen("RelatorioGeralDepartamentos.txt", "w");
            fprintf(txtFile, "%-7s%-20s%-15s%-15s%-10s%-13s\n", "Id", "Nome", "Funcionarios", "Folha", "Status", "Data Cadastro");

            int i;
            for (i=0; i < quant; i++)
            {
                fprintf(txtFile, "%-7i%-20s%-15iR$ %-12.2f%-10s%-13s\n", vetor[i]->dId+1001, vetor[i]->dNome, quantidadeDeFuncionarios(vetor[i]->dNome), custoDepartamento(vetor[i]->dNome), vetor[i]->dStatus, vetor[i]->dDataCadastro);
            }

            printf("Relatório gerado com sucesso!");
            fclose(txtFile);
            getch();
            cls();
            system("start RelatorioGeralDepartamentos.txt");

            break;
        case 3:
            ;
            FILE *csvFile = fopen("RelatorioGeralDepartamentos.csv", "w");
            fprintf(csvFile, "%-7s;%-20s;%-15s;%-15s;%-10s;%-13s;\n", "Id", "Nome", "Funcionarios", "Folha", "Status", "Data Cadastro");

            int j;
            for (j=0; j < quant; j++)
            {
                fprintf(csvFile, "%-7i;%-20s;%-15i;R$ %-12.2f;%-10s;%-13s;\n", vetor[j]->dId+1001, vetor[j]->dNome, quantidadeDeFuncionarios(vetor[j]->dNome), custoDepartamento(vetor[j]->dNome), vetor[j]->dStatus, vetor[j]->dDataCadastro);
            }

            printf("Relatório gerado com sucesso!");
            fclose(csvFile);
            getch();
            cls();
            system("start RelatorioGeralDepartamentos.csv");

            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }
    while(opcao == 0);
}

int quantidadeDeFuncionarios(char departamento[])
{
    Funcionarios *lista[1000];
    int quantTotal = lerArquivo(lista);
    int count = 0;

    int i;
    for(i = 0; i < quantTotal; i++)
    {
        if(strcmp(lista[i]->fpermi,departamento) == 0 && strcmp(lista[i]->fAtivoInativo,"Ativo") == 0)
        {
            count++;
        }
    }

    return count;
}

float custoDepartamento(char departamento[])
{
    Funcionarios *lista[1000];
    int quantTotal = lerArquivo(lista);
    float custo = 0;

    int i;
    for(i = 0; i < quantTotal; i++)
    {
        if(strcmp(lista[i]->fpermi,departamento) == 0)
        {
            custo += lista[i]->fsalario;
        }
    }

    return custo;
}

void salvarDepartamentos(Departamento **vetor, int quant)
{
    FILE *file = fopen("dbdepartamentos.txt", "w");
    int i;

    if(file != NULL)
    {
        fprintf(file, "%d\n", quant);

        for(i=0; i < quant; i++)
        {
            fprintf(file,"%i,", vetor[i]->dId);
            fprintf(file,"%s,", vetor[i]->dNome);
            fprintf(file,"%s,", vetor[i]->dStatus);
            fprintf(file,"%s,\n", vetor[i]->dDataCadastro);
        }
        fclose(file);
    }
    else
    {
        printf("\nNão foi possível criar a base de dados dbDepartamentos!\n");
        getch();
    }
}

int lerDepartamentos(Departamento **vetor)
{
    FILE *file = fopen("dbdepartamentos.txt", "r");
    int quant = 0, i;

    Departamento *novo = malloc(sizeof(Departamento));

    char linha[256];

    if(file != NULL)
    {
        fscanf(file, "%d\n", &quant);

        for(i=0; i < quant; i++)
        {
            fgets(linha, 256, file);

            novo->dId = atoi(strtok(linha, ","));
            strcpy(novo->dNome,strtok(NULL, ","));
            strcpy(novo->dStatus,strtok(NULL, ","));
            strcpy(novo->dDataCadastro,strtok(NULL, ","));

            vetor[i] = novo;
            novo = malloc(sizeof(Departamento));
        }
        fclose(file);
    }
    else
    {
        printf("\nErro: Não foi possível abrir o banco de dados de departamentos\nFoi criado um novo banco de dados...!\n\n");
        FILE *file = fopen("dbdepartamentos.txt", "w");
        fprintf(file, "%d\n", quant);
        fclose(file);
    }
    return quant;
}

void telaDepartamentos()
{
    Departamento *vetorDepartamentos[100];

    int opcao, tam = 100, quant = 0;

    quant += lerDepartamentos(vetorDepartamentos);

    do
    {
        salvarDepartamentos(vetorDepartamentos,quant);

        cabecalho();
        printf("\n Departamentos\n");

        printf("\n [0]Voltar\n [1]Cadastrar\n [2]Consultar\n [3]Desativar\n [4]Relatórios\n\n Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
        case 0:
            return;
            break;
        case 1:
            quant += cadastrarDepartamento(vetorDepartamentos, quant, tam);
            break;
        case 2:
            consultarDepartamento(vetorDepartamentos, quant);
            printf("Pressione qualquer tecla para retornar...");
            getchar();
            break;
        case 3:
            deletarDepartamento(vetorDepartamentos,quant);
            break;
        case 4:
            relatorioDepartamento(vetorDepartamentos,quant);
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }
    while(opcao != 0);
}
