#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

map<char, bool>chutou;
vector<char> chutes_errados;

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


int main(){
    system("cls");

    cout<<"**************************************\n";
    cout<<"*           JOGO DA FORCA            *\n";
    cout<<"**************************************\n";


    const string PALAVRA_SECRETA = "PUTADA"; 
    

    while (nao_acertou(PALAVRA_SECRETA) && nao_enforcou()){
        system("cls");
        cout<<"Chutes errados: ";
        for (char letra : chutes_errados)
        {
            cout<<letra<<" ";
        }
        cout<<"\n";

        for(char letra : PALAVRA_SECRETA){
            if(chutou[letra])
            {
                cout<< letra <<" ";
            }else{
                cout<< "_ ";
            }

            
        }

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
    
}


