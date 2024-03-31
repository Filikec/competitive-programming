#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ll> vld;
typedef vector<pll> vpll;

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


bool possible(ll mid, vpll &v, ll s){
    list<pll> rest;
    ll l,r,c;
    c = l = r = 0;

    rep(i,v.size()){
        if (v[i].first > mid) c+=v[i].first, r++;
        else if (v[i].second < mid) c+=v[i].first, l++;
        else rest.push_back(v[i]);
    }

    if (r > v.size()/2 || l > v.size()/2) return false;

    for (auto &p : rest){
        if (l < v.size()/2){
            l++;
            c += p.first;
        }else{
            c += mid;
        }
    }

    return c <= s;
}

void work(){
    ll n,s;
    cin >> n >> s;
    vpll v(n);
    for (auto &x : v) cin >> x.first >> x.second;
    sort(all(v));

    ll lo=v[v.size()/2].first,hi=s;
    while (lo<hi){
        ll mid = (lo+hi)/2+(lo+hi)%2;
        if (possible(mid,v,s)){
            lo = mid;
        }else{
            hi = mid-1;
        }

    }
    cout << lo << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}