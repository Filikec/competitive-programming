#include <bits/stdc++.h>

using namespace std;


void f(int n, int a, int b, int c, list<pair<int,int>> &m){
    if (!n) return;
    f(n-1,a,c,b,m);
    m.push_back({a,b});
    f(n-1,c,b,a,m);
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    list<pair<int,int>> l;

    f(n,1,3,2,l);
    cout << l.size() << '\n';
    for (auto &p : l) cout << p.first << ' ' << p.second << '\n';

    return 0;
}