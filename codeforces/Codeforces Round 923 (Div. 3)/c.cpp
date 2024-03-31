#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;


void work(){
    int a,b,k;
    cin >> a >> b >> k;

    unordered_set<int> ma,mb;
    for (int i=0;i<a;i++){
        int tmp;
        cin >> tmp;
        ma.insert(tmp);
    }

    for (int i=0;i<b;i++){
        int tmp;
        cin >> tmp;
        mb.insert(tmp);
    }

    int cb,ca,both;
    ca = cb = both = 0;
    for (int i=1;i<=k;i++){
        if (!ma.count(i) && !mb.count(i)){
            cout << "NO\n";
            return;
        }else if (!ma.count(i)) cb++;
        else if (!mb.count(i)) ca++;
        else{
            both++;
        }
    }

    if (abs(ca-cb) <= both) cout << "YES\n";
    else cout << "NO\n";
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