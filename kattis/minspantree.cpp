#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct edge{
    int from, to, weight;
} Edge;

list<Edge> Graph[20000];
int E;
Edge Edges[60000];
vector<Edge> Heap;

bool compare(Edge e1, Edge e2){
    return e1.weight > e2.weight;
}

void add_v(int n){
     for (auto e : Graph[n]){
         Heap.push_back(e);
         push_heap(Heap.begin(),Heap.end(),compare);
     }
}

bool compare2(Edge e1, Edge e2){
    if (e1.from == e2.from){
        return e1.to < e2.to;
    }
    return e1.from < e2.from;
}

void work(int n,int e){
    int Used[20000];
    long long min_cost = 0;
    E = 0;
    Heap.clear();
    make_heap(Heap.begin(),Heap.end(),compare);
    for (int i=0;i<20000;i++){
        Graph[i].clear();
        Used[i] = 0;
    }
    for (int i=0;i<e;i++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        Edges[E].from = v1;
        Edges[E].to = v2;
        Edges[E].weight = w;
        Graph[v1].push_back(Edges[E]);
        E++;
        Edges[E].from = v2;
        Edges[E].to = v1;
        Edges[E].weight = w;
        Graph[v2].push_back(Edges[E]);
        E++;
    }
    vector<Edge> final_edges;
    add_v(0);
    Used[0] = 1;
    while (Heap.size()){
        Edge new_edge = Heap.front();
        pop_heap(Heap.begin(),Heap.end(),compare);
        Heap.pop_back();
        if (!Used[new_edge.to]){
            Used[new_edge.to] = 1;
            min_cost += new_edge.weight;
            add_v(new_edge.to);
            if (new_edge.from > new_edge.to){
                int tmp = new_edge.from;
                new_edge.from = new_edge.to;
                new_edge.to = tmp;
            }
            final_edges.push_back(new_edge);
            
        }
    }
    sort(final_edges.begin(),final_edges.end(),compare2);
    for (int i=0;i<n;i++){
        if (!Used[i]){
            cout << "Impossible\n";
            return;
        }
    }
    cout << min_cost << "\n";
    for (auto e : final_edges){
        cout << e.from << " " <<e.to << "\n";
    }

}

int main(){
    int n,e;
    Heap.reserve(600000);
    while (cin >> n >> e && (n ||e)){
        work(n,e);
    }
    return 0;
}