#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


void work(){
    ll n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    int c=0;
    for (int i=0;i<n;i++){
        if (s[i]!='W')c++,i+=k-1;
    }
    cout << c << '\n';
}   


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}