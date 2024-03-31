#include <bits/stdc++.h>


using namespace std;


int Nodes[10001][3]; //0 - marbles, 1 - parent, 2 - child count;
int N;


void solve(){
    list<int> gen;
    for (int i=1;i<=N;i++){
        Nodes[i][0] = 0;
        Nodes[i][1] = -1;
        Nodes[i][2] = 0;
    }
    for (int i=0;i<N;i++){
        int v,m,c;
        cin >> v >> m >> c;
        Nodes[v][0] = m;
        Nodes[v][2] = c;
        if (!c) gen.push_back(v);
        for (int j=0;j<c;j++){
            int a;
            cin >> a;
            Nodes[a][1] = v;
        }
    }

    int steps = 0;
    while (gen.size()){
        auto current = gen.front();
        gen.pop_front();
        if (Nodes[current][1] == -1) break;
        if (Nodes[current][0] > 1){
            steps += Nodes[current][0]-1;
            Nodes[Nodes[current][1]][0] += Nodes[current][0]-1;
        }else if (Nodes[current][0] <= 0){
            steps += abs(Nodes[current][0])+1;
            Nodes[Nodes[current][1]][0] -= abs(Nodes[current][0])+1;
        }
        Nodes[Nodes[current][1]][2]--;
        if (!Nodes[Nodes[current][1]][2]) gen.push_back(Nodes[current][1]);
    }   
    cout << steps << "\n";
}


int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (cin >> N){
        if (!N) break;
        solve();

    }


    return 0;
}