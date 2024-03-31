#include <iostream>
#include <vector>

using namespace std;


int D[201][201][3];

int main(){


    int n,k;

    while (cin >> n >> k){
        if (!n && !k) break;

        for (int i=0;i<=n;i++) 
            for (int j=0;j<=k;j++) 
                if (j>i){
                    D[i][j][0] = D[i][j][1] = D[i][j][2] = -199999;
                }else if (j==i){
                    D[i][j][0] = D[i][j][1] = 0;
                    D[i][j][2] = -199999;
                }else{
                    D[i][j][0] = D[i][j][1] = D[i][j][2] = 0;
                }
        

        for (int i=1;i<=n;i++){
            int a,b;
            cin >> a >> b;
            for (int j=0;j<=k&&j<=i;j++){
                if (!j){
                    D[i][j][2] = a+b+max(D[i-1][j][2],0);
                }else{
                    D[i][j][0] = max(D[i-1][j-1][0]+a, max(D[i-1][j-1][2] + a,D[i][j][0]));
                    D[i][j][1] = max(D[i-1][j-1][1]+b, max(D[i-1][j-1][2] + b,D[i][j][1]));
                    D[i][j][2] = max(D[i][j][2],max(D[i-1][j][0]+a+b, max(D[i-1][j][1]+a+b,D[i-1][j][2]+a+b)));
                }
            }
        }   

        cout << max(D[n][k][0],max(D[n][k][1],D[n][k][2])) << '\n';
    }


    return 0;
}