#include <iostream>
#include <cmath>

using namespace std;


int M[50][50];

int sign(int n){
    if (n > 0) return 1;
    else if (!n) return 0;
    else return -1;
}

int main(){


    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> M[i][j];
        }
    }

    bool good = 1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (abs(M[i][j]-M[j][i]) % 2){
                cout << "-1\n";
                return 0;
            }
            if (abs(M[i][j]) != abs(M[j][i])){
                good = 0;
            }
        }
    }

    if (good){
        cout << "1\n";
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout << M[i][j] << ' ';
            }
            cout << '\n';
        }
        return 0;
    }

    cout << "2\n";

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (abs(M[i][j]) == abs(M[j][i])) cout << M[i][j] << ' ';
            else if (M[i][j] > M[j][i]) cout << abs(M[i][j] - M[j][i])/2 << ' '; 
            else cout << -abs(M[i][j] - M[j][i])/2 << ' '; 
        }
        cout << '\n';
    }
    
     for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (abs(M[i][j]) == abs(M[j][i])) cout << 0 << ' ';
            else if (M[i][j] > M[j][i]) cout << M[i][j]-abs(M[i][j] - M[j][i])/2 << ' '; 
            else cout << M[i][j]+abs(M[i][j] - M[j][i])/2 << ' '; 
        }
        cout << '\n';
    }

    return 0;
}

