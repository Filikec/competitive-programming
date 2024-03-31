#include <bits/stdc++.h>

using namespace std;

list<int> Graph[10001];
int Money[10001], Visited[10001];

int explore(int start){
    int result=0;
    
    if (Visited[start]) return 0;

    list<int> queue;
    queue.push_back(start);
    Visited[start] = 1;

    while (queue.size()){
        auto cur = queue.front();
        queue.pop_front();
        
        result += Money[cur];

        for (auto neigh : Graph[cur]){
            if (!Visited[neigh]) queue.push_back(neigh), Visited[neigh] = 1;
        }   

        
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;

    cin >> n >> m;


    for (int i=0;i<n;i++){
        cin >> Money[i];
    }


    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (int i=0;i<n;i++){
        if (explore(i)){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << "POSSIBLE\n";
    return 0;
}