#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL combination(ULL amount, ULL take){
    ULL result = 1;

    for (;take;take--){
        result *= amount--;
        result /= take;
    }

    return result;
}

ULL Fruits[40];

int main(){

    ULL n;

    cin >> n;

    for (ULL i=0;i<n;i++){
        cin >> Fruits[i];
    }

    ULL count=0;  
    for (ULL i=0;i<n;i++){
        ULL weight = Fruits[i];
        if (weight >= 200) count += weight;
        for (ULL j=i+1;j<n;j++){
            ULL weight1 = weight + Fruits[j];
            if (weight1 >= 200) count += weight1;
            for (ULL k=j+1;k<n;k++){
                ULL weight2 = weight1 + Fruits[k];
                if (weight2 >= 200) count += weight2;
            }
        }
        for (ULL j=3;j+1<=n;j++){
            count += combination(n-1,j)*Fruits[i];
        }
    }

    cout << count << '\n';


    return 0;
}