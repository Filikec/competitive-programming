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
 
 
bool possible(vll &v, ll t, ll m){
    ll sum=0;
    for (auto &c : v){
        sum += t/c;
        if (sum >= m) return true;
    }
    return false;
}
 
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    auto cmp = [](auto a, auto b){return a.first>b.first;};
    priority_queue<pll,vpll,decltype(cmp)> pq(cmp);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        pq.push({a,b});
    }
    ll t=0;
    ll sum=0;
    while (pq.size()){
        auto cur = pq.top();
        pq.pop();
        t += cur.first;
        sum += cur.second-t;
    }
    cout << sum << '\n';
    return 0;
}