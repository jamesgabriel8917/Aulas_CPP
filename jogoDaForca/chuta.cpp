#include <string>
#include <iostream>
#include <map>
#include <vector>

//pacotes locais
#include "letra_existe.cpp"


using namespace std;

map<char, bool>chutou;
vector<char> chutes_errados;

void chuta(string palavra_secreta){
        char chute;
        cout<<"\nDigite o seu chute:     ";
        cin>>chute;

        chutou[chute] = true;

        if (chute_existe(chute, palavra_secreta))
        {
            cout<<"PARABENS!! Seu chute esta contido na palavra\n";
        }else{
            cout<<"Errou!\n";
            chutes_errados.push_back(chute);
        }
}
