#ifndef AUXILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED

void cabecalho();
char* dataAtual();
char* maiusculo(char textoRecebido[]);
int numerico(char variavel[]);
int alfabeto(char variavel[]);
char* alfabeticoLimite(int num);
char* numericoLimite(int num);
char* encriptarValor(char textoRecebido[]);
char* decriptarValor(char textoRecebido[]);
void cls(void);

#endif // AUXILIARES_H_INCLUDED
