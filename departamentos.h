#ifndef DEPARTAMENTOS_H_INCLUDED
#define DEPARTAMENTOS_H_INCLUDED

typedef struct
{
    int dId;
    char dNome[20], dStatus[10], dDataCadastro[11];
} Departamento;

int cadastrarDepartamento(Departamento **vetor, int quant, int tam);
void consultarDepartamento(Departamento **vetor, int quant);
void deletarDepartamento(Departamento **vetor, int quant);
void relatorioDepartamento(Departamento **vetor, int quant);
int quantidadeDeFuncionarios(char departamento[]);
void salvarDepartamentos(Departamento **vetor, int quant);
int lerDepartamentos(Departamento **vetor);
void telaDepartamentos();

#endif // DEPARTAMENTOS_H_INCLUDED
