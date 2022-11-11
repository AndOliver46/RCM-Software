#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    char nome [40];
    char email[40];
    char endereco[50];
    char codigo[40];
    char cpfcnpj [25];
    char telefone [20];
    char status [9];
} Cliente;

void consultarCliente();
void telacadastro();
void Telaexclui();
void clientes();

#endif // CLIENTES_H_INCLUDED
