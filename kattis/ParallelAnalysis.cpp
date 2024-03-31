#include <iostream>
#include <unordered_map>
#include <list>
#include <set>


using namespace std;


bool Independent[40000], Used[40000];
int Dist[40000];
list<int> Graph[40000];
unordered_map<int, int> Last;



int rec(int node){
    if (Dist[node]){
        return Dist[node];
    }

    int most = 0;
    for (auto neigh : Graph[node]){
        most = max(most,rec(neigh)+1);
    }

    Dist[node] = most;

    return most;
}

void work(int c){

    int n;

    cin >> n;
    
    int r = 0;

    Last.clear();

    for (int i=0;i<n;i++){
        Independent[i] = true;
        Used[i] = false;
        Dist[i] = 0;
        Graph[i].clear();

        int ins;
        cin >> ins;

        for (int j=0;j<ins-1;j++){
            int tmp;
            cin >> tmp;
            
            auto it = Last.find(tmp);

            if (it == Last.end()) continue;
            Independent[i] = false;
            Graph[it->second].push_back(i);
        }
        int last;
        cin >> last;
        Last[last] = i;
    }

    int most = 0;
    for (int i=0;i<n;i++){
        if (Independent[i]){
            most = max(most,rec(i));
        }
    }

    cout << ++c << ' ' << most+1 << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        work(i);
    }


    return 0;
}