#include <bits/stdc++.h>

using namespace std;


typedef unsigned long long ull;


int main(){
    ull n, k;

    cin >> n >> k;

    n--;
    
    cout << min(1+k+(n-(n/k)*k),n);


    return 0;
}