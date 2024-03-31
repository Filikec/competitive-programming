#include <iostream>
#include <list>

using namespace std;


char Field[1000][1000];

bool takable(int x1, int y1, int x2, int y2){
    auto c1 = Field[y1][x1], c2 = Field[y2][x2];

    if (c1 == '#') return false;
    if (c1 == 'F' && c2 == '.' || c2 == 'J') return true;
    if (c1 == 'J' && c2 == '.') return true;
    return false;
}

int main(){

    int r,c;

    cin >> r >> c;

    list<pair<int,int>> fires1, jones1, fires2, jones2;
    list<pair<int,int>> *fires = &fires1, *jones = &jones1, *firesSave = &fires2, *jonesSave = &jones2;

    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cin >> Field[i][j];
            if (Field[i][j] == 'F') fires1.push_back({i,j});
            if (Field[i][j] == 'J') jones1.push_back({i,j});
        }
    }
        
    while (true){
        while (jones->size()){
            while (fires->size()){
                auto square = fires->front();
                int y = square.first, x = square.second;
                fires->pop_front();

                auto cur = Field[y][x];

                if (y){
                    if (takable(x,y,x,y-1)){
                        Field[y-1][x] = cur;
                        firesSave->push_back({y-1,x});
                    }
                }
                if (y+1<r){
                    if (takable(x,y,x,y+1)){

                    }
                }
            }
        }
    }
    

    return 0;
}