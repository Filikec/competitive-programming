#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpll;
typedef vector<pld> vpld;

#define rep(i,a) for(int i = 0; i < a; i++)
#define all(it) it.begin(),it.end()

template<class... T>
constexpr auto min(T... a){
    return min(initializer_list<common_type_t<T...>>{a...});
}
template<class... T>
constexpr auto max(T... a){
    return max(initializer_list<common_type_t<T...>>{a...});
}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}

template<class T>
auto input(T &v) {for (auto &c:v) cin >> c;}

template<class A, class B, class C>
auto forall(A &v, B n, C f){for (auto &c : v) n = f(n,c); return n;}


void work(){
    int n;
    cin >> n;
    vll v1(n),v2(n);
    input(v1);
    input(v2);

    int l=-1;
    int r=n-1;
    list<ll> ls;
    rep(i,n){
        if (l==-1&&v1[i]!=v2[i]) l = i;
        if (l!=-1&&v1[i]==v2[i]) r = min(i-1,r);
        if (i >= l && i<=r) ls.push_back(v2[i]);
    }
    ls.sort();

    cout << l << ' ' << r << '\n';

    for (l=l-1;l>=0;l--){
        if (ls.front() >= v2[l]) continue;
        else break;
    }

    for (r=r+1;r<n;r++){
        if (ls.back() <= v2[r]) continue;
        else break;
    }
    
    cout << l+2 << ' ' << r << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}