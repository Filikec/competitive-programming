#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,m, key[30];
    string raw, ciphered, known;

    cin >> n >> m;

    cin >> raw >> ciphered;


    for (int i=0;i<n;i++){
        for (int j=0;j<25;j++){
            if ((raw[i]-'a' + j)%26 == ciphered[m-n+i]-'a'){
                key[(m-n+i)%n] = j;
            }
        }
    }

    for (int i=0;i<m;i++){
        for (int j=0;j<25;j++){
            if ((key[i%n] + j)%26 == ciphered[i]-'a'){
                cout << (char)(j+'a');
            }
        }
    }
    cout << "\n";

    return 0;
}