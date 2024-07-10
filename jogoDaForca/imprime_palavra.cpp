#include <string>
#include <iostream>
#include <map>

using namespace std;


map<char, bool>chutou;

void imprime_palavra(string palavra_secreta){
    for(char letra : palavra_secreta){
    if(chutou[letra])
    {
        cout<< letra <<" ";
    }else{
        cout<< "_ ";
    }
}
}
