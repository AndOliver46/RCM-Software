#ifndef FUNCIONARIOS_H_INCLUDED
#define FUNCIONARIOS_H_INCLUDED

#include "menuprincipal.h"
#include "bibliotecas.h"
#include "departamentos.h"

//Alterado por anderson

typedef struct
{
    char flogin[50], fNome[50], fSenha[30], fAtivoInativo[8],fpermi[10], fCpf[12], fCep[12], fTelefone[12], fCargo[30], fDataCadastro[11];
    int fCod;
    float fsalario;
} Funcionarios;

void exportar(Funcionarios **f, int quant)
{
    int escolhaExp, i;

    printf("----------Exportacao----------\n");
    printf("[1]Sim\n[2]Nao\nGostaria de exportar: ");
    scanf("%i", &escolhaExp);
    getchar();
    if(escolhaExp == 1)
    {
        FILE *exportar = fopen("Consulta.csv", "w");

        fprintf(exportar,"Num;Nome;Ativo//Inativo;CPF;Cep;Telefone;Cargo;Data Cadastro\n");

        for (i=0; i < quant; i++)
        {
            fprintf(exportar, "%i;%s;%s;%s;%s;%s;%s;%s;%s;\n", i+1, f[i]->fNome, f[i]->fAtivoInativo, f[i]->fCpf, f[i]->fCep, f[i]->fTelefone, f[i]->fCargo, f[i]->fDataCadastro);
        }

        fclose(exportar);

        system("cls");
        printf("Exportacao concluida.\n");
        system("pause");
    }
}

int lerArquivo(Funcionarios **f)
{
    FILE *file = fopen("dbfuncionarios.txt", "r");
    int quant = 0;
    int i;
    char linha[1000];
    Funcionarios *novo = malloc(sizeof(Funcionarios));

    if(file)
    {
        fscanf(file, "%d\n", &quant);
        for(i = 0; i < quant; i++)
        {
            fgets(linha, 1000, file);
            novo->fCod = atoi(strtok(linha,";"));
            strcpy(novo->fNome,strtok(NULL, ";"));
            strcpy(novo->flogin,strtok(NULL, ";"));
            strcpy(novo->fSenha,strtok(NULL, ";"));
            strcpy(novo->fAtivoInativo,strtok(NULL, ";"));
            strcpy(novo->fpermi,strtok(NULL, ";"));
            strcpy(novo->fCpf,strtok(NULL, ";"));
            strcpy(novo->fCep,strtok(NULL, ";"));
            strcpy(novo->fTelefone,strtok(NULL, ";"));
            strcpy(novo->fCargo,strtok(NULL, ";"));
            novo->fsalario = atoi(strtok(NULL,";"));
            strcpy(novo->fDataCadastro,strtok(NULL, ";"));
            f[i] = novo;
            novo = malloc(sizeof(Funcionarios));
        }
        fclose(file);
    }
    else
    {
        printf("Arquivo nao encontrado.");
    }



    return quant;
}

