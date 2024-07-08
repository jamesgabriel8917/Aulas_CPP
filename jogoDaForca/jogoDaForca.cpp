#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

map<char, bool>chutou;
vector<char> chutes_errados;

void imprime_cabecalho(){
    system("cls");

    cout<<"**************************************\n";
    cout<<"*           JOGO DA FORCA            *\n";
    cout<<"**************************************\n";
}

void imprime_erros(){
    cout<<"Chutes errados: ";
    for (char letra : chutes_errados)
    {
        cout<<letra<<" ";
    }
    cout<<"\n";
}

void imprime_palavra(string PALAVRA_SECRETA){
    for(char letra : PALAVRA_SECRETA){
    if(chutou[letra])
    {
        cout<< letra <<" ";
    }else{
        cout<< "_ ";
    }
}
}

bool chute_existe(char chute, string PALAVRA_SECRETA){

    for(char letra : PALAVRA_SECRETA){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(string PALAVRA_SECRETA){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void chuta(string PALAVRA_SECRETA){
        char chute;
        cout<<"\nDigite o seu chute:     ";
        cin>>chute;

        chutou[chute] = true;

        if (chute_existe(chute, PALAVRA_SECRETA))
        {
            cout<<"PARABENS!! Seu chute esta contido na palavra\n";
        }else{
            cout<<"Errou!\n";
            chutes_errados.push_back(chute);
        }
}


int main(){

    imprime_cabecalho();


    const string PALAVRA_SECRETA = "MORANGO"; 
    

    while (nao_acertou(PALAVRA_SECRETA) && nao_enforcou()){

        imprime_erros();
        imprime_palavra(PALAVRA_SECRETA);
        chuta(PALAVRA_SECRETA);
        
    }

    system("cls");
    
    cout<<"Fim de jogo!\n";
    if(nao_acertou(PALAVRA_SECRETA)){
        cout<<"Tente novamente\n";
    }else{
        cout<<"Parabens, vc acertou a palavra secreta!!\n";
        
    }
    cout<<"A palavra secreta e: "<<PALAVRA_SECRETA<<"\n";
}


