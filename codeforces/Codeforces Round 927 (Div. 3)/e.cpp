#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;




void work(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll excess = 0;
    ll sum = 0;

    for (auto c : s) sum += c-'0';

    list<char> num;
    for (int i=0;i<n;i++){
        ll cur = sum + excess;
        num.push_front(cur%10);
        excess = cur/10;
        sum -= s[n-1-i]-'0';
    }
    if (excess) num.push_front(excess);

    while (num.size() && !num.front()) num.pop_front();
    for (auto d : num) cout << (char) (d+'0');
    cout << '\n';

}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}