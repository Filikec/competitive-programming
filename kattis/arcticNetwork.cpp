#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cmath>
#include <unordered_set>
#include <set>
#include <iomanip>

#define cmp maxHeap.begin(),maxHeap.end(),[&](pair<pair<int,int>,double> a, pair<pair<int,int>,double> b){return a.second < b.second;}

using namespace std;

double Dist[500][500];

void work(){

    
    int s,o;

    cin >> s >> o;
    

    list<pair<double,double>> outposts;
    vector<pair<pair<int,int>,double>> maxHeap;
    
    for (int i=0;i<o;i++){
        double x,y;
        cin >> x >> y;
        int in = 0;
        for (auto p : outposts){
            double xDif = x-p.first, yDif = y-p.second;
            Dist[in][i] = sqrt(xDif*xDif+yDif*yDif);
            maxHeap.push_back({{in,i},Dist[in][i]});
            push_heap(cmp);
            in++;
        }
        outposts.push_back({x,y});
    }

    unordered_set<int> sats;
    set<pair<int,int>> visited;
    double result = 0;

    while (s && maxHeap.size()){
        auto cur = maxHeap.front().first;
        pop_heap(cmp);
        maxHeap.pop_back();

        cout << cur.first << ' ' << cur.second << '\n';

        if (visited.count(cur)) continue;
        visited.insert(cur);

        int needed = 2-sats.count(cur.first)-sats.count(cur.second);
        if (needed > s){
            continue;
        }
        s -= needed;
        Dist[cur.first][cur.second] = 0;
        for (int i=0;i<o;i++){
            for (int j=i+1;j<o;j++){
                if (Dist[i][j] > Dist[min(i,cur.first)][max(i,cur.first)]+Dist[min(j,cur.first)][max(j,cur.first)]){
                    Dist[i][j] = Dist[min(i,cur.first)][max(i,cur.first)]+Dist[min(j,cur.first)][max(j,cur.first)];
                    cout << i << "->" << j << ' ' << Dist[i][j] << '\n';
                    maxHeap.push_back({{i,j},Dist[i][j]});
                    push_heap(cmp);
                }
            }
        }
    }
    
    while (maxHeap.size()){
        auto cur = maxHeap.front().first;
        pop_heap(cmp);
        maxHeap.pop_back();

        int needed = 2-sats.count(cur.first)-sats.count(cur.second);
        if (needed){
            result = Dist[cur.first][cur.second];
            break;
        }
    }

    cout << fixed << setprecision(2) <<  result << '\n';
}

int main(){


    int cases;


    cin >> cases;

    for (int c=0;c<cases;c++){
        work();
    }




    return 0;
}