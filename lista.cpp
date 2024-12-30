#include <iostream>


using namespace std;
#define tam 10
int main(){
    setlocale(LC_ALL, "portuguese");
    double vet[tam], media=0;
//    cout << "INFORME 30 NOTAS:\n";
//    for(int i=0;i<tam;i++){
//
//        cout << i+1 << ": ";
//        cin>>vet[i];
//        media+=vet[i];
//    }
//    cout <<"MÉDIA DA TURMA: " << media/tam;
    for(int i=0;i<tam;i++)cin >> vet[i];
    for(int i=0;i<tam;i++)cout << vet[i]<<" ";

    return 0;
}
