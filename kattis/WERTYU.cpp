#include <iostream>
#include <string>


using namespace std;

string Keyboard[4] = {{"`1234567890-="},
    {"QWERTYUIOP[]\\"},
    {"ASDFGHJKL;'"},
    {"ZXCVBNM,./"}};


int main(){

    string line;

    while (getline(cin,line)){
        for (auto c : line){
            if (c != ' '){
                
                char found = 0;
                for (int i=0;i<4;i++){
                    char prev = 0;
                    for (auto k : Keyboard[i]){
                        if (k == c){
                            found = prev;
                            break;
                        }
                        prev = k;
                    }
                    if (found) break;
                }
                cout << found;
            }else{
                cout << ' ';
            }
        }
        cout << '\n';
    }

    

    return 0;
}