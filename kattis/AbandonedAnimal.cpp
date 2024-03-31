#include <iostream>
#include <unordered_map>
#include <functional>
#include <list>
#include <vector>

using namespace std;

// cmp returns 1 if a should be before b, 0 otherwise
template<class T>
class Heap{
public:
    Heap(function<bool(T&,T&)> cmp=[](T &a, T &b) {return a<b;}) : size(0), cmp(cmp) {};
    T& get(int index){
        return elements[index];
    }

    void push(T el){
        size++;
        elements.push_back(el);
        upHeap(size-1);
    }

    T pop(){
        int first = 0, last = size-1;

        if (last < first) return elements[first];

        T tmp = elements[first];
        elements[first] = elements[last];
        elements[last] = tmp;

        lookup[elements[first]] = first;
        size--; // get rid of the last element
        lookup.erase(lookup.find(elements[last]));

        downHeap(first);

        return tmp;
    }

    void print(){
        for (int i=0;i<size;i++){
            cout << elements[i] << ' ';
        }
        cout << "<\n";
    }

    void upHeap(int index){
        int parent;

        while ((parent=getParent(index)) != index){
            T &curEl = elements[index],&parEl = elements[parent];
            if (cmp(curEl,parEl)){
                T tmp = curEl;
                curEl = parEl;
                parEl = tmp;
                lookup[curEl] = index;
            }else{
                break;
            }
            index = parent;
        }
        lookup[elements[index]] = index;

    }

    void downHeap(int index){
        int right,left;

        while ( true ){

            right=getRight(index);
            left=getLeft(index);

            if (right >= size && left >= size){
                break;
            }else if (right >= size){
                right = left;
            }else if (left >= size){
                left = right;
            }

            int bestChild = right;

            if (cmp(elements[left],elements[right])){
                bestChild = left;
            }

            if (!cmp(elements[bestChild],elements[index])){
                break;
            }
            
            T tmp = elements[index];
            elements[index] = elements[bestChild];
            elements[bestChild] = tmp;

            lookup[elements[index]] = index;
            index = bestChild;
        }
        lookup[elements[index]] = index;
    }

    int getSize(){
        return size;
    }
    int getIndex(T el){
        return lookup[el];
    }
private:
    int getLeft(int index){
        return (index+1)*2-1;
    }
    int getRight(int index){
        return (index+1)*2;
    }
    int getParent(int index){
        return (index-1)/2;
    }

    int size;
    vector<T> elements; 
    unordered_map<T,int> lookup;
    function<bool(T&,T&)> cmp;
};


int main(){
    int n,k;

    cin >> n >> k;
    unordered_map<string,Heap<int>> minHeap;
    unordered_map<string,Heap<int>> maxHeap;
    for (int i=0;i<k;i++){
        int tmp;
        string f;
        cin >> tmp >> f;
        auto it = minHeap.find(f);
        if (it == minHeap.end()){
            Heap<int> *newMin = new Heap<int>([&](int a, int b){return a<b;});
            minHeap[f] = *newMin;
            minHeap[f].push(tmp);
            Heap<int> *newMax = new Heap<int>([&](int a, int b){return a>b;});
            maxHeap[f] = *newMax;
            maxHeap[f].push(tmp);
        }else{
            minHeap[f].push(tmp);
            maxHeap[f].push(tmp);
        }
    }

    int m;

    cin >> m;
    list<int> path;
    list<string> order;
    int cur = -1;
    for (int i=0;i<m;i++){
        string g;
        cin >> g;
        order.push_front(g);
        while (minHeap[g].getSize() && cur > minHeap[g].get(0)){
            minHeap[g].pop();
        }
        if (minHeap[g].getSize() == 0){
            cout << "impossible\n";
            return 0;
        }
        cur = minHeap[g].get(0);
        path.push_front(cur);
    }
    
    int curBig = 100000000;
    for (auto g : order){
        while (maxHeap[g].getSize() && curBig < maxHeap[g].get(0)){
            maxHeap[g].pop();
        }
        
        curBig = maxHeap[g].get(0);
        if (curBig != path.front()){
            cout << "ambiguous\n";
            return 0;
        }
        path.pop_front();
    }

    cout << "unique\n";


    return 0;
}