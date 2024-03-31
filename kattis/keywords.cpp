#include <iostream>
#include <unordered_set>

using namespace std;


int main(){

    int n;

    cin >> n;
    unordered_set<string> Words;
    cin.get();
    for (int i=0;i<n;i++){
        string s,result;
        
        getline(cin,s);

        for (int j=0;j<s.size();j++){
            char cha = s[j];
            if (cha == '-'){
                cha = ' ';
            }else if(cha >= 'A' && cha <= 'Z'){
                cha -= 'A';
                cha += 'a';
            }
            result += cha;
        }
        Words.insert(result);
    }

    cout << Words.size() << '\n';


    return 0;
}


/*
6
cryptography
blockchain
Artificial intelligence
Machine-Learning
Linux
artiFICIAL-intelliGENCE
*/