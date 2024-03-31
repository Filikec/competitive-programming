#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    map<long long,long long> m;
    vector<long long> v(n);
    long long ans=0,prev=0;
    for (int i=0;i<n;i++){
        cin >> v[i];
        m[v[i]]++;
        while (m.size() > x) if (--m[v[prev++]]==0) m.erase(v[prev-1]);   
        ans += i-prev+1;
    }
    cout << ans << '\n';

    return 0;
}