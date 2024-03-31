#include <iostream>

using namespace std;



char Students[700][700],Classes[26];

int main(){

    int n,m,k;


    cin >> n >> m >> k;


    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> Students[i][j];
        }
    }






    return 0;
}