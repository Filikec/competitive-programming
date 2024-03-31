#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ll> vld;

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
    ll n,k;
    cin >> n >> k;
    vll v(n);
    input(v);
    
    ll prev = 1;
    ll ans = 1;
    if (v.front()!=1) cout << "1\n";
    else{
        rep(i,k){
            for (int j=prev;ans>=v[j-1]-j+1&&j<=n;j++) prev = j;
            ans += prev;
        }
        cout << ans << '\n';
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}