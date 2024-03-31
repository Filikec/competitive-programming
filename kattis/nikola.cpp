#include <iostream>
#include <climits>

using namespace std;

int memoization[1000][1000];
int N;
int Array[1000];

int dfs(int n, int j){
    int pick1,pick2,pick;
    
    if (n >= N || n < 0 || j >= 1000 || j < 1){
        return INT_MAX;
    }


    if (memoization[n][j]){
        return memoization[n][j];
    }


    int cost = Array[n];

    
    pick1 = dfs(n+j,j+1);
    if (n != 0 || j != 1) pick2 = dfs(n-(j-1),j);

    pick = pick1;

    if (pick1 > pick2){
        pick = pick2;
    }

    if (pick != INT_MAX) pick += cost;
    
    memoization[n][j] = pick;

    return pick;
}

int main(){
    cin >> N;

    for (int i=0;i<N;i++){
        cin >> Array[i];
    }

    for (int i=0;i<1000;i++){
        memoization[N-1][i] = Array[N-1];  
    }

    dfs(0,1);

    cout << memoization[0][1]-Array[0] << "\n";

    return 0;
}