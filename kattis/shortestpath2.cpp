#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

typedef struct{
    int t0,d,cost,to;
} Stop;

list<int> Graph[10000];
Stop Stops[20000];
int Dist[10000];

class Heap{ // min heap
    public:
    vector<int> heap;
    unordered_map<int,int> used;

    Heap(){
        heap.reserve(10000);
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

        if (left < heap.size() && Dist[heap[left]] < Dist[heap[largest]]){
            largest = left;
        }
        if (right < heap.size() && Dist[heap[right]] < Dist[heap[largest]]){ // change comparison here to fit your needs
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

        while ((parent = get_parent(i)) >= 0 && Dist[heap[parent]] > Dist[heap[i]]){ // change comparison here to fit your needs
            
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




int N, M , Q, S;


void solve(){
    Heap *heap = new Heap;
    for (int i=0;i<N;i++){
        Graph[i].clear();
        Dist[i] = INF;
        heap->heap.push_back(i);
        heap->used[i] = i;
    }
    
    for (int i=0;i<M;i++){
        int a,b,t0,P,d;

        cin >> a >> b >> t0 >> P >> d;

        Stops[i] = {t0,P,d,b};

        Graph[a].push_back(i);
    }

    
    Dist[S] = 0;
    heap->up_heapify(heap->used[S]);

    

    while (heap->heap.size()){
        auto curr = heap->pop_heap();
        if (Dist[curr] == INF ) break;

        for (auto edge : Graph[curr]){
            int next = Stops[edge].to;
            int start_time = Stops[edge].t0;
            int delta = Stops[edge].d;
            int cost = Stops[edge].cost;

            int next_time;
            double x;

            if (delta){
                x = ceil((Dist[curr]-start_time)/((double)delta));
                next_time = start_time+delta*x+cost;
            }else if (start_time < Dist[curr]){
                continue;
            }else{
                x = -1;
            }

            if (x < 0){
                next_time = start_time+cost;
            }

            if (next_time < Dist[next]){
                Dist[next] = next_time;
                heap->up_heapify(heap->used[next]);
            }
            
        }
    }

    for (int i=0;i<Q;i++){
        int q;
        cin >> q;
        if (Dist[q] == INF){
            cout << "impossible\n";
        }else{
            cout << Dist[q] << "\n";
        }
    }
    cout << "\n";

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (cin >> N >> M >> Q >> S){
        if (N || M || Q || S){
            solve();
        }else{
            break;
        }
    }

    

    return 0;
}