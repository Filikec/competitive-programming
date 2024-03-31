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
    int n,k;
    cin >> n >> k;
    vll v(n*2);
    input(v);

    list<int> l,r;
    set<int> pr,pl;

    for (int i=1;i<=n;i++) pr.insert(i);

    rep(i,n)
        if (pr.count(v[i])) pr.erase(v[i]);
        else pl.insert(v[i]);
    
    auto it1 = pl.begin();
    auto it2 = pr.begin();
    while (l.size()<2*k && it1!=pl.end()){
        l.push_back(*it1),l.push_back(*it1);
        r.push_back(*it2),r.push_back(*it2);
        it1++,it2++;
    }

    for (int i=1;i<=n&&l.size()<2*k;i++){
        if (!pr.count(i) && !pl.count(i) && 2*k-l.size()) l.push_back(i), r.push_back(i);
    }

    for (auto c : l) cout << c << ' ';
    cout << '\n';
    for (auto c : r) cout << c << ' ';
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