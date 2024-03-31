#include <iostream>
#include <unordered_map>
#include <functional>
#include <list>
#include <vector>
#include <map>

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
    map<T,int> lookup;
    function<bool(T&,T&)> cmp;
};


char Map[400][400];
int Dist[400][400];

Heap<pair<int,int>> heap([](auto a, auto b){return Dist[a.first][a.second] < Dist[b.first][b.second];});

int main(){
    int n,m;
    cin >> n >> m;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> Map[i][j];
            Dist[i][j] = 10000000;
            heap.push({i,j});
        }
    }

    int x,y;

    cin >> y >> x;
    y--,x--;


    Dist[y][x] = 1;
    heap.upHeap(heap.getIndex({y,x}));

    int best;

    while (heap.getSize()){
        auto cur = heap.pop();

        if ((!cur.first || cur.first==n-1) && Map[cur.first][cur.second]=='D'){
            best = Dist[cur.first][cur.second];
            break;
        }
        if ((!cur.second || cur.second==m-1) && Map[cur.first][cur.second]=='D'){
            best = Dist[cur.first][cur.second];
            break;
        }

        if (cur.first+1<n && Map[cur.first+1][cur.second]!='#'){
            if (Dist[cur.first][cur.second]+(Map[cur.first+1][cur.second]=='c') < Dist[cur.first+1][cur.second]){
                Dist[cur.first+1][cur.second] = Dist[cur.first][cur.second]+(Map[cur.first+1][cur.second]=='c');
                heap.upHeap(heap.getIndex({cur.first+1,cur.second}));
            }
        }

        if (cur.second+1<m && Map[cur.first][cur.second+1]!='#'){
            if (Dist[cur.first][cur.second]+(Map[cur.first][cur.second+1]=='c') < Dist[cur.first][cur.second+1]){
                Dist[cur.first][cur.second+1] = Dist[cur.first][cur.second]+(Map[cur.first][cur.second+1]=='c');
                heap.upHeap(heap.getIndex({cur.first,cur.second+1}));
            }
        }

        if (cur.second-1>=0 && Map[cur.first][cur.second-1]!='#'){
            if (Dist[cur.first][cur.second]+(Map[cur.first][cur.second-1]=='c') < Dist[cur.first][cur.second-1]){
                Dist[cur.first][cur.second-1] = Dist[cur.first][cur.second]+(Map[cur.first][cur.second-1]=='c');
                heap.upHeap(heap.getIndex({cur.first,cur.second-1}));
            }
        }

        if (cur.first-1>=0 && Map[cur.first-1][cur.second]!='#'){
            if (Dist[cur.first][cur.second]+(Map[cur.first-1][cur.second]=='c') < Dist[cur.first-1][cur.second]){
                Dist[cur.first-1][cur.second] = Dist[cur.first][cur.second]+(Map[cur.first-1][cur.second]=='c');
                heap.upHeap(heap.getIndex({cur.first-1,cur.second}));
            }
        }
    }

    cout << best << '\n';

    return 0;
}