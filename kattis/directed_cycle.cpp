#include <bits/stdc++.h>


using namespace std;

list<int> Graph[500000], Sequence;
set<int> Visited;

bool dfs(int vertex){
    if (Visited.find(vertex) != Visited.end()){
        Sequence.push_back(vertex);
        return true;
    }

    Visited.insert(vertex);
    Sequence.push_back(vertex);
    for (auto neigh : Graph[vertex]){
        if (dfs(neigh)){
            return true;
        }
        Sequence.pop_back();
    }
    Visited.erase(vertex);
    Sequence.pop_back();
    return false;
}

void get_cycles(){

    Visited.clear();
    Sequence.clear();
    dfs(0);
}

int main(){
    int n,m;

    cin >> n >> m;


    for (int i=0;i<m;i++){
        int a,b;

        cin >> a >> b;

        Graph[a].push_back(b);
    }

    get_cycles();

    int last = Sequence.back();
    Sequence.pop_back();
    list<int> result;
    result.push_front(last);
    while (Sequence.size()){
        result.push_front(Sequence.back());
        if (Sequence.back() == last){
            break;
        }
        Sequence.pop_back();
    }
    
    cout << result.front();
    result.pop_front();


    while (result.size()){
        cout << "->" << result.front();
        result.pop_front();
    }

    return 0;
}

/*
4 4
0 1
1 2
2 3
3 3

4 6
0 1
0 2
1 2
2 0
3 3
2 3
*/