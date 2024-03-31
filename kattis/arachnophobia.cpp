#include <bits/stdc++.h>

using namespace std;

void work(){
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> u;
    for (auto &c  : v) cin >> c, u.insert(c);
    

    set<int> q;
    int small = 0;
    for (int i=0;i<=n;i++){
        if (u.find(i) == u.end()){
            small = i;
            break;
        }
    }
 
    u.clear();
    for (int i=0;i<small;i++) u.insert(i);
 
    pair<int,int> first = {0,-1};
    for (int i=0;i<n;i++){
        u.erase(v[i]);
        if (!u.size()){
            first.second=i;
            break;
        }
    }
 
    u.clear();
    for (int i=0;i<small;i++) u.insert(i);
    for (int i=first.second+1;i<n;i++){
        u.erase(v[i]);
        if (!u.size()){
            cout << 2 << '\n';
            cout << first.first+1 << ' ' << first.second+1 << '\n';
            cout << first.second+2 << ' ' << n << '\n';
            return;
        }
    }
    cout << "-1\n";
}       
 
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();
 
    return 0;
}