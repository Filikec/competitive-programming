#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


void work(){
    ll n;
    cin >> n;

    string s;
    cin >> s;
    bool got = false;
    int count = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '*'){
            if (got) break;
            else got = 1;
        }else{
            got = 0;
            if (s[i] == '@') count++;
        }
    }
    cout << count << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}