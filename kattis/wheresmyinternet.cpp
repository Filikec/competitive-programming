#include <iostream>
#include <list>

using namespace std;


list<int> Graph[200001];
int Connected[200001];

int bfs(){
    int count = 1;
    list<int> queue;
    queue.push_back(1);
    Connected[1] = 1;
    while (!queue.empty()){
        int curr = queue.front();
        queue.pop_front();
       
        for (auto neigh : Graph[curr]){
            if (Connected[neigh]) continue;
            queue.push_back(neigh);
            Connected[neigh] = 1;
            count++;
        }

    }
    return count;
}

int get_int(){
    int num=0;
    char c;
    while ((c=getchar())>='0'){
        num = num*10+c-'0';
    }
    return num;
}

int main(){
    int n,m;
    n = get_int();
    m = get_int();
    for (int i=0;i<m;i++){
        int a,b;

        a = get_int();
        b = get_int();

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    if (bfs()==n){
        cout << "Connected\n";
    }else{
        for (int i=2;i<=n;i++){
            if (!Connected[i]) cout << i << "\n";
        }
    }

    
    return 0;
}