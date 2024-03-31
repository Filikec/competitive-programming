#include <iostream>
#include <list>
#include <set>

using namespace std;

set<pair<int,int>> V;


int most,l,r,dif=10001;

void updateMost(int a, int b){
    if (a+b > most || (most == a+b && abs(a-b) < dif)){
        most = a+b;
        r = a;
        l = b;
        dif = abs(a-b);
    }
}

int main(){
    int c,n;

    cin >> c >> n;

    list<pair<int,int>> got;
    got.push_back({0,0});

    for (int i=0;i<n;i++){
        int m;
        cin >> m;
        list<pair<int,int>> tmp;
        for (auto p : got){
            if (p.first+m <= c){
                pair<int,int> nP = {p.first+m,p.second};
                if (!V.count(nP)) V.insert(nP), updateMost(nP.first,nP.second),tmp.push_back(nP);
            }
            if (p.second+m <= c){
                pair<int,int> nP = {p.first,p.second+m};
                if (!V.count(nP)) V.insert(nP), updateMost(nP.first,nP.second),tmp.push_back(nP);
            }
        }
        got.splice(got.end(),tmp);
    }

    cout << max(l,r) << ' ' << min(l,r) << '\n';


    return 0;
}
