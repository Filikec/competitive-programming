#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
 
char G[7][7];
 
bool check(){
    for (int i=1;i<6;i++){
        for (int j=1;j<6;j++){
            if (G[i-1][j-1]=='B' &&
                G[i-1][j+1]=='B' &&
                G[i+1][j+1]=='B' &&
                G[i+1][j-1]=='B' &&
                G[i][j] == 'B'){
                    return false;
                }
        }
    }
    return true;
}
 
int getLow(vector<pll> &v, int l=0, int used=0){
    if (check()) return used;
    if (used == 7) return 8;
    int best = 8;
    for (int i=l;i<v.size();i++){
        G[v[i].first][v[i].second]='W';
        best = min(best,getLow(v,i+1,used+1));
        G[v[i].first][v[i].second]='B';
    }
    return best;
}
 
void work(){
    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
            cin >> G[i][j];
        }
    }
    set<pll> u;
    vector<pll> pos;
    for (int i=1;i<6;i++){
        for (int j=1;j<6;j++){
            if (G[i][j]=='B') pos.push_back({i,j});
        }
    }
    
    cout << getLow(pos) << '\n';
}
 
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int t;
    cin >> t;
    while (t--) work();
 
    return 0;
}