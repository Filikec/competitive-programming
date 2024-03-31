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


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vpll v(n);
    for (auto &p : v) cin >> p.first >> p.second;
    sort(all(v));

    // auto cmp = [&](auto a, auto b){return v[a].second>v[b].second;};
    // priority_queue<ll,vll,decltype(cmp)> q(cmp);
    ll prev = 0;
    ll got = 0;
    rep(i,n){
        if (prev <= v[i].first) got++,prev = v[i].second;
        else if (prev > v[i].second) prev = v[i].second;
    }  

    cout << got << '\n';

    return 0;
}