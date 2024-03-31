#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    char prev = -1;
    for (int i=0;i<s.size();i++){
        if (s[i] != prev) cout << s[i];
        prev = s[i];
    }

    return 0;
}