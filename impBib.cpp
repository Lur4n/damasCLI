#include "bib.h"
#include "bib_opcoes_Menu.h"


/// OPS DE DESIGN

void linhaCiano(int b){
    cout <<  BCIANO;
    for(int i=0; i<b; i++){
        cout << " ";

    }
    usleep(1000);
    cout << NC;
}

void linhaVermelha(int b){
    cout <<  BVERMELHO;
    for(int i=0; i<b; i++){
        cout << " ";

    }
    usleep(1000);
    cout << NC;
}
void linhaAzul(int b){ // FUNCÃO QUE PREENCHE OS ESPAÇOS COM AZUL
    cout <<  BAZUL;
    for(int i=0; i<b; i++){
        cout << " ";
    }
    usleep(1000);
    cout << NC;
}


void linha(char a, int tamLoop){
    int conversao = tamLoop*9;
//    tamLoop=tamLoop/2;
    for(int i=0; i<tamLoop; i++){
        cout << a;
//        usleep(conversao);
    }
//    usleep(1000);
}
void topo(string texto){
    int aux;
    aux = texto.length();

    if(aux%2==0){
        linhaVermelha(LARGURA_MENU);
        cout << endl;
        linhaVermelha(LARGURA_MENU/2 - texto.length()/2);
        cout << BVERMELHO ESMAECER << texto << NC;
        linhaVermelha(LARGURA_MENU/2 - texto.length()/2);
        cout << endl;
        cout << SUBLINHAR AMARELO ESMAECER;
        linhaVermelha(LARGURA_MENU);
    }else{
        linhaVermelha(LARGURA_MENU);
        cout << endl;
        linhaVermelha(LARGURA_MENU/2 - texto.length()/2);
        cout << PISCAR << texto << NC;
        linhaVermelha(LARGURA_MENU/2 - texto.length()/2-1);
        cout << endl;
        cout << SUBLINHAR AMARELO ESMAECER;
        linhaVermelha(LARGURA_MENU);
    }
    cout << endl;
}

int funTabuleiro(){ //ESSA FUNCAO MOSTRA O TABULEIRO
//    cout << endl;
    int tabuleiro[8][8];
    usleep(140000);
    for(int i=0; i<8; i++){
        linha(' ', LARGURA_MENU/2-15);
        for(int j=0; j<8; j++){
            if((i+j)% 2 == 0){// AQUI É O PREENCHIMENTO DAS PARTES BRANCAS DO TABULEIRO
                if(i==3 || i==4 ){
                    cout << BBRANCO "   " NC;
                }else if(i<3){
                    cout <<  BBRANCO PRETO" 0 "NC  NC;
                }else{
                    cout << BBRANCO PRETO " O " NC NC;
                }
            }else{// AQUI É O PREENCHIMENTO DAS PARTES VAZIAS DO TABULEIRO
                if(i==3 || i==4){
                    cout <<  BCIANO "   " NC;
                }else{
                    cout <<  BCIANO "   " NC;
                }
            }
            usleep(2000);
            if(j<7){
                cout << AMARELO "|" NC;
            }
        }
        cout << endl;
        linha(' ', LARGURA_MENU/2-15);
        cout << AMARELO;
        linha('-', 31);
        cout << NC << endl;
    }
    cout << endl;
    void opcoesFunTabuleiro();
}




//Funcao gerenciadora do menu
void menuPrincipal(int mat[8][8]){
    MenuCentralizado("MAIN MENU"); /// CORES E ESPAÇAMENTOS
    cout << endl;
    funTabuleiro();
    opcoesMenuPrincipal(mat);

    //menuInferior();
}

