#include <iostream>
#include <list>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <functional>
#include <map>

using namespace std;

// cmp returns 1 if a should be before b, 0 otherwise
template<class T>
class Heap{
public:
    Heap(function<bool(T&,T&)> cmp) : size(0), cmp(cmp) {};
    T& get(int index){
        return elements[index];
    }

    void push(T el){
        elements[size++] = el;
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
    T elements[500000];
    map<T,int> lookup;
    function<bool(T&,T&)> cmp;
};




template<class T>
class List{
    struct Node{
        Node *p, *n;
        T data;
    };

    List(){
        nullNode.n = null;
        nullNode.p = null;
    }

    void push(T data){
        Node *newNode = new Node;
        newNode->data = data;
        newNode->n = null;
        newNode->p = tail;
        tail = newNode;
        size++;
    }

    void size(){
        return size;
    }

    void remove(Node *node){
        node->n->p = node->p;
        node->p->n = node->n;
        if (tail == node){
            tail = node->p;
        }
        if (head == node){
            head = node->next;
        }
        delete this;
    }

    private:
    Node nullNode, *null = &nullNode, *head = null, *tail = null;
    
    int size;
};


struct Section{
    list<set<int>>::iterator a, b;
    set<int> primes;
    
    friend bool operator<(const Section  &a, const Section  &b){
        return a.primes.size() < b.primes.size();
    }
};

#define cmp [&] (Section &a, Section &b){return *(a.primes.rbegin()) > *(b.primes.rbegin());}

map<pair<int,int>,Section> Map;

bool notPrime[1000001];

int Changed[20000];

list<int> Primes;

void preprocessPrimes(){
    for (int i=2;i<=1000;i++){
        if (!notPrime[i]){
            for (int j=i*i;j<1000001;j+=i){
                notPrime[j] = true;
            }
        }
    }

    for (int i=2;i<1000001;i++){
        if (!notPrime[i]) Primes.push_back(i);
    }
}

set<int> getPrimes(int n){
    auto p = Primes.begin();

    set<int> primes;
    
    while ((*p) <= n && n > 1){
        if (n%(*p)==0){
            primes.insert(*p);
            n /= (*p);
        }else{
            p = next(p);
        }
    }
   
    return primes;
}


Heap<Section> heap(cmp);


int main(){
    preprocessPrimes();

    int n, k;
    cin >> n >> k;

    list<set<int>> sections;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        auto curPrimes = getPrimes(tmp);
        curPrimes.insert(0);
        
        if (sections.size()){
            Section newSection;

            newSection.a = prev(sections.end());

            for (auto p : sections.back()){
                if (curPrimes.count(p)){
                    newSection.primes.insert(p);
                }
            }

            sections.push_back(curPrimes);
            newSection.b = prev(sections.end());


            heap.push(newSection);
            Map.insert({{newSection.a,newSection.b},newSection});
        }else{
            sections.push_back(curPrimes);
        }        
    }


    while (n-- != k){
        auto currSection = heap.get(0);
        heap.pop();

        /*auto it = Map.find({currSection.b,currSection.a});

        if (it != Map.end()){
            int index = heap.getIndex(it->second);
            heap.get(index).primes.insert(1000001);
            heap.upHeap(index);
            heap.pop();
        }*/

        sections.erase(currSection.b);
        *(currSection.a) = currSection.primes;

        Section newSection;

        newSection.a = currSection.a;
        newSection.b = next(currSection.a);


        if (newSection.b == sections.end()) continue;
        
        for (auto p : *newSection.a){
            if (newSection.b->count(p)){
                newSection.primes.insert(p);
            }
        }
        //Map.insert({{newSection.a,newSection.b},newSection});
        heap.push(newSection);
    }

    int best = 1000001;
    for (auto s : sections){
        best = min(best,*s.rbegin());
    }

    cout << best << '\n';


    return 0;
}
