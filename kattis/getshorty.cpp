#include <bits/stdc++.h>


using namespace std;

typedef struct{
    int to;
    float factor;
} Edge;

list<int> Graph[10000];
Edge Edges[30000];


void solve(int n,int m){
    float Sizes[10000];
    int Used[10000];
    for (int i=0;i<n;i++){
        Sizes[i] = 0;
        Used[i] = 0;
    }
    for (int i=0;i<n;i++){
        Graph[i].clear();
    }
    int e_count = 0;
    for (int i=0;i<m;i++){
        int a, b;
        float f;
        scanf("%d %d %f",&a,&b,&f);
        Edges[e_count] = {b,f};
        Graph[a].push_back(e_count++);
        Edges[e_count] = {a,f};
        Graph[b].push_back(e_count++);
    }

    list<int> queue;
    queue.push_back(0);
    Sizes[0] = 1;
    Used[0] = 1;

    while (queue.size()){
        auto curr = queue.front();
        queue.pop_front();
        Used[curr] = 0;

        for (auto neigh : Graph[curr]){
            int to = Edges[neigh].to;
            float f = Edges[neigh].factor;
            

            if (Sizes[to] < Sizes[curr]*f){
                Sizes[to] = Sizes[curr]*f;
                if (!Used[to]){
                    queue.push_back(to);
                    Used[to] = 1;
                }
            }
        }
    }

    cout << fixed << setprecision(4) << Sizes[n-1] << "\n";
}

int main(){
    int n,m;

    while (cin >> n >> m){
        if (!n && !m) break;
        solve(n,m);
    }

    return 0;
}
