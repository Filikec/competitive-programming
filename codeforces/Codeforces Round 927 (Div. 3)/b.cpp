#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


void work(){
    int n;
    cin >> n;

    ll p = 0    ;
    for (int i=0;i<n;i++){
        ll c;
        cin >> c;
        p = (p/c+1)*c;
    }
    cout << p << '\n';
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}