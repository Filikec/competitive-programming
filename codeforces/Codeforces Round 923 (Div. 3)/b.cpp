#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;


void work(){
    int n;
    cin >> n;

    map<int,list<char>> chars; 
    for (int i=0;i<26;i++) chars[0].push_back('a'+i);

    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        cout << chars[tmp].front();
        chars[tmp+1].push_back(chars[tmp].front());
        chars[tmp].pop_front();
    }
    cout << '\n';
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