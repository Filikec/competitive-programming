#include <iostream>
#include <list>
#include <algorithm>


#define MAX 100001

using namespace std;

bool Start[MAX],Fallen[MAX];
list<int> Graph[MAX];

void work(){

    int n,m;

    cin >> n >> m;

    fill(Start,Start+n+1,1);
    fill(Fallen,Fallen+n+1,0);
    for (int i=1;i<=n;i++){
        Graph[i].clear();
    }

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        Start[b] = 0;
    }
    int result = 0;
    for (int i=1;i<=n;i++){
        if (!Start[i]) continue;
        result++;
        list<int> queue;
        queue.push_back(i);
        Fallen[i] = 1;
        while (queue.size()){
            auto cur = queue.front();
            queue.pop_front();
            
            for (auto neigh : Graph[cur]){
                if (!Fallen[neigh]){
                    queue.push_back(neigh);
                    Fallen[neigh] = 1;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (Fallen[i]) continue;
        result++;
        list<int> queue;
        queue.push_back(i);
        Fallen[i] = 1;
        while (queue.size()){
            auto cur = queue.front();
            queue.pop_front();
            
            for (auto neigh : Graph[cur]){
                if (!Fallen[neigh]){
                    queue.push_back(neigh);
                    Fallen[neigh] = 1;
                }
            }
        }
    }

    cout << result << '\n';

}


int main(){


    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++) work();

    return 0;
}

