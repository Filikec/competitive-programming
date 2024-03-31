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
Edge Edges[20000000];
string Strings[1000];
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
    return e1.from < e2.from;
}

int main(){
    int n,k;
    Heap.reserve(600000);
    int Used[20000];
    long long min_cost = 0;
    make_heap(Heap.begin(),Heap.end(),compare);

    cin >> n >> k;
    getchar();
    for (int i=0;i<n;i++){
        string s = "";
        getline(cin,s);
        for (int j=0;j<i;j++){
            int dif = 0;
            for (int c=0;c<k;c++){
                if (s[c]!=Strings[j][c]){
                    dif++;
                }
            }
            Edges[E].from = i;
            Edges[E].to = j;
            Edges[E].weight = dif;
            Graph[i].push_back(Edges[E]);
            E++;
            Edges[E].from = j;
            Edges[E].to = i;
            Edges[E].weight = dif;
            Graph[j].push_back(Edges[E]);
            E++;
        }
        Strings[i] = s;
    }
    vector<Edge> final_edges;
    final_edges.reserve(1000000);
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
            final_edges.push_back(new_edge);
            
        }
    }
    cout << min_cost << "\n";
    for (auto e : final_edges){
        cout << e.from << " " <<e.to << "\n";
    }
    return 0;
}