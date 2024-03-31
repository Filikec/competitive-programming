#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i=0;i<n-1;i++){
        int c;
        cin >> c;
        v[c]++;
    }
    
    for (int i=0;i<n;i++){
        if (!v[i+1]) cout << i+1 << '\n';
    }

    return 0;
}