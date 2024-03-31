#include <iostream>

using namespace std;

#define MOD 1000000007

int D[1002];


void work(){
    int m,n;
    cin >> m >> n;
    for (int i=2;i<=n+1;i++){
        D[i] = 0;
        for (int j=max(i-1-m,0);j<i;j++){
            int add = D[j]*D[i-1];
            if (j!=i-1) add *= 2;
            D[i] = (D[i]+add)%MOD;
        }
    }
    cout << D[n+1] << '\n';
}


int main(){
    int n;
    cin >> n;

    D[0] = 1;
    D[1] = 1;

    for (int i=0;i<n;i++) work();

    return 0;
}



