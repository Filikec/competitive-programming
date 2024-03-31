#include <iostream>

char curChar = 'a';

using namespace std;

char dfs(int x, int y,int area[100][100], char sinks[100][100], int h, int w){
    if (sinks[y][x]){
        return sinks[y][x];
    }
    int nextX = x, nextY = y;


    if (y-1 >= 0 && area[y-1][x] < area[nextY][nextX]) nextY = y-1, nextX = x;
    if (y+1 < h && area[y+1][x] < area[nextY][nextX]) nextY = y+1, nextX = x;
    if (x-1 >= 0 && area[y][x-1] < area[nextY][nextX]) nextY = y, nextX = x-1;
    if (x+1 < w && area[y][x+1] < area[nextY][nextX]) nextY = y, nextX = x+1;

    if (nextX == x && nextY == y){
        sinks[y][x] = curChar;
        return curChar++;
    }

    sinks[y][x] = dfs(nextX,nextY,area,sinks,h,w);

    return sinks[y][x];    
}


void work(){
    int area[100][100];
    char sinks[100][100];
    int w,h;

    curChar = 'a';

    cin >> h >> w;

    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> area[i][j];
            sinks[i][j] = 0;
        }
    }

    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            dfs(j,i,area,sinks,h,w);
        }
    }

    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cout << sinks[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";

    
}       




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++) cout << "Case #" << c+1 << ":\n", work();


    return 0;
}