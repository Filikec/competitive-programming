#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

list<long long> Graph[500];
list<pair<long long,long long>> Edges;
long long Capacity[500][500];
long long S, T;

bool path_exist(long long s, long long t){
    long long Prev[500], flow=0;
    
    for (long long i=0;i<500;i++) Prev[i] = -1;

    list<pair<long long,long long>> queue;
    queue.push_back(make_pair(s,2147483647));
    Prev[s] = -2;

    while (!queue.empty()){
        pair<long long,long long> curr = queue.front();
        queue.pop_front();
        
        if (curr.first == t){
            flow = curr.second;
            break;
        }

        for (auto neigh : Graph[curr.first]){
            if (Prev[neigh]==-1 && Capacity[curr.first][neigh]>0){
                queue.push_back(make_pair(neigh,min(curr.second,Capacity[curr.first][neigh])));
                Prev[neigh] = curr.first;
            } 
        }
    }

    if (Prev[t]==-1) return false;
    
    long long current = t;
    while (Prev[current]!=-2){
        Capacity[Prev[current]][current] -= flow;
        Capacity[current][Prev[current]] += flow;
        current = Prev[current];
    }
    
    return true;
}

void max_flow(long long s, long long t){
    while (path_exist(s,t)){
        ;
    }
}

int main(){

    long long n, m, s, t;

    cin >> n >> m >> s >> t;

    for (long long i=0;i<m;i++){
        long long a,b,c;
        cin >> a >> b >> c;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
        Capacity[a][b] += c;
        
        Edges.push_back(make_pair(a,b));
    }

    max_flow(s,t);
    
    unordered_set<long long> vertices;
    list<long long> queue;
    queue.push_back(s);
    

    while (!queue.empty()){
        long long curr = queue.front();
        queue.pop_front();
        if (!vertices.count(curr)) vertices.insert(curr);
        

        for (auto neigh : Graph[curr]){
            if (Capacity[curr][neigh] && !vertices.count(neigh)){
                queue.push_back(neigh);
            }
        }
    }

    cout << vertices.size() << "\n";
    for (auto v : vertices){
        cout << v << "\n";
    }

    return 0;
}