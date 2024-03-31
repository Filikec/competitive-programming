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
    ll sum=0;
    vll v(n);
    input(v),sort(all(v));

    if (v.size()==1){
        print(v.front()*2);
        return 0;
    }

    ll dif = v.back()-v[v.size()-2];
    for (int i=0;i<v.size()-2;i++) sum += v[i];
    if (sum >= dif){
        print(sum + v.back()+v[v.size()-2]);
    }else{
        print(v.back()*2);
    }

    return 0;
}