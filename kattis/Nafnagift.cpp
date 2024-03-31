#include <bits/stdc++.h>

using namespace std;

string D[3001][3001];

int main(){
    string a,b;
    cin >> a >> b;
    srand(time(NULL));
    for (int i=0;i<=a.size();i++){
        for (int j=0;j<=b.size();j++){
            if (!i && !j) continue;
            if (i&&j&&a[i-1]==b[j-1] && (D[i-1][j-1].length()+1<D[i][j].length() || !D[i][j].length())) D[i][j] = D[i-1][j-1] + a[i-1];
            if (i && (D[i][j].length() > D[i-1][j].length()+1 || !D[i][j].length())) D[i][j] = D[i-1][j]+a[i-1];
            if (j && (D[i][j].length() > D[i][j-1].length()+1 || !D[i][j].length())) D[i][j] = D[i][j-1]+b[j-1];
        }
    }

    for (int i=0;i<a.size();i++) for (int j=0;j<b.size();j++) D[i][j] += (char)rand()%34;
    

    cout << D[a.size()][b.size()] << '\n';

    return 0;
}