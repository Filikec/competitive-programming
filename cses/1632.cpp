#include <bits/stdc++.h>


using namespace std;

int main(){

    int n,k;
    cin >> n >> k;


    vector<pair<int,int>> v(n);
    for (auto &c : v) cin >> c.first >> c.second;
    sort(v.begin(),v.end());

    multiset<int> s;
    
    long long count=0;
    for (auto &p : v){
        while (s.size()&&*s.begin() <= p.first) s.erase(s.begin());
        if (s.size()<k) s.insert(p.second), count++;
        else if (*s.rbegin() > p.second) s.erase(--s.rbegin().base()), s.insert(p.second);
    }

    cout << count << '\n';

    return 0;
}