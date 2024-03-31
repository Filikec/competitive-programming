#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000

int K;
typedef struct{
    int to, cost;
} Edge;

Edge Edges[400000];
list<int> Graph[1000];
int dist[1000][31];

pair<int,int> get_ind(int n){
    pair<int,int> result;
    result = {n/(K+1),n%(K+1)};
    
    return result;
}

class Heap{ // min heap
    public:
    vector<int> heap;
    unordered_map<int,int> used;

    Heap(){
        heap.reserve(1000);
    }

    int get_left(int i){
        return i*2+2;
    }

    int get_right(int i){
        return i*2+1;
    }

    int get_parent(int i){
        return (i-1)/2;
    }

    void down_heapify(int i){// i is the index of el. to down heapify, can use to update key value if e.g. the value is in a different array
        int largest = i;
        int left, right;

        left = get_left(i);
        right = get_right(i);

        if (left < heap.size() && dist[heap[left]/(K+1)][heap[left]%(K+1)] < dist[heap[largest]/(K+1)][heap[largest]%(K+1)]){
            largest = left;
        }
        if (right < heap.size() && dist[heap[right]/(K+1)]  [heap[right]%(K+1)] < dist[heap[largest]/(K+1)][heap[largest]%(K+1)]){ // change comparison here to fit your needs
            largest = right;
        }

        int temp = heap[i]; 
        used[heap[largest]] = i;
        
        heap[i] = heap[largest];
        heap[largest] = temp;

        if (largest != i){
            down_heapify(largest);
            return;
        }

        used[heap[i]] = i;
    }

    void up_heapify(int i){
        int parent;

        while ((parent = get_parent(i)) >= 0 && dist[heap[parent]/(K+1)][heap[parent]%(K+1)] > dist[heap[i]/(K+1)][heap[i]%(K+1)]){ // change comparison here to fit your needs
            
            used[heap[parent]] = i;
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;

            if (!i){
                break;
            }
        }

        used[heap[i]] = i;
    }

    void push_heap(int k){
        heap.push_back(k);

        int i = heap.size()-1;

        up_heapify(i);
    }

    void pop_push_heap(int k){
        used.erase(heap[0]);

        heap[0] = k;

        used[k] = 0;

        down_heapify(0);
    }

    int pop_heap(){
        if (!heap.size()){
            return -1;
        }

        int max = heap[0];
        used.erase(max);

        heap[0] = heap[heap.size()-1];
        heap[heap.size()-1] = max;
        
        heap.pop_back();

        if (heap.size()) down_heapify(0);
        
    
        return max;
    }

    void remove_heap(int k){
        int i = used[k];

        heap[i] = heap[heap.size()-1];
        used[heap[i]] = i;
        used.erase(k);
        heap.pop_back();
        
        //MOTHERFUCKER
       
        down_heapify(i);
        up_heapify(i);
        
    }

    int max(){
        return heap[0];
    }


    void change_key(int k, int new_k){
        int i = used[k];

        heap[i] = new_k;

        used.erase(k);
        used[new_k] = i;


        down_heapify(i);
        up_heapify(i);
        return;
    }

};




void dijkstra(int s, int t, int k,int n){
    Heap *heap = new Heap;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<=k;j++){
            dist[i][j] = INF;
            heap->push_heap(i*(k+1)+j);
        }
        
    }
    dist[s][1] = 0;
    heap->up_heapify(heap->used[s*(k+1)+1]);
    while (heap->heap.size()){
        pair<int,int> curr = get_ind(heap->pop_heap());
        if (dist[curr.first][curr.second]== INF) continue;
        if (curr.first == t) break;
        if (curr.second == k) continue;

        for (auto edge : Graph[curr.first]){
            int neigh = Edges[edge].to;

            dist[neigh][curr.second+1] = min(dist[neigh][curr.second+1],dist[curr.first][curr.second]+Edges[edge].cost);
            heap->up_heapify(heap->used[neigh*(k+1)+curr.second+1]);
        }
    }

    int minim = INF;
    for (int i=0;i<=k;i++){
        minim = min(minim,dist[t][i]);
    }
    if (minim == INF){
        cout << "-1\n";
    }else{
        cout << minim << "\n";
    }

}

void solve(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int v;
    cin >> v;
    int e_n = 0;
    for (int i=0;i<v;i++){
        int e;
        cin >> e;
        Graph[i].clear();
        for (int j=0;j<e;j++){
            int v, w;
            cin >> v >> w;
            Edges[e_n] = {v, w};
            Graph[i].push_back(e_n++);
        }
    }

    int q;
    cin >> q;

    for (int i=0;i<q;i++){
        int s,t;
        cin >> s >> t >> K;
        dijkstra(s,t,K,v);
    }
    
}


int main(){


    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        if (i)cout << "\n";
        solve();
    }



    return 0;
}