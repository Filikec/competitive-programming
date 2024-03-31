#include <iostream>
#include <cmath>
#include <list>

using namespace std;

int Active[10001][10001];
list<pair<int,int>> Goblins;

double get_dist(int x1, int y1, int x2, int y2){
    double d_x = x1-x2, d_y = y1-y2;

    return sqrt(d_y*d_y+d_x*d_x);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int g;
    cin >> g;

    for (int i=0;i<g;i++){
        int x,y;

        cin >> x >> y;

        Active[x][y]++;
        Goblins.push_back(make_pair(x,y));
    }

    int m;
    cin >> m;
    
    for (int i=0;i<m;i++){
        int x,y,r;
        cin >> x >> y >> r;

        for (int i=x-r;i<=x+r;i++){
            for (int j=y;get_dist(x,y,i,j)<=r;j++){
                if (i > -1 && i <= 10000 && j > -1 && j <= 10000){
                    Active[i][j] = 0;
                }
                if (i > -1 && i <= 10000 && y-(j-y) > -1 && y-(j-y) <= 10000){
                    Active[i][y-(j-y)] = 0;
                }
            }
        }
    }
    
    int sum = 0;
    for (auto e : Goblins){
        if (Active[e.first][e.second]) sum++;
    }
    cout << sum << '\n';

    return 0;
}

