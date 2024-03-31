#include <iostream>
#include <list>
#include <set>

#define INF 10000000

using namespace std;

char Graph[1000][1000];
int Fire[1000][1000];




void work(){
    int w,h;

    cin >> w >> h;

    pair<int,int> start;
    list<pair<int,int>> fires;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> Graph[i][j];
            Fire[i][j] = INF;
            if (Graph[i][j] == '@'){
                start = {i,j};
            }else if (Graph[i][j] == '*'){
                Fire[i][j] = 0;
                fires.push_back({i,j});
            }
        }
    }


    while (fires.size()){
        auto cur = fires.front();
        fires.pop_front();
        int i = cur.first, j = cur.second;

        int f = Fire[i][j]+1;

        if (i && Graph[i-1][j] != '#' && Fire[i-1][j] > f){
            Fire[i-1][j] = f;
            fires.push_back({i-1,j});
        }
        if (j && Graph[i][j-1] != '#' && Fire[i][j-1] > f){
            Fire[i][j-1] = f;
            fires.push_back({i,j-1});
        }
        if (i+1 < h && Graph[i+1][j] != '#' && Fire[i+1][j] > f){
            Fire[i+1][j] = f;
            fires.push_back({i+1,j});
        }
        if (j+1 < w && Graph[i][j+1] != '#' && Fire[i][j+1] > f){
            Fire[i][j+1] = f;
            fires.push_back({i,j+1});
        }
    }
    
    list<pair<pair<int,int>,int>> queue;
    queue.push_back({start,0});
    set<pair<int,int>> visited,visitedFire;
    visited.insert(start);

    while (queue.size()){
        auto cur = queue.front();
        queue.pop_front();

        auto pos = cur.first;
        auto t = cur.second+1;

        int i = pos.first;
        int j = pos.second;

        if (i == h-1 || j == w-1 || !i ||  !j){
            cout << t << '\n';
            return;
        }

        if (i && !visited.count({i-1,j}) && Graph[i-1][j] == '.' &&  Fire[i-1][j] > t){
            queue.push_back({{i-1,j},t});
            visited.insert({i-1,j});
        }
        if (j && !visited.count({i,j-1}) && Graph[i][j-1] == '.' && Fire[i][j-1] > t ){
            queue.push_back({{i,j-1},t});
            visited.insert({i,j-1});
        }
        if (i+1 < h && !visited.count({i+1,j})  && Graph[i+1][j] == '.' && Fire[i+1][j] > t){
            queue.push_back({{i+1,j},t});
            visited.insert({i+1,j});
        }
        if (j+1 < w && !visited.count({i,j+1}) && Graph[i][j+1] == '.' && Fire[i][j+1] > t){
            queue.push_back({{i,j+1},t});
            visited.insert({i,j+1});
        }

    } 

    cout << "IMPOSSIBLE\n";
}


int main(){
    
    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++) work();


    return 0;
}