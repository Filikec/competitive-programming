#include <iostream>
#include <list>

#define INF 10000000000

using namespace std;

typedef struct depart{
    int s, e, t;
} Depart;

long long Distances[500][500], Inspection[500], Max_flow[1003][1003];
int N, M;
list<int> Graph[1003];
Depart Departures[500];



 
void spfa(){

    for (int k=0;k<N;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                Distances[i][j] = min(Distances[i][j],Distances[i][k]+Distances[k][j]);
            }
        }
    }
}


bool bfs(int s, int e){
    list<int> queue;
    bool f = false;
    queue.push_back(0);
    int Prev[1003];
    
    for (int i=0;i<1003;i++) Prev[i] = -1;

    while (!queue.empty()){
        int curr = queue.front();
        queue.pop_front();
        
        if (curr == e){
            f = true;
            break;
        }
        
        for (auto neigh : Graph[curr]){
            if (Max_flow[curr][neigh] && Prev[neigh]==-1) queue.push_back(neigh), Prev[neigh] = curr;
        }
    }

    if (!f) return false;

    int curr = e;
    while (Prev[curr] != -1){
        Max_flow[Prev[curr]][curr] = 0;
        Max_flow[curr][Prev[curr]] = 1;
        curr = Prev[curr];
    }

    return true;

}

void max_flow(){
    while (bfs(0,M+502)){
        ;
    }
}

int main(){
    cin >> N >> M;

    for (int i=0;i<N;i++){
        cin >> Inspection[i];
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> Distances[i][j];
            if (i != j) Distances[i][j] += Inspection[j];
        }
    }

    spfa();


    for (int i=0;i<M;i++){
        int s,e,t;
        cin >> s >> e >> t;
        Departures[i] = {s-1,e-1,t};
    }
    list<pair<int,int>> original;
    for (int i=0;i<M;i++){
        Graph[0].push_back(i+1);
        Graph[i+501].push_back(M+502);

        Max_flow[0][i+1] = 1;
        Max_flow[i+501][M+502] = 1;

        for (int j=0;j<M;j++){
            if (Departures[i].t + Distances[Departures[i].s][Departures[i].e] +  Distances[Departures[i].e][Departures[j].s] <= Departures[j].t){
                Graph[i+1].push_back(j+501);
                original.push_back(make_pair(i+1,j+501)); 
                Graph[j+501].push_back(i+1);

                Max_flow[i+1][j+501] = 1;
            } 
        }
    }
    
    max_flow();

    int count = 0;
    for (auto p : original){
        if (Max_flow[p.first][p.second]==0)count++;
    }

    cout << M-count << '\n';

}