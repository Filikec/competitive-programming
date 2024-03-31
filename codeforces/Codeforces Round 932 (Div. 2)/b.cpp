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
    vll v(n);
    input(v);
    set<ll> u;
    for (auto &c  : v) u.insert(c);


    ll small = 0;
    for (int i=0;i<=n;i++){
        if (!u.contains(i)){
            small = i;
            break;
        }
    }

    u.clear();
    for (int i=0;i<small;i++) u.insert(i);

    pll first = {0,-1};
    for (int i=0;i<n;i++){
        u.erase(v[i]);
        if (!u.size()){
            first.second=i;
            break;
        }
    }

    u.clear();
    for (int i=0;i<small;i++) u.insert(i);
    for (int i=first.second+1;i<n;i++){
        u.erase(v[i]);
        if (!u.size()){
            cout << 2 << '\n';
            cout << first.first+1 << ' ' << first.second+1 << '\n';
            cout << first.second+2 << ' ' << n << '\n';
            return;
        }
    }
    cout << "-1\n";
}       

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}