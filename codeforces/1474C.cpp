#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

typedef long long ll;

bool follow(int i, vector<ll> &v, unordered_map<ll,int> &m, int n){
    unordered_map<ll,int> cm;
    cm[v[2*n-1]]++;
    cm[v[i]]++;

    ll sum = v[2*n-1];
    list<pair<ll,ll>> ins = {{v[2*n-1],v[i]}};
    for (int i=2*n-2;i>=0;i--){
        if (m[v[i]]-cm[v[i]] <= 0) continue;
        ll cur = v[i];
        cm[cur]++;
        ll needed = sum-cur;
        if (m[needed]-cm[needed] <= 0) return false;
        cm[needed]++;
        ins.push_back({cur,needed});
        sum = cur;
    }
    cout << "YES\n";
    cout << ins.front().first + ins.front().second << '\n';
    for (auto &p : ins) cout << p.first << ' ' << p.second << '\n';
    return true;
    
}
void work(){
    int n;
    cin >> n;
    vector<ll> v(2*n);  
    unordered_map<ll,int> map;

    for (int i=0;i<2*n;i++) cin >> v[i], map[v[i]]++;
    sort(v.begin(),v.end());

    bool f = false;
    for (int i=0;i<2*n-1;i++){
        f = follow(i,v,map,n);
        if (f) break;
    }
    if (!f) cout << "NO\n";
}

int main(){

    int t;
    cin >> t;
    for (int i=0;i<t;i++) work();

    return 0;
}