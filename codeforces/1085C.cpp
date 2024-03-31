#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> pii;

long long dist(pii &a, pii &b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

void createPath(pii &a, pii &b, list<pii> &l){
    for (int i=1;i<=abs(a.first-b.first);i++){
        if (b.first > a.first) l.push_back({a.first+i,a.second});
        else l.push_back({a.first-i,a.second});
    }

    for (int i=1;i<=abs(a.second-b.second);i++){
        if (b.second > a.second) l.push_back({b.first,a.second+i});
        else l.push_back({b.first,a.second-i});
    }
}

int main(){
    vector<pii> v(3);

    for (auto &c : v) cin>>c.first>>c.second;
    sort(v.begin(),v.end());

    pii best = v[0];
    list<pii> sq = {v[0]};

    createPath(v[0],v[1],sq);
    for (auto &p : sq) if (dist(best,v[2]) > dist(p,v[2])) best = p;
    createPath(best,v[2],sq);

    cout << sq.size() << '\n';
    for (auto &p : sq) cout << p.first << ' ' << p.second << '\n';

    return 0;
}