#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    while (n--){
        long long c;
        cin >> c;
        cout << (1 << ((int)log2(c))) << "\n";
    }

    return 0;
}