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


pll DP[3000][3000];

pll comp(pll a, pll b){
    if (a.first + (b.second - a.second) < b.first) return a;
    else return b;
}

void work(){
    ll n,t;
    cin >> n >> t;

    vpll v(n);
    for (auto &c : v) cin >> c.first >> c.second;
    sort(all(v),[](auto a, auto b){return a.second < b.second;});

    rep(i,n){
        rep(j,n+1){
            DP[i][j].first = t+1;
            DP[i][j].second = -1e13;
        }
    }

    DP[0][0] = {0,0};
    DP[0][1] = {v[0]};

    ll best = v[0].first<=t?1:0;
    for (int i=1;i<n;i++){
        for (int j=1;j<=i+1;j++){
            if (j==1) DP[i][j] = comp(DP[i-1][j],v[i]);
            else DP[i][j] = comp(DP[i-1][j],{DP[i-1][j-1].first+v[i].first+abs(v[i].second-DP[i-1][j-1].second),v[i].second});
            if (DP[i][j].first <= t) best = max(best,j);
        }
    }
    cout << best << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}