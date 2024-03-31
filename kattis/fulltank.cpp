#include <iostream>
#include <list>

#define INF 10000000

using namespace std;


list<int> Graph[1000];
int Prices[1000], Distances[1000][1000];
int Dynamic[1000][101], Used[1000];

void solve(int n){
    int s, e, c;
    cin >> c >> s >> e;
    for (int i=0;i<n;i++){
        Used[i] = 0;
        for (int j=0;j<=c;j++){
            Dynamic[i][j] = INF;
        }
    }
    for (int i=0;i<=c;i++){
        Dynamic[s][i] = Prices[s]*i;
    }

    list<int> queue;
    queue.push_back(s);
    Used[s] = 1;    

    while (!queue.empty()){
        int curr = queue.front();
        queue.pop_front();
        Used[curr] = 0;
        for (auto neigh : Graph[curr]){
            if (Distances[curr][neigh] > c){
                continue;
            }
            for (int i=0;i<=c;i++){
                int tmp;
                if (i+Distances[curr][neigh] > c){
                    tmp = Dynamic[curr][c] + Prices[neigh]*(i+Distances[curr][neigh]-c);
                }else{
                    tmp = Dynamic[curr][i+Distances[curr][neigh]];
                }
                int old = Dynamic[neigh][i];

                Dynamic[neigh][i] = min(Dynamic[neigh][i],min(tmp,Dynamic[curr][Distances[curr][neigh]]+Prices[neigh]*i));

                if (old != Dynamic[neigh][i] && !Used[neigh]){
                    queue.push_back(neigh);
                    Used[neigh] = 1;
                }
                
            }
        }
    }

   if (Dynamic[e][0] == INF){
       cout << "Impossible\n";
   }else{
       cout << Dynamic[e][0] << "\n";
   }
}

int main(){
    int n,m;

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> Prices[i];
    }

    for (int i=0;i<m;i++){
        int a,b,d;
        cin >> a >> b >> d;
        if (!Distances[a][b] || Distances[a][b] > d) Distances[a][b] = d;
        if (!Distances[b][a] || Distances[b][a] > d) Distances[b][a] = d;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        solve(n);
    }

    return 0;
}   