#include <bits/stdc++.h>

using namespace std;

int D[6000][6000];

int main(){
    string a,b;
    cin >> a >> b;

    for (int i=0;i<a.size();i++){
        for (int j=0;j<b.size();j++){
            D[i+1][j+1] = D[i][j]+1;
            if (a[i] == b[j]) D[i+1][j+1] = min(D[i+1][j+1],D[i][j]);
            D[i+1][j+1] = min(D[i+1][j+1],D[i][j+1]+1);
            D[i+1][j+1] = min(D[i+1][j+1],D[i+1][j]+1);
            cout << i+1 << ' ' << j+1 << ' ' << D[i+1][j+1] << '\n';
         }
    }

    cout << D[a.size()][b.size()] << '\n';

    return 0;
}