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
    ll n;
    cin >> n;
    vll v(n),p(n);
    input(v),input(p);

    auto cmp1 = [&](auto a,auto b){return v[a-1]>v[b-1]?true:v[a-1]==v[b-1]&&a>b;};
    auto cmp2 = [&](auto a,auto b){return v[a-1]<v[b-1]?true:v[a-1]==v[b-1]&&a<b;};
    set<ll,decltype(cmp1)> pq(cmp1);
    for (int i=1;i<=n;i++) pq.insert(i);

    pll best = {0,1e9};
    set<int,decltype(cmp2)> u(cmp2);
    set<int> im;

    rep(i,n){
        while (pq.size() && im.count(*pq.begin())) pq.erase(pq.begin());
        if (!pq.size()) break;

        int cur = *pq.begin();
        pq.erase(pq.begin());
        u.insert(cur);
        if (best.first < v[*u.begin()-1] * u.size()) best = {v[*u.begin()-1] * u.size(),u.size()};

        im.insert(p[i]);        
        if (u.count(p[i])){
            u.erase(p[i]);
            while (pq.size() && im.count(*pq.begin())) pq.erase(pq.begin());
            if (!pq.size()) break;
            u.insert(*pq.begin());
            pq.erase(pq.begin());
        }
    }

    cout << best.first << ' ' << best.second << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}