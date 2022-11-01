#include "bibliotecas.h"
#include "departamentos.h"
#include "auxiliares.h"

int cadastrarDepartamento(Departamento **vetor, int quant, int tam)
{
    cls();
    printf("----------------------------------------------------------------\n");
    printf("		Cadastrar departamento\n");
    printf("----------------------------------------------------------------\n");

    if(quant < tam)
    {
        //Aloca dinamicamente a mem�ria necess�ria para armazenar uma struct do tipo Departamento na vari�vel novo
        Departamento *novo = malloc(sizeof(Departamento));

        //Define que o Id do novo departamento vai ser o valor da quantidade de elementos na lista
        novo->dId = quant;

        //Fun��o alfabetico, verifica se foram digitados somente caracteres a-z A-Z e se n�o excedeu o limite estabelecido de caracteres (20)
        printf("Nome do novo departamento: ");
        strcpy(novo->dNome,alfabeticoLimite(19));
        strcpy(novo->dNome,maiusculo(novo->dNome));

        //Define o departamento cadastrado como ativo
        strcpy(novo->dStatus,"Ativo");

        //Cria a data de cadastro a partir da vari�vel global dataSistema
        strcpy(novo->dDataCadastro,dataAtual());

        //Insere a struct criada atrav�s dos dados inseridos no vetor de Structs passado como argumento
        vetor[quant] = novo;

        cls();
        printf("Departamento cadastrado com sucesso!\n\n");

        return 1;
    }
    else
    {
        cls();
        printf("\n\tImposs�vel realizar novo cadastro, lista de departamentos cheia!");

        return 0;
    }
}

void consultarDepartamento(Departamento **vetor, int quant)
{
    cls();

    printf("\n----------------------------------------------------------------------------------------------------------------\t\n");
    //Mostrar r�tulos e formato de colunas reservando espa�os para cada dado
    printf("%-7s%-20s%-10s%-13s\n", "Id", "Nome", "Status", "Data Cadastro");

    //Loop para percorrer toda a struct de departamentos mostrando cada um em uma linha
    int i;
    for (i=0; i < quant; i++)
    {
        printf("%-7i%-20s%-10s%-13s\n", vetor[i]->dId+1001, vetor[i]->dNome, vetor[i]->dStatus, vetor[i]->dDataCadastro);
    }
    printf("\n----------------------------------------------------------------------------------------------------------------\t\n");
}

void deletarDepartamento(Departamento **vetor, int quant)
{
    cls();

    //Mostra lista de departamentos para usuario identificar os Id's
    consultarDepartamento(vetor,quant);

    printf("----------------------------------------------------------------\n");
    printf("		Deletar registros\n");
    printf("----------------------------------------------------------------\n");

    int id;
    printf("\nDigite o Id do deparamento que deseja desativar: ");
    scanf("%d", &id);
    getchar();
    id -= 1001;

    //Verifica se o id existe, se existir altera o departamento para Inativo
    if(id >= 0 && id < quant)
    {
        //Alterando dado dStatus do departamento "id" para Inativo
        strcpy(vetor[id]->dStatus,"Inativo");

        printf("\nDepartamento desativado com sucesso!\n");
        getch();
    }
    else
    {
        printf("\nC�digo inv�lido!\n");
        getch();
    }

    cls();
}

void relatorioDepartamento(Departamento **vetor, int quant)
{
    int opcao = 0;

    do
    {
        cls();

        printf("\n----------------------------------------------------------------------------------------------------------------\t\n");
        //Mostrar r�tulos e formato de colunas reservando espa�os para cada dado
        printf("%-7s%-20s%-10s%-13s\n", "Id", "Nome", "Status", "Data Cadastro");

        //Loop para percorrer toda a struct de departamentos mostrando cada um em uma linha
        int i;
        for (i=0; i < quant; i++)
        {
            printf("%-7i%-20s%-10s%-13s\n", vetor[i]->dId+1001, vetor[i]->dNome, vetor[i]->dStatus, vetor[i]->dDataCadastro);
        }
        printf("\n----------------------------------------------------------------------------------------------------------------\t\n");

        printf("Qual tipo de relat�rio deseja exportar?\n\n[0]Voltar\n[1]Relat�rio individual (TXT)\n[2]Relat�rio geral (TXT)\n[3]Relat�rio geral (Excel)\n\nOp��o: ");
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
            printf("Digite o c�digo do departamento desejado: ");
            scanf("%d", &id);
            getchar();
            id -= 1001;

            FILE *file = fopen("Relatorio individual.txt", "w");
            fprintf(file, "C�digo do departamento: %d\n", vetor[id]->dId+1001);
            fprintf(file, "Nome..................: %s\n", vetor[id]->dNome);
            fprintf(file, "Status................: %s\n", vetor[id]->dStatus);
            fprintf(file, "Data de cadastro......: %s\n", vetor[id]->dDataCadastro);

            printf("Relat�rio gerado com sucesso!");
            fclose(file);
            getch();
            cls();

            break;
        case 2:
            ;
            FILE *txtFile = fopen("Relatorio geral.txt", "w");
            fprintf(txtFile, "%-7s%-20s%-10s%-13s\n", "Id", "Nome", "Status", "Data Cadastro");

            //Loop para percorrer toda a struct de departamentos mostrando cada um em uma linha
            int i;
            for (i=0; i < quant; i++)
            {
                fprintf(txtFile, "%-7i%-20s%-10s%-13s\n", vetor[i]->dId+1001, vetor[i]->dNome, vetor[i]->dStatus, vetor[i]->dDataCadastro);
            }

            printf("Relat�rio gerado com sucesso!");
            fclose(txtFile);
            getch();
            cls();
            break;
        case 3:
            ;
            FILE *csvFile = fopen("Relatorio geral.csv", "w");
            fprintf(csvFile, "%-7s;%-20s;%-10s;%-13s;\n", "Id", "Nome", "Status", "Data Cadastro");

            //Loop para percorrer toda a struct de departamentos mostrando cada um em uma linha
            int j;
            for (j=0; j < quant; j++)
            {
                fprintf(csvFile, "%-7i;%-20s;%-10s;%-13s;\n", vetor[j]->dId+1001, vetor[j]->dNome, vetor[j]->dStatus, vetor[j]->dDataCadastro);
            }

            printf("Relat�rio gerado com sucesso!");
            fclose(csvFile);
            getch();
            cls();
            break;
        default:
            printf("\nOp��o inv�lida!\n");
            break;
        }
    }
    while(opcao == 0);
}

