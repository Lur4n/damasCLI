#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#define TAM_MAX_LINHA 120

#include <iostream>
#include <clocale>
#include <string>
#include <unistd.h>

using namespace std;

/// AQUI ESTÃO MINHAS CORES DE FONTE
#define PRETO "\e[30m"
#define VERMELHO "\e[31m"
#define VERDE "\e[32m"
#define AMARELO "\e[33m"
#define AZUL "\e[34m"
#define ROXO "\e[35m"
#define CIANO "\e[36m"
#define BRANCO "\e[37m"
#include "bib_opcoes_Menu.h"

/// AQUI ESTÃO MINHAS CORES DE BACKROUND
#define BCIANO "\e[46m"
#define BAZUL "\e[44m"
#define BBRANCO "\e[47m"
#define BVERMELHO "\e[41m"
#define BAMARELO "\e[43m"


#define ESMAECER "\e[1m"
#define SUBLINHAR "\e[4m"
#define PISCAR "\e[5m"
#define NEGATIVO "\e[7m"
#define ITALICO "\e[3m"
#define TESTE "\bE ai mundo"

///PARADA(resetando o estilo) DA ESTILIZAÇÃO DA COR
#define NC "\e[0m"


void topo(string y);
void linha(char a, int b);
int funTabuleiro();
void menuPrincipal(int MAT[8][8]);

void jogo(int MAT[8][8]);
bool paridade(int a);

//void topo(string letras, int qtdLetras);

#endif // BIB_H_INCLUDED
