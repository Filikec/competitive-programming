#include <iostream>
#include <iomanip>

using namespace std;

long double dynamic[3000][3000];

int main(){

    int n,m;

    cin >> n >> m;

    for (int i=0;i<3000;i++) dynamic[i][0] = 1;

    for (int i=1;i<3000;i++){
        long double p;
        cin >> p;
        p = 1-p;
        for (int j=1;j<=m+n;j++){
            dynamic[i][j] = dynamic[i-1][j]+(dynamic[i-1][j-1]-dynamic[i-1][j])*p;
        }

    }

    cout << fixed << setprecision(8) << 1-dynamic[n+m-1][n] << '\n';

    return 0;
}