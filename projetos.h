#ifndef PROJETOS_H_INCLUDED
#define PROJETOS_H_INCLUDED

typedef struct //Aqui temos a definição da Struct. Uma vez definida, podemos declarar qualquer
//variável com ela(struct cadastro cliente ou struct cadastro funcionario)
{
    char titulo[30], linguagem[25], cpf[15],descricao[120], projetoN[5], cliente[40],status[15],tPag[12];
    int inicio[3], previsao[3],conclusao[3];
    float valor, fPag;
} Projeto;

void telaProjetos();
void cadProjeto();
void statusA();
void statusP();
void statusC();
void projRelatorio();
void consultaProj();
void chamaCliente();
void telaAtualiza();


#endif // PROJETOS_H_INCLUDED
