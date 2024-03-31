#include <bits\stdc++.h>

using namespace std;



void solve(){
    int n;
    char board[30][30];
    double points[30];
    cin >> n;

    for (int i=0;i<n;i++){
        points[i] = 0;
        for (int j=0;j<n;j++){
            cin >> board[i][j];
            if (board[i][j] == '1'){
                points[i]++;
            }else if(board[i][j]=='d'){
                points[i]+=0.5;
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){}
    }



}

int main(){
    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        solve();
    }
}