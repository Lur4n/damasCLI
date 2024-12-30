#include "bib.h"
#include "bib_opcoes_Menu.h"

#define tam_vet 8

bool paridade(int a){
    return (a)%2==0;
}

void tabuleiro_Organizado(int mat[8][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(paridade(i+j)&&i<3){ // Brancas
                mat[i][j] = 1;
            }else if(paridade(i+j)&&i>4){ // Brancas
                mat[i][j] = 0;
            }else if(paridade(i+j)&&(i>2&&i<5)){  // Brancas
                mat[i][j] = 2;
            }else{ //Azuis
                mat[i][j] = 3;
            }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");



    int matriz[8][8];
    tabuleiro_Organizado(matriz);
    menuPrincipal(matriz);
//    jogo(matriz);



}
