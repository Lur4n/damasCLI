#include "bib.h"
#include "bib_opcoes_Menu.h"

void funTabuleiroJogadas(int mat[8][8]){
    linha(' ', LARGURA_MENU/2-17);
    for(int i=0; i<8; i++)cout << VERMELHO "   " << i+1 << NC;
    cout << endl;

    for(int i=0; i<8; i++){
        linha(' ', LARGURA_MENU/2-17);
        cout << VERMELHO << i+1 << " " NC;
        for(int j=0; j<8; j++){
            if((i+j)% 2 == 0){// AQUI É O PREENCHIMENTO DAS PARTES BRANCAS DO TABULEIRO
                if(mat[i][j] == 0){
                    cout << BBRANCO PRETO " X " NC;
                }else if(mat[i][j] == 1){
                    cout << BBRANCO PRETO " 0 " NC;
                }else if(mat[i][j] == 3){
                    cout << BCIANO " 0 " NC;
                }else if(mat[i][j] == 4){
                    cout << BCIANO " X " NC;
                }else{
                    cout << BBRANCO PRETO "   " NC;
                }
            }else{// AQUI É O PREENCHIMENTO DAS PARTES AZUIS DO TABULEIRO
                cout <<  BAZUL "   " NC;
            }
            if(j<7){
                cout << AMARELO "|" NC;
            }
        }
        cout << VERMELHO " " << i+1 << NC;
        cout << endl;
        linha(' ', LARGURA_MENU/2-15);
        cout << AMARELO;
        linha('-', 31);
        cout << NC << endl;

    }
    linha(' ', LARGURA_MENU/2-17);
    for(int i=0; i<8; i++){
        cout << VERMELHO "   " << i+1 << NC;
    }
    cout << endl;
    cout << endl;

}
void exemploPeca(char a){
    linhaCiano(1);
    cout << BCIANO<< a;
    linhaCiano(1);
}
void movimento(int a, int b, int valor,int mat[8][8]){
    if((a+b)%2==0){
        mat[a][b] = valor;
    }else{
        cout << "O MOVIMENTO NAO PODE SER REALIZADO\n";
        system("Pause");
    }
}

void movimentar(int li, int col, int liDestino,int colDestino, int mat[8][8]){
    movimento(liDestino-1, colDestino-1, mat[li-1][col-1], mat);
    movimento(li-1, col-1, 2, mat);
}

void topoGame(int i, int j){
    linhaCiano(LARGURA_MENU);
    string texto = "CASA SELECIONADA:";
    linhaCiano(LARGURA_MENU/2-(texto.length()/2)-3);
    cout << BCIANO << texto <<  " [" << i << "][" << j << "]";
    linhaCiano(LARGURA_MENU/2-(texto.length()/2)-5);
    cout << SUBLINHAR PRETO;
    linhaCiano(LARGURA_MENU);
    cout << endl;
    cout << endl;
}

void comendoPecaBaixoDireita(int l, int c, int lDest, int cDest, int mat[8][8]){
    system("cls");
    topoGame(lDest, cDest);
    movimentar(l, c, lDest, cDest, mat);
    funTabuleiroJogadas(mat);
    linha(' ',LARGURA_MENU/2-15);
    movimentar(lDest, cDest, lDest+1, cDest+1, mat);
    cout << "MOVIMENTANDO";
    usleep(700000);
}
void comendoPecaBaixoEsquerda(int l, int c, int lDest, int cDest, int mat[8][8]){
    system("cls");
    topoGame(lDest, cDest);
    movimentar(l, c, lDest, cDest, mat);
    funTabuleiroJogadas(mat);
    linha(' ',LARGURA_MENU/2-15);
    movimentar(lDest, cDest, lDest+1, cDest-1, mat);
    cout << "MOVIMENTANDO";
    usleep(700000);
}
void entrada(int &li, int &col){
    cout << "EXEMPLO DA ENTRADA: ";
    string exemplo[3]={"LIN"," ","COL"};usleep(70000);
    for(int i=0;i<3;i++){cout<<exemplo[i];usleep(70000);}
    cout<<endl;
    linha(' ',LARGURA_MENU/2-13);
    cout<<"-> ";
    cin >> li;
    linha(' ',LARGURA_MENU/2-13);
    cout<<"-> ";
    cin >> col;
    linha(' ',LARGURA_MENU/2-15);

}


