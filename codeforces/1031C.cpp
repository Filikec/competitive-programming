#include <bits/stdc++.h>

using namespace std;

typedef long long ll;




int main(){
    ll a,b;
    cin >> a >> b;

    ll n=1;
    for (ll i=0;i*i+i<=a+b+a+b;i++) n = i;

    set<ll> as;
    for (ll i=n;i>0;i--){
        if (a >= i) a -= i, as.insert(i);
    }

    cout << as.size() << '\n';
    for (auto c : as) cout << c << ' ';
    cout << '\n';
    cout << n-as.size() << '\n';
    for (int i=1;i<=n;i++) if (!as.contains(i)) cout << i << ' ';
    cout << '\n';

    return 0;
}