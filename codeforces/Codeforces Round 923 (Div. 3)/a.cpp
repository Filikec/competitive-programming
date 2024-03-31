#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;


void work(){
    int n;
    cin >> n;
    list<int> is;
    for (int i=0;i<n;i++){
        char c;
        cin >> c;
        if (c == 'B') is.push_back(i);
    }
    if (!is.size()) cout << "0\n";
    else if (is.size()==1) cout << "1\n";
    else cout << is.back() - is.front() + 1 << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--){
        work();
    }

    return 0;
}