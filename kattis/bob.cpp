#include <iostream>


using namespace std;


long long Counts[1001][1001],Board[1000][1000];

int main(){
    int n,m;
    cin>>n>>m;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> Board[i][j];
        }
    }

    long long sum = 0;
    for (int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--){
            bool added = false;
            auto cur = Board[i][j];
            Counts[i][j] = 1;
            if (cur==Board[i][j+1]) added = true,Counts[i][j] += Counts[i][j+1];
            if (cur==Board[i+1][j]) added = true,Counts[i][j] += Counts[i+1][j];
            if (cur==Board[i+1][j+1] && added) Counts[i][j] -= Counts[i+1][j+1];
            sum += Counts[i][j];
        }
    }

    cout << sum << '\n';

    return 0;
}

