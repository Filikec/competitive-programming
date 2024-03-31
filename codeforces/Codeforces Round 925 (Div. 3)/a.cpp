#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;


void write(int p, int n){
    if (!p) return;

    for (int i=1;i<=26;i++){
        if ((p-1)*26 >= n-i){
            cout << (char)('a'+i-1);
            write(p-1,n-i);
            break;
        }
    }
}

void work(){
    int n;
    cin >> n;

    write(3,n);
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