void jogo(int mat[8][8]){
    int contador = 0, contador2 = 0, li=0, col=0, colDestino, liDestino;
    bool coordenadaVazia = false, flagSaida = false;
    char resp = 0;

    do{
        system("cls");
        topoGame(li, col);
        funTabuleiroJogadas(mat);
        if(coordenadaVazia==false){ // CASO INFORME UMA COORDENADA VAZIA
            linha(' ',LARGURA_MENU/2-13);
//            cout << "INFORME A :   ";
            entrada(li, col);
            if(mat[li-1][col-1]<2){ // RESTRINGE PARA ID DE PECA 0 = "x", 1 = "o"
                if(mat[li-1][col-1]==1){ // SE O QUE TA DENTRO DA MATRIZ = ID DA PEÇA "o"
                    mat[li-1][col-1]=3; // ALTERA A ID DA PEÇA "o" PARA SELECIONADA(COR CIANO)
                    system("cls");topoGame(li,col);funTabuleiroJogadas(mat);
                    mat[li-1][col-1]=1; // FAÇO RESET DA ID DA PEÇA

                    linha(' ',LARGURA_MENU/2-13);
                    entrada(liDestino, colDestino);

                    if(li<liDestino&&colDestino!=col){ // NAO AZUL, NAO MESMA LINHA, NA0 RETROCEDER
                        system("cls");
                        topoGame(liDestino, colDestino);
                        if(paridade(liDestino+colDestino)==true){ // SE LINHA + COLUNA PAR
                            if(colDestino>col){ // SE COLUNA DESTINO DIREITA
                                if(mat[liDestino-1][colDestino-1]==1){ // SE PEÇA IGUAL BOLA
                                    cout << endl << endl << endl << endl;
                                    linha(' ',LARGURA_MENU/2-17);
                                    cout << "NÃO DA PRA MOVER ["<<li<<"]["<<col<<"] PARA ["<<liDestino<<"]["<<colDestino<<"]\n\n";
                                    linha(' ', LARGURA_MENU/2);
                                    exemploPeca('o');
                                    cout << endl;
                                    linha(' ', LARGURA_MENU/2+3);
                                    exemploPeca('o');
                                    cout << endl << endl << endl << endl;
                                    linha(' ',LARGURA_MENU/2-21);
                                    system("pause");
                                }else if(mat[liDestino-1][colDestino-1]==0){ // SE PEÇA IGUAL X
                                    comendoPecaBaixoDireita(li, col, liDestino, colDestino, mat);
                                }else{ // SE IGUAL VAZIA BRANCA
                                    movimentar(li, col, liDestino, colDestino, mat);
                                }
                            }else{ // SE COLUNA DESTINO ESQUERDA
                                if(mat[liDestino-1][colDestino-1]==1){ // SE PEÇA IGUAL BOLA
                                    cout << endl << endl << endl << endl;
                                    linha(' ',LARGURA_MENU/2-17);
                                    cout << "NÃO DA PRA MOVER ["<<li<<"]["<<col<<"] PARA ["<<liDestino<<"]["<<colDestino<<"]\n\n";
                                    linha(' ', LARGURA_MENU/2);
                                    exemploPeca('o');
                                    cout << endl;
                                    linha(' ', LARGURA_MENU/2-3);
                                    exemploPeca('o');
                                    cout << endl << endl << endl << endl;
                                    linha(' ', LARGURA_MENU/2-6);
                                    cout << "PEÇAS IGUAIS";
                                    cout << endl << endl << endl << endl;
                                    linha(' ',LARGURA_MENU/2-21);
                                    system("pause");
                                }else if(mat[liDestino-1][colDestino-1]==0){ // SE PEÇA IGUAL X
                                    comendoPecaBaixoEsquerda(li, col, liDestino, colDestino, mat);
                                }else{
                                    movimentar(li, col, liDestino, colDestino, mat);
                                }
                            }
                        }else{
                            linha(' ',LARGURA_MENU/2-14);
                            cout << "OPA, ESSE MOVIMENTO NÃO VALE!\n\n\n\n\n\n";
                            coordenadaVazia = !coordenadaVazia;
                            system("pause");
                        }

                    }else{
                        coordenadaVazia =+ !coordenadaVazia;
                    }
                }else{ // PEÇAS 'x'
                    mat[li-1][col-1]=4;
                    system("cls");topoGame(li,col);funTabuleiroJogadas(mat);
                    mat[li-1][col-1]=0;

                    linha(' ',LARGURA_MENU/2-13);
                    entrada(liDestino, colDestino);

                    if(li!=liDestino){
                        movimentar(li, col, liDestino, colDestino, mat);

                        linha(' ',LARGURA_MENU/2-15);                        cout << "movimentando";
                        sleep(1);
                        system("cls");topoGame(li,col);funTabuleiroJogadas(mat);


                    }else{
                        coordenadaVazia =+ !coordenadaVazia;
                        system("cls");topoGame(li,col);funTabuleiroJogadas(mat);

                        linha(' ',LARGURA_MENU/2-14);
                        cout << "OPA, ESSE MOVIMENTO NÃO VALE!\n\n\n\n\n\n";
                        system("pause");
                    }
                }
            }

        }else{
            linha(' ',LARGURA_MENU/2-14);
            cout << "OPA, ESSE MOVIMENTO NÃO VALE!\n\n\n\n\n\n";
            coordenadaVazia = !coordenadaVazia;
            system("pause");

        }
    li=0, col=0, liDestino, colDestino=0;
    }while(flagSaida==false);
    cout << endl << endl << endl << endl;

//    do{
//    funTabuleiroJogadas(mat);
//        linha(' ', 45);
//        cout << "INFORME A LINHA:  ";
//        cin >> li;
//        while(li!=3){
//            system("cls");
//            funTabuleiroJogadas(mat);
//            linha(' ', 45);
//            cout << "COORDENADA DE LINHA INVALIDA\n";
//            linha(' ', 45);
//            cout << "INFORME A LINHA:  ";
//            cin >> li;
//        }
//        linha(' ', 45);
//        cout << "INFORME A COLUNA: ";
//        cin >> col;
//        while(col>7){
//            system("cls");
//            funTabuleiroJogadas(mat);
//            linha(' ', 45);
//            cout << "COORDENADA DE COLUNA INVALIDA\n";
//            linha(' ', 45);
//            cout << "INFORME A LINHA:  "<<li<<"\n";
//            linha(' ', 45);
//            cout << "INFORME A COLUNA: ";
//            cin >> col;
//        }
//
//        if(li%2==0){
//            while(col%2!=0){
//                system("cls");
//                funTabuleiroJogadas(mat);
//                linha(' ', 45);
//                cout << "COORDENADA DE COLUNA INVALIDA\n";
//                linha(' ', 45);
//                cout << "INFORME A LINHA:  "<<li<<"\n";
//                linha(' ', 45);
//                cout << "INFORME A COLUNA: ";
//                cin >> col;
//            }
//        }else{
//            while(col%2==0){
//                system("cls");
//                funTabuleiroJogadas(mat);
//                linha(' ', 45);
//                cout << "COORDENADA DE COLUNA INVALIDA\n";
//                linha(' ', 45);
//                cout << "INFORME A LINHA:  "<<li<<"\n";
//                linha(' ', 45);
//                cout << "INFORME A COLUNA: ";
//                cin >> col;
//            }
//        }
//
//    }while((li+col)%2!=0);
//    movimento(li, col, mat);
//    do{
//    funTabuleiroJogadas(mat);
//        linha(' ', 45);
//        cout << "INFORME A LINHA:  ";
//        cin >> liDestino;
//        while(liDestino!=li+1){
//            system("cls");
//            funTabuleiroJogadas(mat);
//            linha(' ', 45);
//            cout << "COORDENADA DE LINHA INVALIDA\n";
//            linha(' ', 45);
//            cout << "INFORME A LINHA:  ";
//            cin >> liDestino;
//        }
//        linha(' ', 45);
//        cout << "INFORME A COLUNA: ";
//        cin >> colDestino;
//        while(colDestino>7){
//            system("cls");
//            funTabuleiroJogadas(mat);
//            linha(' ', 45);
//            cout << "COORDENADA DE COLUNA INVALIDA\n";
//            linha(' ', 45);
//            cout << "INFORME A LINHA:  "<<li<<"\n";
//            linha(' ', 45);
//            cout << "INFORME A COLUNA: ";
//            cin >> colDestino;
//        }
//
//        if(liDestino%2==0){
//            while(colDestino%2!=0){
//                system("cls");
//                funTabuleiroJogadas(mat);
//                linha(' ', 45);
//                cout << "COORDENADA DE COLUNA INVALIDA\n";
//                linha(' ', 45);
//                cout << "INFORME A LINHA:  "<<liDestino<<"\n";
//                linha(' ', 45);
//                cout << "INFORME A COLUNA: ";
//                cin >> colDestino;
//            }
//        }else{
//            while(colDestino%2==0){
//                system("cls");
//                funTabuleiroJogadas(mat);
//                linha(' ', 45);
//                cout << "COORDENADA DE COLUNA INVALIDA\n";
//                linha(' ', 45);
//                cout << "INFORME A LINHA:  "<<liDestino<<"\n";
//                linha(' ', 45);
//                cout << "INFORME A COLUNA: ";
//                cin >> colDestino;
//            }
//        }
//
//    }while((liDestino+colDestino)%2!=0);
    cout << endl;





}
