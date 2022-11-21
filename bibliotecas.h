#ifndef BIBLIOTECAS_H_INCLUDED
#define BIBLIOTECAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

#define ESC 27
#define ENTER 13
#define BACKSPACE 8

#define CHAVE 2

#endif // BIBLIOTECAS_H_INCLUDED
