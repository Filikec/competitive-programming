#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

int E[100001][2];

void bfs(int node, int v, vector<list<int>> &g){
    list<int> q = {node};
    set<int> u = {node};
    

    while (q.size()){
        auto cur = q.front();
        q.pop_front();
        for (auto neigh : g[cur]){
            if (!E[neigh][node>neigh] && !u.count(neigh)){
                q.push_back(neigh);
                E[neigh][node>neigh]=1;
                u.insert(neigh);
            }
        }
    }
}

void work(){
    int n;
    cin >> n;
    vector<list<int>> g(n+1);
    vector<char> t(n+1);
    for (int i=0;i<=n;i++) E[i][0] = E[i][1] = 0;

    for (int i=2;i<=n;i++){
        int a;
        cin >> a;
        g[i].push_back(a);
        g[a].push_back(i);
    }

    for (int i=1;i<=n;i++) cin >> t[i];

    set<int> used;
    for (int i=1;i<=n;i++) bfs(i,t[i],g)
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;
}