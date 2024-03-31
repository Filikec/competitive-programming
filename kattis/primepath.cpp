#include <bits/stdc++.h>

using namespace std;


list<int> G[10000];
int D[10000];


constexpr bool is_prime(int p){
    for (int i=2;i<=sqrt(p);i++) if (p%i==0) return 0;
    return 1;
}

constexpr bool is_connected(int p1, int p2){
    return ((p1%10 == p2%10) + (p1/10%10 == p2/10%10) + (p1/100%10 == p2/100%10) + (p1/1000 == p2/1000)) == 3;
}

constexpr vector<list<int>> preprocess(){
    vector<list<int>> v(9999+1);
    if (!is_constant_evaluated()){
        cout << "ok\n";
    }
    

    return v;
}



void bfs(int a, int b){
    list<int> q = {a};
    for (int i=1000;i<=9999;i++) D[i]=1000000;
    D[a]=0;
    constexpr auto G = preprocess(); 
    while (q.size()){
        auto cur = q.front();
        q.pop_front();
        if (cur == b){
            cout << D[cur] << '\n';
            return;
        }
        for (auto n : G[cur]){
            if (D[n] > D[cur]+1) D[n] = D[cur]+1, q.push_back(n);
        }
    }
    cout << "impossible\n";

}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    preprocess();
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        bfs(n,m);
    }
    
    return 0;
}