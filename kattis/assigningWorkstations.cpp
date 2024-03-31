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

        elements.pop_back();

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

struct Res{
    int s,l;

};


list<Res> Reses;

int main(){


    int n,d;

    cin >> n >> d;


    for (int i=0;i<n;i++){
        int a,s;

        cin >> a >> s;

        Reses.push_back({a,s});
    }

    Reses.sort([&](Res a, Res b){return a.s < b.s;});

    int used = 0;
    Heap<int> heap([&](int a, int b){return a<b;});
    for (auto r : Reses){
        if (!heap.getSize() || heap.get(0) > r.s){
            used++;
            heap.push(r.l+r.s);
        }else{
            while (heap.getSize() && heap.get(0)+d < r.s){
                heap.pop();
            }
            if (heap.getSize() && heap.get(0)+d >= r.s && heap.get(0) <= r.s){
                heap.pop();
            }else{
                used++;
            }
            heap.push(r.l+r.s);
        }
        
    }

    cout << n-used << '\n';


    return 0;
}