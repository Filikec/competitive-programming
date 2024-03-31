#include <iostream>
#include <list>

using namespace std;

typedef long long ll;

pair<ll,ll> D[200000];
ll P[200000];
list<pair<int,ll>> G[200000];


pair<ll,ll> get(int i, pair<ll,ll> p, int ip=-1){
    ll best = p.first+p.second*P[i];

    

    return best;
}


int main(){

    int n;
    cin >> n;

    for (int i=0;i<n;i++) cin >> P[i];

    for (int i=0;i<n-1;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--,b--;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }

    ll count = 0;
    for (int i=0;i<n;i++) count += get(i);
    cout << count << '\n';

    return 0;
}