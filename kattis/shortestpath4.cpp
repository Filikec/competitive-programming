#include <iostream>
#include <queue>
#include <list>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

list<int> Graph[1000];
long long Distances[1000][1000];
long long Paths_curr[1000], Paths_next[1000];
int V;


void init(){
    cin >> V;
    for (int i=0;i<V;i++){
        int edges;
        cin >> edges;
        for (int j=0;j<edges;j++){
            int vertex;
            long long value;
            cin >> vertex >> value;
            Graph[i].push_back(vertex);
            Distances[i][vertex] = value;
        }
    }
}

void clear(){
    for (int i=0;i<V;i++){
        Graph[i].clear();
    }
}

void bfs(int s, int t, int k){
    queue<int> queue1, queue2;
    queue<int> *curr=&queue1, *next=&queue2;

    int Used[1000];

    for (int i=0;i<V;i++){
        Paths_curr[i] = INT_MAX;
        Paths_next[i] = INT_MAX;
    }

    Paths_curr[s] = 0;
    Paths_next[s] = 0;
    int step = 1;
    queue1.push(s);
    while (step < k){
        while (!(*curr).empty()){
            int node = (*curr).front();
            (*curr).pop();
            for (auto neigh : Graph[node]){
                if (Paths_next[neigh] > Paths_curr[node]+Distances[node][neigh]){
                    Paths_next[neigh] = Paths_curr[node]+Distances[node][neigh];
                    (*next).push(neigh);
                }
            }
        }
        for (int i=0;i<1000;i++){
            Paths_curr[i] = Paths_next[i];
        }
        if (step%2){
            curr = &queue2;
            next = &queue1;
        }else{
            curr = &queue1;
            next = &queue2;
        }
        step++;
    }

    if (Paths_curr[t] != INT_MAX){
        cout << Paths_curr[t]<<"\n";
    }else{
        cout << -1 << "\n";
    }
}

void work(){
    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        int s,t,k;
        cin >> s >> t >> k;
        bfs(s,t,k);
    }
    cout << "\n";
}

int main(){
    int c;
    cin >> c;
    for (int i=0;i<c;i++){
        init();
        work();
        clear();
    }
}