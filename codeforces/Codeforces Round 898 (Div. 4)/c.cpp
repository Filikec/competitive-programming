#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

char G[10][10];

void work(){
    ll count = 0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cin >> G[i][j];
            if (G[i][j] == 'X') count += min(min(i,9-i),min(j,9-j))+1;
        }
    }    
    cout << count << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}