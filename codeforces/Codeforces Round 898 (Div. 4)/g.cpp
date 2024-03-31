#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


void work(){
    string s;
    cin >> s;
    ll bcount=0;
    int l=0,r=s.size()-1;

    while (l<r && s[l]=='B') l++;
    while (r>l && s[r]=='B') r++;

    for (int i=l;i<=r;i++) bcount += s[i]=='B';
    bcount += (s.front()=='B')+(s.back()=='B');

    multiset<ll> segments;
    ll cur=0;
    ll acount=0;
    for (auto c : s){
        if (c=='A') cur++,acount++;
        else{
            if (cur) segments.insert(cur);
            cur=0;
        }
    }
    if (cur) segments.insert(cur);

    if (bcount >= segments.size()) cout << acount << '\n';
    else cout << acount-*segments.begin() << '\n';

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}