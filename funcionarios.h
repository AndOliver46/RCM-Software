#ifndef FUNCIONARIOS_H_INCLUDED
#define FUNCIONARIOS_H_INCLUDED

typedef struct
{
    char flogin[50], fNome[50], fSenha[30], fAtivoInativo[8],fpermi[10], fCpf[12], fCep[12], fTelefone[12], fCargo[30], fDataCadastro[11];
    int fCod;
    float fsalario;
} Funcionarios;

void exportar(Funcionarios **f, int quant);
int lerArquivo(Funcionarios **f);
void consultarFuncionarios(Funcionarios **f, int quant);
int fDeletar(Funcionarios **f, int quant);
int fCadastrar(Funcionarios **f, int quant);
void fAtualizar(Funcionarios **f, int quant);
void salvarCadastro(Funcionarios **f, int quant);
void fRelatorio(Funcionarios **f, int quant);
void telaFuncionarios();

#endif // FUNCIONARIOS_H_INCLUDED
