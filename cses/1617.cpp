#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> v(n);
    v[0] = 2;

    for (int i=1;i<n;i++){
        v[i] = (v[i-1]*2) % (long long)(1e9+7);
    }
    cout << v.back() << '\n';

    return 0;
}