#include <iostream>
#include <vector>
#include <algorithm>
#include <list>


using namespace std;


#define INF 10000000;
#define cmp queue.begin(),queue.end(),[&](pair<int,int> a, pair<int,int> b){return a.second>b.second;}

int Distance[2000][2000];

void work(){

    int Visited[2000];
    list<int> Graph[2000];

    int m,c;

    cin >> m >> c;

    for (int i=0;i<c;i++) Visited[i] = 0;


    for (int i=0;i<(c*(c-1))/2;i++){
        int a,b,d;

        cin >> a >> b >> d;

        Graph[a].push_back(b);
        Graph[b].push_back(a);

        Distance[a][b] = d;
        Distance[b][a] = d;
    }

    vector<pair<int,int>> queue;
    queue.push_back({0,0});

    int distance = 0;

    while (queue.size()){
        auto cur = queue.front();
        pop_heap(cmp);
        queue.pop_back();

        if (Visited[cur.first]) continue;
        Visited[cur.first] = 1;

        distance += cur.second;

        for (auto neigh : Graph[cur.first]){
            queue.push_back({neigh,Distance[cur.first][neigh]});
            push_heap(cmp);
        }
    }

    if (distance+c <= m){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }

}


int main(){


    int cases;

    cin >> cases;


    for (int i=0;i<cases;i++){
        work();
    }


    return 0;
}