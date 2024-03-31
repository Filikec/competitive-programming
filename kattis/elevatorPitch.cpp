#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int Grid[500][500];
bool Visited[500][500];
int Needed;
vector<pair<int,int>> Highest;


bool possible(int i, int j, int h, int w){
    return i >= 0 && j >= 0 && i < h && j < w;
}


void bfs(int i, int j, int h, int w){
    list<pair<int,int>> queue;
    queue.push_back({i,j});

    while (queue.size()){
        auto cur = queue.front();
        queue.pop_front();
        
        i = cur.first, j = cur.second;

        //cout << i << ' ' << j << "<<\n";

        if (possible(i+1,j,h,w) && Grid[i+1][j] <= Grid[i][j] && !Visited[i+1][j]){
            Visited[i+1][j] = 1;
            queue.push_back({i+1,j});
        }
        //cout << possible(i-1,j,h,w) << ' ' << Grid[i-1][j] << ' ' << !Visited[i-1][j] << '\n';
        if (possible(i-1,j,h,w) && Grid[i-1][j] <= Grid[i][j] && !Visited[i-1][j]){
            Visited[i-1][j] = 1;
            queue.push_back({i-1,j});
        }
        if (possible(i,j+1,h,w) && Grid[i][j+1] <= Grid[i][j] && !Visited[i][j+1]){
            Visited[i][j+1] = 1;
            queue.push_back({i,j+1});
        }
        if (possible(i,j-1,h,w) && Grid[i][j-1] <= Grid[i][j] && !Visited[i][j-1]){
            Visited[i][j-1] = 1;
            queue.push_back({i,j-1});
        }
    }

}

int main(){

    int h,w;

    cin >> h >> w;

    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> Grid[i][j];
            Highest.push_back({i,j});
            push_heap(Highest.begin(),Highest.end(),[&](pair<int,int> a, pair<int,int>  b){return Grid[a.first][a.second]<Grid[b.first][b.second];});
        }
    }



    while (Highest.size()){
        auto cur = Highest.front();
        pop_heap(Highest.begin(),Highest.end(),[&](pair<int,int> a, pair<int,int>  b){return Grid[a.first][a.second]<Grid[b.first][b.second];});
        Highest.pop_back();

        //cout << cur.first << ' ' << cur.second << "<\n";

        if (!Visited[cur.first][cur.second] && Grid[cur.first][cur.second] > 1){
            Visited[cur.first][cur.second] = 1;
            Needed++;
            bfs(cur.first,cur.second,h,w);
        }
    }
    cout << Needed << '\n';

    return 0;
}