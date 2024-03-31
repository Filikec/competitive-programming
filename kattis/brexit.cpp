#include <iostream>
#include <list>


using namespace std;


int Partners[200001][2], Out[200001]; //0-start,1-lost
list<int> Graph[200001];


void bfs(int s){
    list<int> queue;
    queue.push_back(s);
    Out[s] = 1;

    while (!queue.empty()){
        int curr = queue.front();
        queue.pop_front();

        for (auto neigh : Graph[curr]){
            if (Out[neigh]) continue;
            Partners[neigh][1]++;
            if (Partners[neigh][1]*2 >= Partners[neigh][0]) queue.push_back(neigh), Out[neigh] = 1;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, p, h, f;

    cin >> n >> p >> h >> f;

    for (int i=0;i<p;i++){
        int a,b;

        cin >> a >> b;
        
        Graph[a].push_back(b);
        Graph[b].push_back(a);

        Partners[a][0]++;
        Partners[b][0]++;
    }

    bfs(f);

    if (Out[h]){
        cout << "leave\n";
    }else{
        cout << "stay\n";
    }

    return 0;
}