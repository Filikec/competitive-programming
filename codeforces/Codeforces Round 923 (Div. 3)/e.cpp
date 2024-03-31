#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;


void work(){
    int n,m;
    cin >> n >> m;

    int lo = 1, hi = n;
    bool f = false;
    
    vector<int> v(n);

    for (int i=0;i<m;i++){
        int add = f?hi:lo;
        for (int j=i;j<n;j+=m) v[j] = add, add += 1-2*f;
        
        if (f) hi = add;
        else lo = add;
        f = !f;
    }
    for (auto c : v) cout << c << ' ';
    cout << '\n';
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