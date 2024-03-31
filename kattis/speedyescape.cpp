#include <iostream>
#include <list>
#include <iomanip>

#define INF 10000000000.0

using namespace std;


double Distances[100][100],Highway[100],Best[100],Min[100];
list<int> Exits;
list<int> Graph[100];
double Dist[100][100];


void apsp(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                Distances[j][k] = min(Distances[j][i] + Distances[i][k],Distances[j][k]);
            }
        }
    }
}


typedef struct path{
    double time, max;
    int current;
} Path;


int main(){
    int n,m,e;

    cin >> n >> m >> e;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            Distances[i][j] = INF;
        }
    }

    for (int i=0;i<m;i++){
        int a,b;
        double l;
        cin >> a >> b >> l;
        a--,b--;
        Distances[a][b] = l/1000;
        Distances[b][a] = l/1000;

        Dist[a][b] = l/1000;
        Dist[b][a] = l/1000;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }


    for (int i=0;i<n;i++){
        Distances[i][i] = 0;
    }

    apsp(n);


    for (int i=0;i<e;i++){
        int tmp;
        cin >> tmp;
        tmp--;
        Exits.push_back(tmp);
    }


    int b,p;

    cin >> b >> p;
    b--,p--;
    for (int i=0;i<n;i++){
        Min[i] = ((double)(Distances[p][i]))/160.0;
    }

    list<Path> queue;
    Path start = {0,0,b};
    queue.push_back(start);

    for (int i=0;i<n;i++){
        Best[i] = INF;
        Best[i] = INF;
    }
    Best[b] = 0;

    while (!queue.empty()){
        auto p = queue.front();
        queue.pop_front();
        int curr = p.current;
        double time = p.time;

        for (auto neigh : Graph[curr]){
            if (time > Min[neigh]) continue;
            double least_speed = Dist[curr][neigh]/(Min[neigh]-time);
            double total_time = time+Dist[curr][neigh]/least_speed;

            double max_speed = max(least_speed,p.max);

            if (max_speed < Best[neigh]){
                Best[neigh] = max_speed;
                Path new_path = {total_time,max_speed,neigh};
                queue.push_back(new_path);
            }
        }
    }
    double least = INF;
    for (auto e : Exits){
        least = min(Best[e],least);
    }

    if (least == INF){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << fixed << setprecision(9) << least << '\n';
    }

    return 0;
}