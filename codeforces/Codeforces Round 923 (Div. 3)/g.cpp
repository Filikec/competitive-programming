#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;


int D[100][100];

int getBest(int a, int b, vector<int> &v){
    if (b < 0 || a >= v.size()) return 0;
    if (a > b) return 0;
    if (a == b) return 1;
    if (D[a][b] != 1000) return D[a][b];
    int res = 100;
    for (int i=0;i<v.size();i++){
        if (i >= a && i-v[i] < b){
            res = min(res,getBest(a,i-v[i],v)+getBest(i+1,b,v)+1);
        }
        if (i <= b && i+v[i] > a){
            res = min(res,getBest(a,i-1,v)+getBest(i+v[i],b,v)+1);
        }
    }    
    D[a][b] = res;
    return res;
}

void work(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &c : v) cin >> c;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            D[i][j] = 1000;

    cout << getBest(0,n-1,v) << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--){
        work();
    }

    return 0;
}