#include <iostream>
#include <string>


using namespace std;

bool chute_existe(char chute, string PALAVRA_SECRETA){

    for(char letra : PALAVRA_SECRETA){
        if(chute == letra){
            return true;
        }
    }
    return false;
}


int main(){
    system("cls");

    const string PALAVRA_SECRETA = "PUTADA"; 

    bool nao_acertou = true;
    bool nao_enforcou = true;



    while (nao_acertou && nao_enforcou){

        char chute;
        cout<<"Digite o seu chute\n";
        cin>>chute;

        if (chute_existe(chute, PALAVRA_SECRETA))
        {
            cout<<"PARABENS!! Seu chute esta contido na palavra\n";
        }else{
            cout<<"Errou!\n";
        }
        
        
    }
    



}


