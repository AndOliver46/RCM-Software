#include "bibliotecas.h"
#include "funcionarios.h"
#include "departamentos.h"
#include "auxiliares.h"

void exportar(Funcionarios **f, int quant)
{
    int escolhaExp, i;

    printf(" Exportacao\n\n");
    printf(" [1]Sim\n [2]Nao\n \n Gostaria de exportar? ");
    scanf("%i", &escolhaExp);
    getchar();
    if(escolhaExp == 1)
    {
        FILE *exportar = fopen("Consulta.csv", "w");

        fprintf(exportar,"Num;Nome;Ativo/Inativo;Departamento;CPF;Cep;Telefone;Cargo;Salario;Data Cadastro\n");

        for (i=0; i < quant; i++)
        {
            fprintf(exportar, "%i;%s;%s;%s;%s;%s;%s;%s;%f;%s;\n", i+1, f[i]->fNome, f[i]->fAtivoInativo, f[i]->fpermi, f[i]->fCpf, f[i]->fCep, f[i]->fTelefone, f[i]->fCargo, f[i]->fsalario, f[i]->fDataCadastro);
        }

        fclose(exportar);
        system("start Consulta.csv");

        system("cls");
        printf("Exportacao concluida.\n");
        getch();
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
    system("cls");
    cabecalho();

    printf("\nLista de colaboradores:\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("%-7s%-35s%-15s%-12s%-15s%-20s%-14s\n", "Num", "Nome", "CPF", "Cep", "Telefone", "Cargo", "Ativo/Inativo");

    for (i=0; i < quant; i++)
    {
        printf("%-7i%-35s%-15s%-12s%-15s%-20s%-14s\n", i+1, f[i]->fNome, f[i]->fCpf, f[i]->fCep, f[i]->fTelefone, f[i]->fCargo, f[i]->fAtivoInativo);
    }

    printf("---------------------------------------------------------------------------------------------------------------------\n\n");
}

int fDeletar(Funcionarios **f, int quant)
{
    int id;

    consultarFuncionarios(f, quant);

    printf("Digite o Id de funcion�rio que deseja excluir: ");
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
    cabecalho();

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

    Departamento *vetorDepartamentos[100];
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
            printf("Departamento inexistente ou inativo (Pressione qualquer tecla para continuar ou 'Esc' para retornar ao menu)");
            int op = getch();
            printf("\n");
            if(op == ESC)
            {
                return 0;
            }
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

    printf("Digite o ID do funcion�rio que deseja alterar: ");
    scanf("%i", &id);
    getchar();
    id--;

    if(id >= 0 && id < quant)
    {
        Funcionarios *novo = malloc(sizeof(Funcionarios));

        novo = f[id];

        printf("\n O que deseja alterar ?\n\n");
        printf("\n [1]Nome\n [2]Senha\n [3]Departamento\n [4]CPF\n [5]CEP\n [6]Telefone\n [7]Cargo\n [8]Salario\n Op��o: ");
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
            Departamento *vetorDepartamentos[100];
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
                    printf("Departamento inexistente ou inativo (Pressione qualquer tecla para continuar ou 'Esc' para retornar ao menu)");
                    int op = getch();
                    printf("\n");
                    if(op == ESC)
                    {
                        return;
                    }
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
        getch();
    }


}

void salvarCadastro(Funcionarios **f, int quant)
{
    FILE *file = fopen("dbfuncionarios.txt", "w");

    int i;
    fprintf(file, "%d\n", quant);
    for(i=0; i < quant; i++)
    {
        fprintf(file, "%i;%s;%s;%s;%s;%s;%s;%s;%s;%s;%.2f;%s;\n", f[i]->fCod, f[i]->fNome, f[i]->flogin, f[i]->fSenha, f[i]->fAtivoInativo,f[i]->fpermi, f[i]->fCpf, f[i]->fCep, f[i]->fTelefone, f[i]->fCargo, f[i]->fsalario, f[i]->fDataCadastro);
    }
    fclose(file);
}

void fRelatorio(Funcionarios **f, int quant)
{
    FILE *file;

    char nome_arquivo[50];
    char nome[50];

    int id;

    system("cls");
    consultarFuncionarios(f, quant);

    printf("\n Digite o ID do funcion�rio: ");
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
        getch();

    }
    else
    {
        printf("Nao foi possivel gerar o relatorio.\n");
        getch();
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
        cabecalho();

        printf("\n Funcion�rios\n\n");

        printf(" [0]Sair\n [1]Cadastrar\n [2]Atualizar\n [3]Deletar\n [4]Consultar\n [5]Gerar relat�rio\n");

        printf("\n Opc�o: ");
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
            printf("Op��o inv�lida");
            break;
        }
    }
    while(fEscolha != 0);
}
