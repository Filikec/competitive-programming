#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <list>
#include <cmath>
#include <set>

using namespace std;

pair<long double,long double> Points[4];

long double getD(pair<long double,long double> &a, pair<long double,long double> &b){
    long double x = a.first-b.first, y= a.second-b.second;

    return sqrt(x*x+y*y);
}


list<int> Graph[100];



bool dfs(int c, int w, int n, list<int> &g){
    if (!w){
        set<int> s;
        for (auto v : g){
            for (auto e : Graph[v]) s.insert(e);
        }
        if (s.size()==4) return true;
        return false;
    }
    for (int i=c;i<n;i++){
        g.push_back(i);
        bool p = dfs(i+1,w-1,n,g);
        g.pop_back();
        if (p) return true;    
        
    } 
    return false;
}

int main(){

    long double l,w,n,r;

    cin>>l>>w>>n>>r;

    Points[0] = {-l/2.0,0.0};
    Points[1] = {l/2.0,0.0};
    Points[2] = {0.0,-w/2.0};
    Points[3] = {0.0,w/2.0};


    for (int i=0;i<n;i++){
        long double x,y;
        cin>>x>>y;
        pair<long double,long double> p = {x,y};
        for (int j=0;j<4;j++){
            if (getD(Points[j],p)<=r){
                Graph[i].push_back(j);
            }
        }
    }

    list<int> g;
    for (int i=1;i<=4;i++){
        g.clear();
        if (dfs(0,i,n,g)){
            cout << i << "\n";
            return 0;
        }
    }

    cout << "Impossible\n";

    return 0;
}


