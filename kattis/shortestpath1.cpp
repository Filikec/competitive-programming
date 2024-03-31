#include <iostream>
#include <list>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_map>

using namespace std;

int Given[10000][10000];
long long Distances[10000];
int S;
list<int> Graph[10000];

vector<int> Heap;
unordered_map<int,int> Heap_used;

int get_left(int i){
    return i*2+2;
}

int get_right(int i){
    return i*2+1;
}

int get_parent(int i){
    return (i-1)/2;
}

void down_heapify(int i){
    int largest = i;
    int left, right;

    left = get_left(i);
    right = get_right(i);

    if (left < Heap.size() && Distances[Heap[left]] < Distances[Heap[largest]]){
        largest = left;
    }
    if (right < Heap.size() && Distances[Heap[right]] < Distances[Heap[largest]]){ // change comparison here to fit your needs
        largest = right;
    }

    int temp = Heap[i];
    Heap_used[Heap[largest]] = i;
    
    Heap[i] = Heap[largest];
    Heap[largest] = temp;

    if (largest != i){
        down_heapify(largest);
        return;
    }

    Heap_used[Heap[i]] = i;
}

void up_heapify(int i){
    int parent;

    while ((parent = get_parent(i)) >= 0 && Distances[Heap[parent]] > Distances[Heap[i]]){ // change comparison here to fit your needs
        
        Heap_used[Heap[parent]] = i;
        int temp = Heap[parent];
        Heap[parent] = Heap[i];
        Heap[i] = temp;
        i = parent;

        if (!i){
            break;
        }
    }

    Heap_used[Heap[i]] = i;
}

void push_heap(int k){
    Heap.push_back(k);

    int i = Heap.size()-1;

    up_heapify(i);
}

void pop_push_heap(int k){
    Heap_used.erase(Heap[0]);

    Heap[0] = k;

    Heap_used[k] = 0;

    down_heapify(0);
}

int pop_heap(){
    if (!Heap.size()){
        return -1;
    }

    int max = Heap[0];
    Heap_used.erase(max);

    Heap[0] = Heap[Heap.size()-1];
    Heap[Heap.size()-1] = max;
    
    Heap.pop_back();

    if (Heap.size()) down_heapify(0);
    
 
    return max;
}

void remove_heap(int k){
    int i = Heap_used[k];

    Heap[i] = Heap[Heap.size()-1];
    Heap[Heap.size()-1] = k;
    Heap_used.erase(k);

    Heap.pop_back();

    down_heapify(Heap[i]);
}

int max(){
    return Heap[0];
}


void change_key(int k, int new_k){
    int i = Heap_used[k];

    Heap[i] = new_k;

    Heap_used.erase(k);
    Heap_used[new_k] = i;

    if (Distances[new_k]<Distances[k]){ //change comparison
        down_heapify(i);
        return;
    }
    up_heapify(i);
    return;
}


void dijkstra(int n){
    Heap.clear();
    Heap_used.clear();

    fill(Distances,Distances+10000,LLONG_MAX);

    Distances[S] = 0;

    for (int i=0;i<n;i++){
        push_heap(i);
    }

    while (!Heap.empty()){  
        int current = pop_heap();
        if (Distances[current] == LLONG_MAX) break;
        for (auto node : Graph[current]){
            long long tmp = Distances[current] + Given[current][node];
            if (tmp < Distances[node]){
                Distances[node] = tmp;
                up_heapify(Heap_used[node]);
            }
        }
    }
}

int main(){
    int n,m,q;
    Heap.reserve(30000);
    while(cin >> n >> m >> q >> S && (n || m || q || S)){
        for (int i=0;i<n;i++){
            Graph[i].clear();
            for (int j=0;j<n;j++){
                Given[i][j] = INT_MAX;
            }
        }
        for (int i=0;i<m;i++){
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            if (Given[v1][v2] == INT_MAX){
                Graph[v1].push_back(v2);
                Given[v1][v2] = w;
            }else if (Given[v1][v2] > w){
                Given[v1][v2] = w;
            }
            
        }

        dijkstra(n);

        for (int i=0;i<q;i++){
            int v;
            cin >> v;
            if (v > 9999 || Distances[v] == LLONG_MAX){
                cout << "Impossible\n";
            }else{
                cout << Distances[v] <<"\n";
            }
        }
    }
   
}