#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;

void work(){
    int n;
    cin >> n;


    vector<ll> v(n);
    for (auto &c : v) cin >> c;

    int prev = v[0];
    int i=0;
    for (i=0;i<n;i++){
        if (v[i] != prev) break;
    }

    int j=0;
    prev = v[n-1];
    for (j=0;j<n;j++){
        if (v[n-1-j] != prev) break;
    }

    if (v[0] == v[n-1]) cout << max(n-i-j,0) << '\n';
    else cout << max(n-max(i,j),0) << '\n';  

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    while (t--) work();


    return 0;
}