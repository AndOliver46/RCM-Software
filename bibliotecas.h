#ifndef BIBLIOTECAS_H_INCLUDED
#define BIBLIOTECAS_H_INCLUDED

//bibliotecas do programa
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define RED2        "\x1b[31m"
#define RESET       "\x1b[0m"
#define RED         "\e[0;31m" //cores em ANSI utilizadas
#define GRAY        "\e[0;37m"
#define DARK_GRAY 	"\e[1;30m"
#define GREEN	    "\e[0;32m"
#define BLACK       "\e[0;30m"
#define YELLOW      "\e[0;33m"
#define BLUE        "\e[0;34m"
#define PURPLE      "\e[0;35m"
#define CYAN        "\e[0;36m"
#define WHITE       "\e[0;37m"
#define BG_GREEN    "\e[42m"
#define BG_BLUE     "\e[44m"
#define HWHITE      "\e[0;97m"
#define HRED        "\e[0;91m"

#define CHAVE 0

//funções auxiliares

char* dataAtual()
{
    char *dataSistema = (char*) malloc(11 * sizeof(char));

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    sprintf(dataSistema,"%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    return dataSistema;
}

char* maiusculo(char textoRecebido[])
{
    int tamanho = strlen(textoRecebido);
    char *textoMaiusculo = (char*) malloc(tamanho * sizeof(char));

    int i;
    for(i = 0; i < tamanho; i++)
    {
        textoMaiusculo[i] = toupper(textoRecebido[i]);
    }
    return textoMaiusculo;
}

int numerico(char variavel[])
{
    int i = 0;
    while(variavel[i] != '\0')
    {
        if(!(variavel[i] >= '0' && variavel[i] <= '9'))
        {
            printf("Digite apenas numeros\n");
            return 0;
            break;
        }
        ++i;
    }
    return 1;
}

int alfabeto(char variavel[])
{
    int i = 0;
    while(variavel[i] != '\0')
    {
        if(!((variavel[i] >= 'a' && variavel[i] <= 'z') || (variavel[i] >= 'A' && variavel[i] <= 'Z') || (variavel[i] == ' ')))
        {
            printf("Digite apenas letras e espacos\n");
            return 0;
            break;
        }
        ++i;
    }
    return 1;
}

char* alfabeticoLimite(int num)
{
    int i;
    char *texto = (char*) malloc(num * sizeof(char));

    int erro = 0;
    do
    {
        scanf("%s", texto);
        getchar();

        for(i = 0; i < strlen(texto); i++)
        {
            if((texto[i] >= 'a' && texto[i] <= 'z' || texto[i] >= 'A' && texto[i] <= 'Z') && (strlen(texto) <= num))
            {
                erro = 1;
            }
            else
            {
                printf("\nDigite somente letras, até %d caracteres: ", num);
                erro = 0;
                break;
            }
        }
    }
    while(erro == 0);

    return texto;
}

char* numericoLimite(int num)
{
    int i;
    char *texto = (char*) malloc(num * sizeof(char));

    int erro = 0;
    do
    {
        scanf("%s", texto);
        getchar();

        for(i = 0; i < strlen(texto); i++)
        {
            if((texto[i] >= '0' && texto[i] <= '9') && (strlen(texto) <= num))
            {
                erro = 1;
            }
            else
            {
                printf("\nDigite somente numeros, até %d caracteres: ", num);
                erro = 0;
                break;
            }
        }
    }
    while(erro == 0);

    return texto;
}

char* encriptarValor(char textoRecebido[])
{
    int tamanho = strlen(textoRecebido);
    char *textoEncriptado = (char*) malloc(tamanho * sizeof(char));

    int i;
    for(i = 0; i < tamanho; i++)
    {
        textoEncriptado[i] = textoRecebido[i] - CHAVE;
    }
    return textoEncriptado;
}

char* decriptarValor(char textoRecebido[])
{
    int tamanho = strlen(textoRecebido);
    char *textoDecriptado = (char*) malloc(tamanho * sizeof(char));

    int i;
    for(i = 0; i < tamanho; i++)
    {
        textoDecriptado[i] = textoRecebido[i] - CHAVE;
    }
    return textoDecriptado;
}

void cls(void)
{
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, TEXT(' '),
                               dwConSize, coordScreen, &cCharsWritten);

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
                               dwConSize, coordScreen, &cCharsWritten);

    SetConsoleCursorPosition(hConsole, coordScreen);
}

#endif // BIBLIOTECAS_H_INCLUDED