void salvarDepartamentos(Departamento **vetor, int quant)
{
    //Abertura de arquivo em modo write
    FILE *file = fopen("dbdepartamentos.txt", "w");
    int i;

    if(file != NULL)
    {
        //Armazenar a quantidade de funcionarios na primeira linha do arquivo, para auxiliar na leitura posterior
        fprintf(file, "%d\n", quant);

        for(i=0; i < quant; i++)
        {
            //Inserir dados de cada struct que est� dentro do vetor no arquivo, com a formata��o separada por virgulas
            fprintf(file,"%i,%s,%s,%s,\n", vetor[i]->dId, vetor[i]->dNome, vetor[i]->dStatus, vetor[i]->dDataCadastro);
        }
        fclose(file);
    }
    else
    {
        printf("\nN�o foi poss�vel criar a base de dados dbDepartamentos!\n");
        getch();
    }
}

int lerDepartamentos(Departamento **vetor)
{
    //Abertura do arquivo em modo read
    FILE *file = fopen("dbdepartamentos.txt", "r");
    int quant = 0, i;

    //Aloca dinamicamente a mem�ria necess�ria para armazenar uma struct do tipo Departamento na vari�vel novo
    Departamento *novo = malloc(sizeof(Departamento));

    //Variavel preparada para receber conte�do da linha recebida do arquivo pela fun��o fgets abaixo
    char linha[256];

    if(file != NULL)
    {
        //Busca quantidade de funcionarios salvos no txt e joga na variavel quantidade
        fscanf(file, "%d\n", &quant);

        for(i=0; i < quant; i++)
        {
            //Fun��o para jogar conte�do da linha dentro da vari�vel linha
            fgets(linha, 256, file);

            novo->dId = atoi(strtok(linha, ","));
            strcpy(novo->dNome,strtok(NULL, ","));
            strcpy(novo->dStatus,strtok(NULL, ","));
            strcpy(novo->dDataCadastro,strtok(NULL, ","));

            //Salva novo departamento no vetor de departamentos na posi��o i
            vetor[i] = novo;

            //Realoca espa�o na mem�ria para receber os dados no pr�ximo loop
            novo = malloc(sizeof(Departamento));
        }
        fclose(file);
    }
    else
    {
        printf("\nErro: N�o foi poss�vel abrir o banco de dados de departamentos\nFoi criado um novo banco de dados...!\n\n");
        FILE *file = fopen("dbdepartamentos.txt", "w");
        fprintf(file, "%d\n", quant);
        fclose(file);
    }
    return quant;
}

void telaDepartamentos()
{
    //Cria um vetor do tipo Departamento para inser��o das structs e manipula��o dos dados dos departamentos.
    Departamento *vetorDepartamentos[100];

    //tam: Define quantos departamentos podem ser cadastrados para que n�o exceda o limite
    //quant: Define um valor inicial para a quantidade de departamentos cadastrados
    int opcao, tam = 100, quant = 0;

    //Ao in�cio da fun��o, busca os departamentos cadastrados no TXT e altera a quantidade incial de acordo com quandos departamentos existem no arquivo
    quant += lerDepartamentos(vetorDepartamentos);

    do
    {
        //Sempre que houver retorno ao menu departamentos, h� um salvamento dos dados
        salvarDepartamentos(vetorDepartamentos,quant);

        printf("----------------------------------------------------------------\n");
        printf("		M�dulo departamentos!\n");
        printf("----------------------------------------------------------------\n");

        printf("\n[0]Voltar\n[1]Cadastrar\n[2]Consultar\n[3]Desativar departamento\n[4]Relat�rios\n\nOp��o: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
        case 0:
            return;
            break;
        case 1:
            //Passa o vetor de departamentos como parametro para ser cadastrado o novo departamento, a fun��o retorna 1 (cadastrado) / 0 (Erro)
            quant += cadastrarDepartamento(vetorDepartamentos, quant, tam);
            break;
        case 2:
            consultarDepartamento(vetorDepartamentos, quant);
            break;
        case 3:
            deletarDepartamento(vetorDepartamentos,quant);
            break;
        case 4:
            relatorioDepartamento(vetorDepartamentos,quant);
            break;
        default:
            printf("\nOp��o inv�lida!\n");
            break;
        }
    }
    while(opcao != 0);
}
