#include <iostream>

using namespace std;


char Board1[100][100],Board2[100][100];

bool inBounds(int w,int h, int x, int y){
    return ( x > -1 && x < w && y > -1 && y < h);
}

void move(int x1, int y1, int x2, int y2){
    char cur = Board1[y1][x1], neigh = Board1[y2][x2];
    if (cur == 'R' && neigh == 'C'){
        Board2[y2][x2] = 'R';
    }else if (cur == 'S' && neigh == 'P'){
        Board2[y2][x2] = 'S';
    }else if (cur == 'P' && neigh == 'R'){
        Board2[y2][x2] = 'P';
    }
}

void step(int r, int c){
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            if (i-1 >= 0){
                move(j,i,j,i-1);
            }
            if (i+1 < r){
                move(j,i,j,i+1);
            }
            if (j-1 >= 0){
                move(j,i,j-1,i);
            }
            if (i+1 < c){
                move(j,i,j+1,i);
            }
        }
    }

    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            Board1[i][j] = Board2[i][j];
        }
    }
}


void work(){

    int r,c,n;

    cin >> r >> c >> n;

    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cin >> Board1[i][j];
            Board2[i][j] = Board1[i][j];
        }
    }

    for (int i=0;i<n;i++){
        step(r,c);
    }
    cout << '\n';
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cout << Board1[i][j];
        }
        cout << '\n';
    }       
    cout << '\n';

}

int main(){

    int cases;
    cin >> cases;

    for (int c=0;c<cases;c++){
        work();
    }


    return 0;
}