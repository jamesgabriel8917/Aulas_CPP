#include <vector>
#include <string>
#include <time.h>

#include <le_arquivo.cpp>


string sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    return palavras[indice_sorteado];
}
