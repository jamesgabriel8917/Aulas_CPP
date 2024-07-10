#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

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
