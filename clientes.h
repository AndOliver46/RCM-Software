#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
    {
        char nome [40];
        char email[40];
        char cpfcnpj [15];
        char telefone [11];

    }Cliente;
    Cliente ctt;

void consultarCliente()
{
    system("cls");
    printf("\n----------------------------------------------------------------------------------------------------------------\t\n");


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
            printf("\n\n****************************************************************\n");
            printf("Nome: %s\n", ctt.nome);
            printf("Cpf/Cnpj: %s\n", ctt.cpfcnpj);
            printf("Email: %s\n", ctt.email);
            printf("Telefone: %s\n", ctt.telefone);
         }
         else {

                printf ("Cpf/Cnpj não encontrado\n");

         }
        }
          fclose(arquivo);
         // getch();

    }
    printf("\n----------------------------------------------------------------------------------------------------------------\t\n");
    system ("pause");
}



void telacadastro()
{
    system ("cls");

    FILE *arquivo;
    arquivo = fopen("cadastro.txt", "ab");

    if (arquivo == NULL)
    {
        printf("Arquivo não encontrado");
    }
    else {


            printf("\n--------Cadastro de Cliente--------\n\n\n");

            fflush(stdin);
            printf("Digite o nome completo.....: ");
            scanf("%40[^\n]",ctt.nome);
            getchar();

            fflush(stdin);
            printf("Digite o numero de cpf/cnpj: ");
            scanf("%s", ctt.cpfcnpj);
            getchar();

            fflush(stdin);
            printf("Digite o numero de telefone..: ");
            scanf("%s",ctt.telefone);
            getchar();

            fflush(stdin);
            printf("Digite o email.............: ");
            scanf("%s",ctt.email);
            getchar();

            printf("\n\nCadastro realizado com sucesso!\n\n");
            system ("pause");

            fwrite(&ctt,sizeof(Cliente),1,arquivo);

           } fclose(arquivo);
}
void Telaexclui()
{
    system ("cls");

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
            printf("\n\n****************************************************************\n");
            printf("Nome: %s\n", ctt.nome);
            printf("Cpf/Cnpj: %s\n", ctt.cpfcnpj);
            printf("email: %s\n",ctt.email);
            printf("\nTelefone: %s\n\n", ctt.telefone);

            printf("Você tem certeza que deseja excluir esse clente? (1-Sim / 2-Não) ");
            scanf("%d", &opcao);
            getchar();

            if (opcao == 2)
            {
                fwrite(&ctt, sizeof(Cliente),1,arqTem);
                printf("OPERAÇÃO CANCELADA!");
            }
            else
            {
                printf("\nCADASTRO EXCLUÍDO COM SUCESSO!\n");
            }

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

void clientes()
{
    setlocale(LC_ALL, "Portuguese");
    system("color f1");
    system ("cls");

    int opcao;

    while (opcao != 4)
    {
    system ("cls");

    printf("       Tela de Clientes");
    printf("\n\nSelecione uma opção válida e tecle enter:");
    printf("\n\n(1)Consulta\n(2)Cadastro\n(3)Excluir\n(4)Menu Principal");

    printf("\n\nOpção:");
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
        return;
        break;
    }
    }

}

#endif // CLIENTES_H_INCLUDED
