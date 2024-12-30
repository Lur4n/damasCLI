#ifndef BIB_OPCOES_MENU_H_INCLUDED
#define BIB_OPCOES_MENU_H_INCLUDED

static short LARGURA_MENU = 120;// 120 é o padrao da quantidade
// de caracteres em brancos na tela antes de quebrar linha.
// Rodei um for com a cor azul e quando quebrou a linha automaticamente
// vi o maximo de caracteres da saida

// 154 tela maximizada
// 120 tela padrao


void textos(string y, int x);


void linhaAzul(int b);
void linhaVermelha(int b);
void linhaCiano(int a);
void linha(char a, int b);
void MenuCentralizado(string a);
void topoMenu(string a, int b);
void opcoesMenuPrincipal(int MAT[8][8]);
void menuInferior();
void menuPrincipal();
void opcoesFunTabuleiro();

void jogo(int MAT[8][8]);

void centralize(string a);


#endif // BIB_OPCOES_MENU_H_INCLUDED
