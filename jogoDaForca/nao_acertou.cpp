#include <string>
#include <map>

using namespace std;
map<char, bool>chutou;

bool nao_acertou(string palavra_secreta){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}
