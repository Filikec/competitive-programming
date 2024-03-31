#include <bits/stdc++.h>


using namespace std;

typedef pair<int,int> pii;

int D[1001],U[1001];
list<pii> G[1001];


int main(){
    int n,m;
    cin >> n >> m;
    for (int i=2;i<=n;i++) D[i]=1e9;

    for (int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }

    set<pii> q={1,1};
    while (q.size()){
        auto c = *q.begin();
        q.erase(q.begin());

        for (auto n : G[c]){
            if (D[n] > )
        }
    }

    return 0;   
}