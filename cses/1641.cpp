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
    
    ll n,x;
    cin >> n >> x;

    vpll v(n);
    rep(i,n){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(all(v));
    for(int i = 0; i < n; i++){
        int c = x - v[i].first;
        int r = n-1;
        for(int l = i+1; l < r; l++){
            while(l+1 < r && v[l].first + v[r].first > c)  r--;
            if(v[l].first + v[r].first == c){
                print(v[i].second, v[l].second, v[r].second);
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}