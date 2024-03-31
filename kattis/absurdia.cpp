#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>

using namespace std;

int Visited[100001];
int Has[100001];

list<int> Graph[100001];
unordered_multiset<int> Graph_dfs[100001];
list<int> Path;

void dfs_pair(int node){
    for (auto neigh : Graph[node]){
       if (!Has[neigh]){
            Has[neigh] = 1;
            cout << neigh << " " << node << "\n";
            dfs_pair(neigh);
       }
    }
}

int dfs(int node){
    unordered_set<int> visited;

    if (Visited[node]){
        Path.push_front(node);
        return 1;
    }
    Visited[node] = 1;
    Path.push_front(node);

    for (auto neigh : Graph_dfs[node]){
        if (visited.count(neigh)){
            continue;
        }
        visited.insert(neigh);

        if (Graph_dfs[neigh].count(node) == 1){
            Graph_dfs[neigh].erase(node);
        }

        if (dfs(neigh)){
            return 1;
        }

        while (Path.front() != node){
            Path.pop_front();
        }

    }

    return 0;
}

int main(){
    int n, n1,n2;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> n1 >> n2;
        Graph[n1].push_back(n2);
        Graph[n2].push_back(n1);

        Graph_dfs[n1].insert(n2);
        Graph_dfs[n2].insert(n1);
    }

    for (int i=1;i<=n;i++){
        if (!Visited[i] && !Has[i]){
            dfs(i);
        }
        
        while (Path.size() && Path.front() != Path.back()){
            Path.pop_back();
        }
        
        auto node1 = Path.begin();
        for (auto node2 = ++Path.begin(); node2 != Path.end();node2++){
            Has[*node1] = 1;
            cout << *node1  << " " <<*node2 << "\n";
            node1++;

        }

        for (auto node : Path){
            dfs_pair(node);
        }

        Path.clear();
    }

    return 0;
}