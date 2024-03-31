#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


bool dfs(int n,int a,int b,vector<list<int>> &g,set<int> &s, list<int> &p){
    if (s.count(n)) return false;
    s.insert(n);
    int prev = p.back();
    p.push_back(n);

    for (auto neigh : g[n]){
        if (neigh==prev) continue;
        if (s.count(neigh)){
            p.push_back(neigh);
            return true;
        }
        if (dfs(neigh,a,b,g,s,p)) return true;
    }
    p.pop_back();
    return false;
}

ll bfs(int a, int b, vector<list<int>> &g){
    list<pll> q = {{a,0}};
    set<int> used = {a};
    while (q.size()){
        auto cur = q.front();
        q.pop_front();
        if (cur.first == b) return cur.second;
        for (auto n : g[cur.first]){
            if (!used.count(n)){
                q.push_back({n,cur.second+1});
                used.insert(n);
            }
        }
    }
}

void work(){
    ll n,a,b;
    cin >> n >> b >> a;
    vector<list<int>> g(n+1);

    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int> s;
    list<int> p = {-1}; 
    dfs(a,a,b,g,s,p);
    
    set<int> cycle;
    int l = p.back();
    p.pop_back();
    while (p.back() != l) cycle.insert(p.back()), p.pop_back();
    // cout << l << "<\n";
    // cout << bfs(a,l,g) << ' ' << bfs(b,l,g) << "<\n";
    if (bfs(a,l,g) < bfs(b,l,g)) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}