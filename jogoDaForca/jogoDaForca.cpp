#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <windows.h>
#include <time.h>

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

bool chute_existe(char chute, string palavra_secreta){

    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(string palavra_secreta){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

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

vector<string> le_arquivo() {
    ifstream arquivo("palavras.txt"); // Abre o arquivo "palavras.txt"

    if (!arquivo.is_open()) { // Verifica se o arquivo foi aberto com sucesso
        cout << "Erro ao abrir o arquivo!" << endl;
        exit(0);
    }

    int quantidade_palavras;
    arquivo >> quantidade_palavras; // Lê o número de palavras do arquivo

    vector<string> palavras_arquivo;

    // Lê e exibe cada palavra
    for (int i = 0; i < quantidade_palavras; i++) {
        string palavra_lida;
        arquivo >> palavra_lida; // Lê cada palavra do arquivo
        palavras_arquivo.push_back(palavra_lida);
    }

    arquivo.close(); // Fecha o arquivo após a leitura
    
    return palavras_arquivo;

}

string sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    return palavras[indice_sorteado];
}

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
