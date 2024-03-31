#include <iostream>

using namespace std;

int main(){


    string s;

    cin >> s;

    bool f = false;
    for (int i=0;i<s.size()-1;i++){
        if (s[i] == '(' && s[i+1] == ')' && i*2 == s.size()-2) f = true;
    }

    if (f) cout << "correct\n";
    else cout << "fix\n";
}