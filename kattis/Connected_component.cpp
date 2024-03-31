#include <bits/stdc++.h>



using namespace std;



typedef struct set_{
    int p;
    int size;
} Set;


list<int> Graph[500000],Sequence;
Set Sets[500000];
int Node_set[500000],Edges[100000000],Used[100000000],Visited[100000000];

void find_components(int node=0){
    if (Visited[node]){
        if (Node_set[Sequence.back()] != Node_set[node]){
            for (auto it = Sequence.rbegin();it!=Sequence.rend();it++){
                
            }
        }
        
    }
}

int main(){

    int n,m;

    cin >> n >> m;

    for (int i=0;i<n;i++){
        Sets[i] = {-1,1};
        Node_set[i] = i;
    }

    for (int i=0;i<m;i++){
        int a,b;

        cin >> a >> b;
        Edges[i] = n;
        if (a!=b) Graph[a].push_back(i);
    }

    find_components();

    return 0;
}