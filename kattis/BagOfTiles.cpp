#include <iostream>
#include <list>
#include <cmath>

using namespace std;


int comb(double n, double t){
    double up = 1;

    t = min(t,n-t);

    while (t){
        up *= n--;
        up /= t--;
    }

    return (int) round(up);

}

int D[2][31][10000];

void work(int game){
    int m;

    cin >> m;


    int tiles[30];

    for (int i=0;i<m;i++){
        cin >> tiles[i];
    }

    int n,t;
    cin >> n >> t;
    

    if (!t && !n){
        cout << "Game " << game << " -- " << 1 << " : " << 0 << '\n';
        return;
    }

    for (int i=0;i<=n;i++){
        for (int k=0;k<=t;k++){
            D[0][i][k] = 0;
        }
    }

    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            for (int k=0;k<=t;k++){
                D[i%2][j][k] = D[(i+1)%2][j][k];
                if (j == 1 && k == tiles[i-1]) D[i%2][j][k]++;
                if (k-tiles[i-1] >= 0) D[i%2][j][k] += D[(i+1)%2][j-1][k-tiles[i-1]];
            }
        }
    }
    

    cout << "Game " << game << " -- " << D[m%2][n][t] << " : " << comb(m,n)-D[m%2][n][t] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        work(i+1);
    }


    return 0;
}