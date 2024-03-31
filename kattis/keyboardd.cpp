#include <bits/stdc++.h>

using namespace std;

set<char> Sticky;


int main(){
    string s,t;


    getline(cin,s);
    getline(cin,t);

    int j = 0,i=0;
    for (i=0;i<t.size()&&j<s.size();i++){
        while (t[i] != s[j]){
            Sticky.insert(t[i++]);
        }
        j++;
    }

    for (i;i<t.size();i++){
        Sticky.insert(t[i]);
    }

    for (auto c : Sticky){
        cout << c;
    }
    cout << '\n';   


    return 0;
}