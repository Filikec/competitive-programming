#include <iostream>

using namespace std;

typedef long long ll;


pair<ll,ll> D[101][20001];
ll P[101];


int main(){
    ll n,m;
    cin >> n >> m;


    for (int i=0;i<n;i++){
        cin >> P[i];
    }

    D[0][m] = {0,m};

    for (ll i=1;i<=n;i++){
        for (ll j=0;j<=m;j++){
            if (min(j,P[i-1]) == D[i+1][j*2/3].first && D[i+1][j*2/3].second < j) D[i+1][j*2/3] = {min(j,P[i-1]),j};
            if (min(j,P[i-1]) > D[i+1][j*2/3].first)
        }
    }
    
    
    return 0;
}