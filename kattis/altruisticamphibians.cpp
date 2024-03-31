#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

typedef long long ll;

struct Frog{
    ll l,w,h;
};

Frog Frogs[100000];
ll D[100000001];

int main(){
    ll n,d;

    cin >> n >> d;

    for (int i=0;i<n;i++) cin >> Frogs[i].l >> Frogs[i].w >> Frogs[i].h;
    sort(Frogs,Frogs+n,[&](auto a, auto b){return a.w>b.w;});

    int count=0;

    for (int i=0;i<n;i++){
        if (Frogs[i].l + D[Frogs[i].w] > d) count++;
        for (int w=1;w<Frogs[i].w;w++){
            if (w+Frogs[i].w <= 100000000)
                D[w] = max(Frogs[i].h+D[w+Frogs[i].w],D[w]);
        }
    }

    cout << count << '\n';

    return 0;
}