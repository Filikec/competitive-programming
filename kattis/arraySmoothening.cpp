#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int,int> Occurances;

int main(){

    int n,k;

    cin >> n >> k;

    vector<int> heap;

    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        auto it = Occurances.find(tmp);
        if (it == Occurances.end()){
            Occurances[tmp] = 1;
            heap.push_back(tmp);
        }
        else it->second++;    
    }

    sort(heap.begin(),heap.end(),[&](int a, int b){return Occurances[a] > Occurances[b];});

    for (int i=0;i<k;i++){
        auto cur = heap.front();
        pop_heap(heap.begin(),heap.end(),[&](int a,int b){return Occurances[a] < Occurances[b];});
        heap.pop_back();
        Occurances[cur]--;
        heap.push_back(cur);
        push_heap(heap.begin(),heap.end(),[&](int a,int b){return Occurances[a] < Occurances[b];});
    }


    int biggest = 0;
    for (auto o : Occurances){
        biggest = max(biggest,o.second);
    }       

    cout << biggest << "\n";




    return 0;
}