#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <set>
#include <iomanip>


using namespace std;


float Dist[1000][1000];

int encode(int a, int b){
    return a*1000+b;
}

void work(){
    int n;

    cin >> n;

    vector<pair<float,float>> points;

    for (int i=0;i<n;i++){
        float a,b;

        cin >> a >> b;

        for (int j=0;j<i;j++){
            float aDif, bDif;
            aDif = a-points[j].first, bDif = b-points[j].second;
            float dist = sqrt(aDif*aDif+bDif*bDif);
            Dist[j][i] = dist;
            Dist[i][j] = dist;
        }
        points.push_back({a,b});
    }   

    unordered_set<int> visited;
    unordered_set<int> used;
    vector<pair<int,int>> heap;

    visited.insert(0);
    for (int i=1;i<n;i++){
        heap.push_back({0,i});
        push_heap(heap.begin(),heap.end(),[&](pair<int,int> a,pair<int,int> b) {return Dist[a.first][a.second] > Dist[b.first][b.second];});
        used.insert(encode(i,0));
        used.insert(encode(0,i));
    }

    float needed = 0;
    while (heap.size()){
        auto cur = heap.front();
        pop_heap(heap.begin(),heap.end(),[&](pair<int,int> a,pair<int,int> b) {return Dist[a.first][a.second] > Dist[b.first][b.second];});
        heap.pop_back();

        if (visited.count(cur.second)){
            continue;
        }

        visited.insert(cur.second);
        needed += Dist[cur.first][cur.second];
        
        for (int i=0;i<n;i++){
            if (used.count(encode(cur.second,i))) continue;
            used.insert(encode(cur.second,i));
            used.insert(encode(i,cur.second));
            heap.push_back({cur.second,i});
            push_heap(heap.begin(),heap.end(),[&](pair<int,int> a,pair<int,int> b) {return Dist[a.first][a.second] > Dist[b.first][b.second];});
        }
    }

    cout << fixed << setprecision(2) << needed << '\n';
    cout << '\n';
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        work();
    }


    return 0;
}