#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

#define cmp heap.begin(),heap.end(),[&](pair<int,int> a, pair<int,int>b){return a.second > b.second;}

using namespace std;


int DistancesStart[10000], DistanceEnd[10000];
list<pair<int,int>> Graph[10000];


void spfa(int s, int *dist, int n){
    fill(dist,dist+n,2147483647);
    
    vector<pair<int,int>> heap;

    heap.push_back({s,0});
    dist[s] = 0;
    
    while (heap.size()){
        auto cur = heap.front();
        pop_heap(cmp);
        heap.pop_back();
        auto c = cur.first, d = cur.second;
        if (d != dist[c]) continue;

        for (auto p : Graph[c]){
            auto neigh = p.first;
            auto l = p.second;

            if (dist[neigh] > d+l){
                dist[neigh] = d+l;
                heap.push_back({neigh,d+l});
                push_heap(cmp);
            }
        }
    }

}


int main(){


    int n,m;

    cin >> n >> m;


    for (int i=0;i<m;i++){
        int a,b,d;

        cin >> a >> b >> d;

        Graph[a].push_back({b,d});
        Graph[b].push_back({a,d});
    }


    spfa(0,DistancesStart,n);
    spfa(n-1,DistanceEnd,n);


    int shortest = DistancesStart[n-1];
    

    int sum = 0;
    for (int i=0;i<n;i++){
        for (auto p : Graph[i]){
            if (DistancesStart[i]+p.second+DistanceEnd[p.first] == shortest){
                sum += p.second;
            }   
        }
    }

    cout << sum*2 << '\n';

    return 0;
}