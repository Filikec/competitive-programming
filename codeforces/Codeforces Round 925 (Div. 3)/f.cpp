#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;



void work(){
    ll n,m;
    cin >> n >> m;
    vector<set<ll>> v(n+1);

    for (int i=0;i<n;i++){
        int c;
        cin >> c;
        if (i) v[c] = {i,i-1};
        else {
            for (int i=0;i<n;i++) v[c].insert(i);
        }
    }

    for (int i=0;i<m-1;i++){
        for (int j=0;j<n;j++){
            int c;
            cin >> c;
            if (j){
                set<ll> news = {j,j-1};
                set<ll> ress;
                for (auto p : v[c]){
                    if (news.count(p)) ress.insert(p);
                }
                v[c] = ress;
            }
        }
    }

    set<ll> used;
    for (int i=1;i<=n;i++){
        if (!v[i].size()){
            cout << "NO\n";
            return;
        }
        for (auto n : v[i]){
            if (v[i].size()==1){
                if (used.count(n)){
                    cout << "NO\n";
                    return;
                }else{
                    used.insert(n);
                }
                
            }
        }
    }
    cout << "YES\n";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    while (t--) work();


    return 0;
}