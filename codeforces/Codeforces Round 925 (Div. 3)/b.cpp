#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;

void work(){
    int n;
    cin >> n;

    vector<ll> v(n);
    list<ll> more;
    ll s=0;
    for (auto &c : v) cin >> c,s+=c;

    for (auto c : v){
        if (c > s/n) more.push_back(c);
        if (c < s/n){
            while (more.size() && c < s/n){
                int needed = min(s/n-c,more.front()-s/n);
                c += needed;
                more.front() -= needed;
                if (more.front() <= s/n) more.pop_front();
            }
            if (c < s/n){
                cout << "NO\n";
                return;
            }
        }
    }

    if (more.size()) cout << "NO\n";
    else cout << "YES\n";

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    while (t--) work();


    return 0;
}