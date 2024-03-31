#include <iostream>
#include <list>
#include <map>


using namespace std;

typedef long long ll;
typedef long double ld;

struct Bus{
    int a,b;
    ll dep, arr;
    ld p;
};


Bus Buses[1000000];
list<int> Graph[1000000];
list<int> A[1000000], B[1000000];
ld Probs[1000000];

ld best(int bus){
    if (Probs[bus]!=-1) return Probs[bus];
    if (Buses[bus].b==1){
        cout << bus << ' ' << Buses[bus].p << '\n';
        Probs[bus] = Buses[bus].p;
        return Buses[bus].p;
    }

    ld bestP = 1;
    for (auto b : Graph[bus]){
        bestP *= 1-best(b);
    }
    
    Probs[bus] = 1-bestP;
    cout << bus << ' ' << Probs[bus] << '\n';

    return bestP;
    
}

int main(){
    int n,m;
    ll k;

    cin >> m >> n >> k;

    for (int i=0;i<m;i++){
        int a, b;
        ll dep,ar;
        ld p;
        cin >> a >> b >> dep >> ar >> p;
        Buses[i] = {a,b,dep,ar,p};
        A[a].push_back(i);
        B[b].push_back(i);
        Probs[i] = -1;
    }

    for (int i=0;i<m;i++){
        auto bus = Buses[i];
        for (auto b : A[bus.b]){
            if (bus.arr < Buses[b].dep){
                Graph[i].push_back(b);
            }
        }
    }
    
    ld bestP = 0;
    for (auto b : A[0]){
        bestP += best(b);
    }
    cout << bestP << '\n';

    return 0;
}
