#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void work(){
    int n;
    cin >> n;

    ll f;
    cin >> f;
    ll gcd = f;

    ll best = f;
    for (int i=1;i<n;i++){
        cin >> f;
        gcd = __gcd(abs(f),gcd);
        best = max(best,f);
    }
    cout << gcd << '\n';
    cout << max(best,1LL)+1+(max(best,1LL)+1)%gcd << '\n';
}


int main(){

    int t;
    cin >> t;
    while (t--) work();

    return 0;
}