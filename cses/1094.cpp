#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,p=0;
    cin >> n;

    long long sum = 0;
    for (int i=0;i<n;i++){
        int c;
        cin >> c;
        sum += max(0,p-c);
        p = max(p,c);
    }
    cout << sum << '\n';

    return 0;
}