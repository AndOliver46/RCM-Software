#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    char nome [40];
    char email[40];
    char cpfcnpj [15];
    char telefone [11];

} Cliente;

void consultarCliente();
void telacadastro();
void Telaexclui();
void clientes();

#endif // CLIENTES_H_INCLUDED
