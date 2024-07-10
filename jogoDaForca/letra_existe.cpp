#include <string>

using namespace std;

bool chute_existe(char chute, string palavra_secreta){

    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}