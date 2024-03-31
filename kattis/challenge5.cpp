#include <iostream>
#include <list>

using namespace std;

int Used[1000], Time[1000][1000], Dist[1000];

int main(){
    int n, s, t;
    cin >> n >> s >> t;

    for (int i=0;i<n;i++){
        Dist[i] = 1000000000;
        for (int j=0;j<n;j++){
            int t;
            cin >> t;
            Time[i][j] = t;
        }
    }

    list<int> queue;
    queue.push_back(s);
    Dist[s] = 0;

    while(queue.size()){
        auto cur = queue.front();
        queue.pop_front();

        Used[cur]=0;

        for (int i=0;i<n;i++){
            if (Dist[cur]+Time[cur][i] < Dist[i]){
                Dist[i] = Dist[cur]+Time[cur][i];
                if (!Used[i]) Used[i]=1, queue.push_back(i);
            }
        }
    }

    cout << Dist[t] << '\n';


    return 0;
}