#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <functional>

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
    T elements[100000];
    unordered_map<T,int> lookup;
    function<bool(T&,T&)> cmp;
};


string operate(string const &bin, string const &operation){
    string newBin;

    for (int i=0;i<bin.size();i++){
        char op = operation[i], b = bin[i];

        if (op == 'F'){
            if (b == '1') b = '0';
            else b = '1';
        }else if (op == 'S'){
            b = '1';
        }else if (op == 'C'){
            b = '0';
        }else{
            ;// nothing if N
        }

        newBin += b;
    }

    return newBin;
}




void work(){
    int l,o,n;

    map<string,int> Costs;
    cin >> l >> o >> n;

    for (int i=0;i<o;i++){
        string s;
        cin >> s;
        int c;
        cin >> c;
        auto it = Costs.find(s);
        if (it == Costs.end()) Costs[s] = c;
        else Costs[s] = min(Costs[s],c);
    }

    for (int i=0;i<n;i++){
        string start, end;
        cin >> start >> end;

        unordered_map<string,int> visited;
        Heap<string> nodes([&] (string a, string b) {return visited[a] < visited[b];});

        nodes.push(start);
        visited[start] = 0;

        while (nodes.getSize()){
            auto cur = nodes.get(0);
            nodes.pop();

            if (cur == end) break;
            
            for (auto cost : Costs){
                string newBin = operate(cur,cost.first);
                int newCost = visited[cur] + cost.second;

                if (!visited.count(newBin)){
                    visited[newBin] = newCost;
                    nodes.push(newBin);                   
                }else if (visited[newBin] > newCost){
                    visited[newBin] = newCost;
                    nodes.upHeap(nodes.getIndex(newBin));
                }
            }
        }

        if (visited.count(end)){
            cout << visited[end] << ' ';
        }else{
            cout << "NP ";
        }
    }

    
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        work();
    }

    return 0;
}