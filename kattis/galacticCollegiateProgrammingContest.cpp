#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Team{
    ll id,a,b;
};

Team Teams[10000000];

int main(){
    int n,m;

    cin >> n >> m;

    for (int i=0;i<n;i++) Teams[i].id = i+1;

    for (int i=0;i<m;i++){
        ll t,p;
        cin >> t >> p;
        Teams[t].a++;
        Teams[t].b += p;
    }

    sort(Teams,Teams+n,[&](auto a, auto b){ return a.a > b.a || (a.a == b.a && a.b < b.b);});
    for (int i=0;i<n;i++){
        if (Teams[i].id == 1){
            cout <<
        }
    }

    return 0;
}