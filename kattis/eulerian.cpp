#include <iostream>
#include <list>

using namespace std;


int Vertices[100000],Visited[100000];
list<int> Graph_un[100000],Graph[100000],Graph_r[100000];

bool bfs(int n){
    list<int> queue;
    queue.push_back(0);
    Visited[0] = 1;

    while (!queue.empty()){
        int curr = queue.front();
        queue.pop_front();

        for (auto neigh : Graph_un[curr]){
            if (!Visited[neigh]){
                queue.push_back(neigh);
                Visited[neigh] = 1;
            }
        }
    }

    for (int i=0;i<n;i++){
        if (!Visited[i]) return false;
    }

    return true;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    
    cin >> n >> m;

    for (int i=0;i<m;i++){
        int a,b;

        cin >> a >> b;
        a--,b--;
        Vertices[a]++;
        Vertices[b]--;
        Graph_un[a].push_back(b);
        Graph_un[b].push_back(a);
        Graph[a].push_back(b);
        Graph_r[b].push_back(a);
    }

    int less=0,more=0,start=-1,end=-1;
    for (int i=0;i<n;i++){
        if (Vertices[i]>0){
            start = i;
            more++;
            if (Vertices[i]>1){
                cout << "no\n";
                return 0;
            }
        }else if (Vertices[i]<0){
            less++;
            end = i;
            if (Vertices[i]<-1){
                cout << "no\n";
                return 0;
            }
        }
    }
    
    if (start > 1 || end > 1){
        cout << "no\n";
        return 0;
    }

    if (!bfs(n)){
        cout << "no\n";
        return 0;
    }
    
    if (start!=-1 && end!=-1){
        cout << start+1 << ' ' << end+1 << '\n';
    }else if(start != -1){
        cout << start+1 << ' ';
        int curr = start;
        while (Graph[curr].size()){
            curr = Graph[curr].front();
            Graph[curr].pop_front();
        }
        cout << curr+1 << '\n';
    }else if (end != -1){
        cout << end+1 << ' ';
        int curr = end;
        while (Graph_r[curr].size()){
            curr = Graph_r[curr].front();
            Graph_r[curr].pop_front();
        }
        cout << curr+1 << '\n';
    }else{
        cout << "anywhere\n";
    }

    return 0;
}