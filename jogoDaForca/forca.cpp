#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <windows.h>
#include <time.h>

//pacotes locais
#include "nao_acertou.cpp"
#include "letra_existe.cpp"


using namespace std;



map<char, bool>chutou;
vector<char> chutes_errados;

int main(){

    imprime_cabecalho();

    le_arquivo();

    string palavra_secreta = sorteia_palavra(); 
    

    while (nao_acertou(palavra_secreta) && nao_enforcou()){

        imprime_erros();
        imprime_palavra(palavra_secreta);
        chuta(palavra_secreta);
        
    }

    system("cls");
    
    cout<<"Fim de jogo!\n";
    if(nao_acertou(palavra_secreta)){
        cout<<"Tente novamente\n";
    }else{
        cout<<"Parabens, vc acertou a palavra secreta!!\n";
        
    }
    cout<<"A palavra secreta e: "<<palavra_secreta<<"\n";
}
