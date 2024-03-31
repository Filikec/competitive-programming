#include <iostream>
#include <list>

using namespace std;

list<int> Graph[1000001];
int Blocked[1000001];

list<int> Queue;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;

    cin >> n >> m;

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        Blocked[b]++;
        Graph[a].push_back(b);
    }

    for (int i=1;i<=n;i++){
        if (!Blocked[i]) Queue.push_back(i);
    }

    list<int> pulled;

    while (Queue.size()){
        auto cur = Queue.front();
        Queue.pop_front();

        pulled.push_back(cur);

        for (auto n : Graph[cur]){
            Blocked[n]--;
            if (!Blocked[n]){
                Queue.push_back(n);
            }
        }
    }

    if (pulled.size()<n){
        cout << "IMPOSSIBLE\n";
    }else{
        for (auto p : pulled){
            cout << p << '\n';
        }
    }

    return 0;
}