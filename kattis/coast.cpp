#include <bits/stdc++.h>

using namespace std;


int Board[1000][1000];
int Count;

void work(int i, int j){
    if (Board[i][j] == -1) return;
    

}


int main(){


    int n,m;

    cin >> n >> m;


    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> Board[i][j];
        }
    }


    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            work(i,j);
        }
    }


    return 0;   
}