void consultarFuncionarios(Funcionarios **f, int quant)
{
    int i;

    printf("\n\nLista de colaboradores:\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("%-7s%-35s%-15s%-12s%-15s%-20s%-14s\n", "Num", "Nome", "CPF", "Cep", "Telefone", "Cargo", "Data cadastro");

    for (i=0; i < quant; i++)
    {
        if(strcmp(f[i]->fAtivoInativo,"Ativo") == 0)
        {
            printf("%-7i%-35s%-15s%-12s%-15s%-20s%-14s\n", i+1, f[i]->fNome, f[i]->fCpf, f[i]->fCep, f[i]->fTelefone, f[i]->fCargo, f[i]->fDataCadastro);
        }
    }

    printf("---------------------------------------------------------------------------------------------------------------------\n\n");
}

int fDeletar(Funcionarios **f, int quant)
{
    int id;

    consultarFuncionarios(f, quant);

    printf("Digite o Id de funcionário que deseja excluir: ");
    scanf("%i", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant)
    {
        strcpy(f[id]->fAtivoInativo,"Inativo");

        printf("\nFuncionario deletado com sucesso!\n");
        system("pause");
    }
    else
    {
        printf("---------Codigo invalido---------\n");
        system("pause");
    }
    return 1;
}

int fCadastrar(Funcionarios **f, int quant)
{
    Funcionarios *novo = malloc(sizeof(Funcionarios));

    system("cls");

    novo->fCod = quant + 1;

    do
    {
        printf("Nome completo: ");
        scanf("%50[^\n]", novo->fNome);
        getchar();
    }
    while(alfabeto(novo->fNome) != 1);

    printf("Login: ");
    scanf("%s", novo->flogin);
    getchar();

    printf("Senha: ");
    scanf("%s", novo->fSenha);
    getchar();

    strcpy(novo->fAtivoInativo, "Ativo");

    //Cria um vetor do tipo Departamento para inserção das structs e manipulação dos dados dos departamentos.
    Departamento *vetorDepartamentos[100];
    //quantDepar: Define um valor inicial para a quantidade de departamentos cadastrados
    int i, quantDepar = 0;
    int compare = 0;

    quantDepar += lerDepartamentos(vetorDepartamentos);

    do
    {
        printf("Departamento: ");
        scanf("%s", novo->fpermi);
        getchar();
        strcpy(novo->fpermi,maiusculo(novo->fpermi));

        for (i=0; i < quantDepar; i++)
        {
            if(strcmp(novo->fpermi, vetorDepartamentos[i]->dNome) == 0 && strcmp(vetorDepartamentos[i]->dStatus, "Ativo") == 0)
            {
                compare = 1;
                break;
            }
        }

        if(compare == 0)
        {
            printf("Departamento inexistente ou inativo\n");
        }
    }
    while(compare != 1);


    do
    {
        printf("CPF: ");
        scanf("%s", novo->fCpf);
        getchar();
    }
    while(numerico(novo->fCpf) != 1);

    do
    {
        printf("CEP: ");
        scanf("%s", novo->fCep);
        getchar();
    }
    while(numerico(novo->fCep) != 1);

    do
    {
        printf("Telefone (DDD+Numero): ");
        scanf("%s", novo->fTelefone);
        getchar();
    }
    while(numerico(novo->fTelefone) != 1);

    printf("Cargo: ");
    scanf("%30[^\n]", novo->fCargo);
    getchar();

    printf("Salario: ");
    scanf("%f", &novo->fsalario);
    getchar();

    strcpy(novo->fDataCadastro, dataAtual());

    system("pause");

    f[quant] = novo;

    return 1;
}

void fAtualizar(Funcionarios **f, int quant)
{

    int id, escolhaatt;

    consultarFuncionarios(f, quant);

    printf("Digite o ID do funcionário que deseja alterar: ");
    scanf("%i", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant)
    {
        Funcionarios *novo = malloc(sizeof(Funcionarios));

        novo = f[id];

        printf("\tO que deseja alterar ?\t\n");
        printf("[1]Nome\n[2]Senha\n[3]Departamento\n[4]CPF\n[5]CEP\n[6]Telefone\n[7]Cargo\n[8]Salario\n");
        scanf("%i", &escolhaatt);
        getchar();

        switch(escolhaatt)
        {
        case 1:
            do
            {
                printf("Nome completo: ");
                scanf("%50[^\n]", novo->fNome);
                getchar();
            }
            while(alfabeto(novo->fNome) != 1);
            break;
        case 2:
            printf("Senha: ");
            scanf("%s", novo->fSenha);
            getchar();
            break;
        case 3:
            ;
            //Cria um vetor do tipo Departamento para inserção das structs e manipulação dos dados dos departamentos.
            Departamento *vetorDepartamentos[100];
            //quantDepar: Define um valor inicial para a quantidade de departamentos cadastrados
            int i, quantDepar = 0;
            int compare = 0;

            quantDepar += lerDepartamentos(vetorDepartamentos);

            do
            {
                printf("Departamento: ");
                scanf("%s", novo->fpermi);
                getchar();
                strcpy(novo->fpermi,maiusculo(novo->fpermi));

                int i;
                for (i=0; i < quantDepar; i++)
                {
                    if(strcmp(novo->fpermi, vetorDepartamentos[i]->dNome) == 0 && strcmp(vetorDepartamentos[i]->dStatus, "Ativo") == 0)
                    {
                        compare = 1;
                        break;
                    }
                }

                if(compare == 0)
                {
                    printf("Departamento invalido\n");
                }
            }
            while(compare != 1);
            break;
        case 4:
            do
            {
                printf("CPF: ");
                scanf("%s", novo->fCpf);
                getchar();
            }
            while(numerico(novo->fCpf) != 1);
            break;

        case 5:
            do
            {
                printf("CEP: ");
                scanf("%s", novo->fCep);
                getchar();
            }
            while(numerico(novo->fCep) != 1);
            break;
        case 6:
            do
            {
                printf("Telefone (DDD+Numero): ");
                scanf("%s", novo->fTelefone);
                getchar();
            }
            while(numerico(novo->fTelefone) != 1);
            break;
        case 7:
            printf("Cargo: ");
            scanf("%30[^\n]", novo->fCargo);
            getchar();
            break;
        case 8:
            printf("Salario: ");
            scanf("%f", &novo->fsalario);
            getchar();
            break;
        default:
            printf("Digite uma opcao valida.");
            break;
        }

        f[id] = novo;
    }
    else
    {
        printf("Codigo invalido");
    }


}

void salvarCadastro(Funcionarios **f, int quant)
{
    FILE *file = fopen("dbfuncionarios.txt", "w");

    int i;
    fprintf(file, "%d\n", quant);
    for(i=0; i < quant; i++)
    {
        fprintf(file, "%i;%s;%s;%s;%s;%s;%s;%s;%s;%s;%.2f;%s;\n", f[i]->fCod, f[i]->fNome, f[i]->flogin, f[i]->fSenha, f[i]->fAtivoInativo,f[i]->fpermi, f[i]->fCpf, f[i]->fCep, f[i]->fTelefone, f[i]->fCargo, f[i]->fsalario,f[i]->fDataCadastro);
    }
    fclose(file);
}

void fRelatorio(Funcionarios **f, int quant)
{
    FILE *file;

    char nome_arquivo[50];
    char nome[50];

    int id;

    consultarFuncionarios(f, quant);

    printf("\n\nDigite o ID do funcionário: ");
    scanf("%i", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant)
    {
        Funcionarios *novo = malloc(sizeof(Funcionarios));

        novo = f[id];

        strcpy(nome, novo->fNome);

        strcpy(nome_arquivo, strcat(nome, "_Relatorio Individual.txt"));

        char charsalario[9];

        file = fopen(nome_arquivo, "w");


        fprintf(file,novo->fNome);
        fprintf(file,"\n\nNome.......................: ");
        fprintf(file,novo->fNome);
        fprintf(file,"\nDepartamento...............: ");
        fprintf(file,novo->fpermi);
        fprintf(file,"\nCPF........................: ");
        fprintf(file,novo->fCpf);
        fprintf(file,"\nCEP........................: ");
        fprintf(file,novo->fCep);
        fprintf(file,"\nTelefone...................: ");
        fprintf(file,novo->fTelefone);
        fprintf(file,"\nCargo......................: ");
        fprintf(file,novo->fCargo);
        fprintf(file,"\nSalario....................: ");
        sprintf(charsalario, "%.2f", novo->fsalario);
        fprintf(file,charsalario);
        fprintf(file,"\nData de cadastro no sistema: ");
        fprintf(file,novo->fDataCadastro);

        fclose(file);

        printf("\nRelatorio gerado com sucesso!\n");
        system("pause");

    }
    else
    {
        printf("Nao foi possivel gerar o relatorio.\n");
        system("pause");
    }
}

void telaFuncionarios()
{
    Funcionarios *lista[1000];
    int quant = lerArquivo(lista);
    int fEscolha;

    do
    {
        salvarCadastro(lista, quant);

        system("cls");
        printf("----------------------------\n");
        printf("    FUNCIONARIOS\n");
        printf("----------------------------\n");
        printf("[0]Sair\n[1]Cadastrar funcionario\n[2]Atualizar cadastro\n[3]Deletar cadastro\n[4]Consultar\n[5]Gerar Relatorio\n");
        printf("----------------------------\n");


        printf("Digite uma opcao: ");
        scanf("%i", &fEscolha);
        getchar();


        switch(fEscolha)
        {
        case 0:
            return;
            break;
        case 1:
            quant += fCadastrar(lista, quant);
            break;
        case 2:
            fAtualizar(lista, quant);
            break;
        case 3:
            fDeletar(lista, quant);
            break;
        case 4:
            consultarFuncionarios(lista, quant);
            exportar(lista, quant);
            break;
        case 5:
            fRelatorio(lista, quant);
            break;
        default:
            printf("Opção inválida");
            break;
        }
    }
    while(fEscolha != 0);
}

#endif // FUNCIONARIOS_H_INCLUDED
