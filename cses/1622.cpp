#include <bits/stdc++.h>

using namespace std;


long long r(list<long long> u, long long total=0,long long sum=0){
    if (!u.size()) return abs(total-sum);
    long long cur = u.front();
    u.pop_front();
    return min(r(u,total+cur,sum),(r(u,total,sum+cur)));
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    list<long long> l;
    for (int i=0;i<n;i++){
        int c;
        cin >> c;
        l.push_back(c);
    }

    cout << r(l) << '\n';

    return 0;
}