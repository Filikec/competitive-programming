#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <unordered_map>

#define INF 1000000000

using namespace std;

int Distance_dfs[500],Distances[500],N,Used[500],Prev[500],Min=INF,Best[500],Edges[500];
list<int> Graph[500];
int Connected[500][500];

class Heap{
    public:
    vector<int> heap;
    unordered_map<int,int> used;

    Heap(){
        heap.reserve(500);
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

        if (left < heap.size() && Distances[heap[left]] < Distances[heap[largest]]){
            largest = left;
        }
        if (right < heap.size() && Distances[heap[right]] < Distances[heap[largest]]){ // change comparison here to fit your needs
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

        while ((parent = get_parent(i)) >= 0 && Distances[heap[parent]] > Distances[heap[i]]){ // change comparison here to fit your needs
            
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
        if (Distances[k] > Distances[heap[i]]){
            down_heapify(i);
        }else{
            up_heapify(i);
        }
    }

    int max(){
        return heap[0];
    }


    void change_key(int k, int new_k){
        int i = used[k];

        heap[i] = new_k;

        used.erase(k);
        used[new_k] = i;

        if (new_k>k){ //change comparison function to fit your needs
            down_heapify(i);
            return;
        }
        up_heapify(i);
        return;
    }

};



Heap *heap = new Heap;



void preprocess(){
	 ;
}


bool spfa(){
    int prev[500];
    set<int> finalist;
    
    heap->heap.clear();
    Distances[N-1] = 0;
    prev[0] = -1;

    for (int i=0;i<N-1;i++){
        Distances[i] = INF;
        Used[i]=0;
        heap->push_heap(i); 
    }
    heap->push_heap(N-1); 

    while (!heap->heap.empty()){
        int curr = heap->max();
        heap->pop_heap();   
        if (!curr) break;

        for (auto neigh : Graph[curr]){ 
            if (Distances[neigh] > Distances[curr]+!Distance_dfs[neigh]){
                Distances[neigh] = Distances[curr]+!Distance_dfs[neigh];
                prev[neigh] = curr;
                heap->up_heapify(heap->used[neigh]);
            }
        }
    }

    int curr = N-1;
    if (prev[0] == -1) return false;

    while (curr){
        finalist.insert(curr);
        curr = Prev[curr];
    }

    curr = 0;
    while (curr!=N-1){
        finalist.insert(curr);
        curr = prev[curr];
    }

    Min = min(Min,(int)finalist.size()-1);

    return true;
}


bool dfs(int n=0, int dist=0, int back=0){
    Distance_dfs[n] = 1;
    if (dist >= Min){
        ;
    }else if (N-1==n){
        if (!spfa()) return false;
    }else{
        for (auto e : Graph[n]){
            if (dist>=Min-back) break;
            if (!Distance_dfs[e]){
                Prev[e] = n;
                if (!dfs(e,dist+1,back+(Connected[e][n]))) return false;
                Prev[e] = -1;
            }
        }   
    }
    Distance_dfs[n] = 0;
    return true;
}



int main(){
    cin >> N;

    for (int i=0;i<N;i++){
        int count;
        cin >> count;
        Prev[i] = -1;
        for (int c=0;c<count;c++){
            int neigh;
            cin >> neigh;
            if (!Connected[i][neigh]){
                Graph[i].push_back(neigh-1);
                Connected[i][neigh] = 1;
            }
            
        }
    }

    dfs();  

    if (Min == INF){
        cout << "nej\n";
    }else{
        cout << Min << '\n';
    }
    

    return 0;
}

/*
9
1 9
1 6
1 7
1 1
2 2 6
1 7
2 1 4
3 3 2 5
3 8 8 4
*/
