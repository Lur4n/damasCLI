#include "bib.h"
#include "bib_opcoes_Menu.h"


void textos(string y, int x){
    int aux;
    cout << y << endl;
    linha('-', TAM_MAX_LINHA);
    cout << endl;

}

void centralize(string texto){
    int aux=0;
    aux = texto.length()/2;
    linha(' ', LARGURA_MENU/2-aux);
}

void opcoesFunTabuleiro(int mat[8][8]){
    string opcao1 = "[1] VOLTAR AO MENU PRINCIPAL";

    cout << endl;
    centralize(opcao1);
    cout << opcao1 << "\n";

    centralize(opcao1);
    cout << "[2] MOSTRAR TABULEIRO\n";

    centralize(opcao1);
    cout << "[3] SAIR\n";

    cout << endl;
    linha(' ', LARGURA_MENU/2-14);
    cout << "INFORME O ÍNDICE DA OPÇÃO: ";
    char resposta = ' ';
    while(resposta==' ')cin >> resposta;

    switch(resposta){
        case '1':
            system("cls");
            menuPrincipal(mat);
            break;
        case '2':
            system("cls");
            topo(" TABULEIRO DE DAMAS ");

            funTabuleiro();
            opcoesFunTabuleiro(mat);
            break;
        case '3':
            break;
        case '4':

            break;
    }

}

void opcoesMenuPrincipal(int mat[8][8]){
    cout << endl;
    string opcao1 = "[1] DESENVOLVIMENTO DO GAME";

    centralize(opcao1);
    cout << opcao1 << "\n";

    centralize(opcao1);
    cout << "[2] SEGUNDA OPÇÃO\n";

    centralize(opcao1);
    cout << "[3] MOSTRAR TABULEIRO\n";

    centralize(opcao1);
    cout << "[4] SAIR\n\n";

    linha(' ', LARGURA_MENU/2-14);
    cout << "INFORME O ÍNDICE DA OPÇÃO: ";

    char resposta = ' ';
    while(resposta==' ')cin >> resposta;

    switch(resposta){
        default:
            system("cls");
            menuPrincipal(mat);
            break;
        case '1':
            jogo(mat);
            break;
        case '3':
            system("cls");
            topo(" TABULEIRO DE DAMAS ");
//            MenuCentralizado(" TABULEIRO DE DAMAS ");

            funTabuleiro();
            opcoesFunTabuleiro(mat);
        break;
        case '4':

        break;

    }
}

void MenuCentralizado(string texto){
    int auxInt = 0;
    if(texto.length()%2==0){
        linhaAzul(LARGURA_MENU);
        cout << endl;

        auxInt = LARGURA_MENU/2 - texto.length()/2;

        linhaAzul(auxInt);
        cout << BAZUL ESMAECER << texto << NC;
        linhaAzul(auxInt);//Linha com texto centralizado;
        cout << endl << SUBLINHAR AMARELO;

        linhaAzul(LARGURA_MENU);
    }else{
        linhaAzul(LARGURA_MENU);
        cout << endl;

        auxInt = LARGURA_MENU/2 - texto.length()/2;

        linhaAzul(auxInt);
        cout << BAZUL ESMAECER << texto << NC;
        linhaAzul(auxInt-1);//Linha com texto centralizado;
        cout << endl << SUBLINHAR AMARELO;

        linhaAzul(LARGURA_MENU);
    }
    cout << endl;
}

void menuInferior(){
    system("cls");
    for(int i=0; i<22; i++){
        cout << endl;
    }
    cout << SUBLINHAR;
            linha(' ',LARGURA_MENU);
            cout << NC;
    linha(' ', LARGURA_MENU);
    string fim = "ATÉ A PRÓXIMA";
    if(fim.length()%2!=0){
        linha(' ',LARGURA_MENU/2-fim.length()/2);
        cout << ESMAECER << fim;
        linha(' ',LARGURA_MENU/2-fim.length()/2-1);
    }else{
        linha(' ',LARGURA_MENU/2-fim.length()/2);
        cout << ESMAECER << fim;
        linha(' ',LARGURA_MENU/2-fim.length()/2);        linha(' ',LARGURA_MENU/2-fim.length()/2);
    }
    fim = "Feito por Luan";
    if(fim.length()%2!=0){
        linha(' ',LARGURA_MENU/2-fim.length()/2);
        cout << ITALICO ESMAECER << fim;
        linha(' ',LARGURA_MENU/2-fim.length()/2-1);
    }else{
        linha(' ',LARGURA_MENU/2-fim.length()/2);
        cout << ITALICO ESMAECER << fim;
        linha(' ',LARGURA_MENU/2-fim.length()/2);
    }
    cout << SUBLINHAR;
    linha(' ',LARGURA_MENU);
    cout << NC;
}
void topoMenu(string y, int x){
    int aux=0;
    if(x%2==0){
        cout << BAZUL;
        linha(' ', LARGURA_MENU);
        cout << endl;
        aux = 60-(x/2);
        linha(' ', aux);
        cout << ESMAECER << y << NC BAZUL;

        aux = 60-(x/2);
//        system("Pause");
        linha(' ', aux);
//        linha(' ', LARGURA_MENU);
        cout << endl << NC;
    }else{
        cout << BAZUL;
        linha(' ', LARGURA_MENU);
        cout << endl;
        aux = LARGURA_MENU/2;
        linha(' ', aux-(x/2));
        cout << ESMAECER << y << NC BAZUL;
        linha(' ', aux-(x/2)+1);
        linha(' ', LARGURA_MENU);
        cout << endl << NC;
    }

}


