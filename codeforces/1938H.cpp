#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long c[2];
    long long k = 0;    
    vector<pair<long long,long long>> zs,os;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        c[0] = c[1] = 0;
        for (auto k : s) c[k-'0']++;
        k += min(c[0],c[1]);
        zs.push_back({c[0],i});
        os.push_back({c[1],i});
    }
    long long best = 1e10;
    if (zs.front().second == os.front().second){
        cout << k - min(zs.front().firstq)
    }
    return 0;
}