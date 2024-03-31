#include <bits/stdc++.h>

using namespace std;


int main(){

    int n;
    while (cin >> n){
        if (!n) return 0;
        bool neg = false;
        if (n < 0) neg=true;
        bool got = false;
        for (int i=2;i<=sqrt(abs(n));i++){
            for (int j=31;j>0;j--){
                int pow = 1;
                for (int k=0;k<j;k++){
                    pow *= i;
                    if (neg) pow *= -1;
                }
                if (pow == n){
                    cout << j << '\n';
                    got = true;
                    break;
                }
            }
            if (got) break;
        }

        if (!got) cout << 1 << '\n';


    }



    return 0;
}