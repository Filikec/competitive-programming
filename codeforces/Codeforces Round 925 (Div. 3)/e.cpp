#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;



void work(){
    ll n,m;
    cin >> n >> m;
    list<pii> l;
    for (int i=0;i<n;i++){
        ll c;
        cin >> c;
        ll count = 0,countz=0;
        bool b=1;
        while (c){
            count++;
            if (c%10==0&&b) countz++;
            else b=0;
            c /= 10;
        }

        l.push_back({count,countz});
    }
    l.sort([](auto &a, auto &b){return a.second>b.second;});
    
    bool b=0;
    ll res=0;
    for (auto &p : l){
        if (b){
            res += p.first;
        }else{
            res += p.first-p.second;
        }
        b = !b;
    }

    if (res > m) cout << "Sasha\n";
    else cout << "Anna\n";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    while (t--) work();


    return 0;
}