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
    
    ll n,m,k;
    cin >> n >> m >> k;
    list<ll> a(n),b(m);

    input(a),input(b);
    a.sort(),b.sort();

    int count=0;
    for (auto c : a){
        while (b.size() && b.front()+k < c) b.pop_front();
        if (b.size()==0) break;
        if (abs(b.front()-c) <= k) count++,b.pop_front();
    } 

    cout << count << '\n';

    return 0;
}