#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;
    map<char,int> m;
    int best = 1;
    for (int i=0;i<s.size();i++){
        for (auto &p : m) if (p.first!=s[i]) p.second = 0;
        if (!m[s[i]]) m[s[i]]=i+1;
        else best = max(i+1-m[s[i]]+1,best);
    }
    cout << best << '\n';

    return 0;
}