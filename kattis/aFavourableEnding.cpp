#include <iostream>
#include <list>
#include <string>

using namespace std;

typedef long long ll;

list<int> G[400];
bool F[400];
ll P[400];

ll getP(int i){
    if (P[i]) return P[i];

    for (auto n : G[i]){
        P[i] += getP(n);
    }

    if (!P[i]) P[i] = 1;

    return P[i];
}

void work(){
    int n;
    cin >> n;

    for (int i=0;i<400;i++){
        G[i].clear();
        F[i] = false;
        P[i] = 0;
    }

    for (int i=0;i<n;i++){
        int p;
        cin >> p;
        string s;
        cin >> s;
        p--;
        if (s == "favourably"){
            F[p] = 1;
        }else if (s == "catastrophically") continue;
        else{
            int a,b,c;
            cin >> b >> c;
            a = stoi(s);
            a--,b--,c--;
            G[a].push_back(p);
            G[b].push_back(p);
            G[c].push_back(p);
        }   
    }

    ll count=0;
    
    for (int i=0;i<400;i++){
        if (F[i]) count += getP(i);
    }
    cout << count << '\n';
}

int main(){


    int c;
    cin >> c;
    for (int i=0;i<c;i++) work();


    return 0;
}
