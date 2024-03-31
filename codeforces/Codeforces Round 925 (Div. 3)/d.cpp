#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;



void work(){
    ll n,x,y;
    cin >> n >> x >> y;

    map<ll,map<ll,ll>> mod;
    
    ll res=0;
    for (int i=0;i<n;i++){
        int c;
        cin >> c;
        res += mod[c%y][(x-c%x)%x];
        mod[c%y][c%x]++;
    }

    cout << res << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    while (t--) work();


    return 0;
}