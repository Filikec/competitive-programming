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
    ll x,d;
    cin >> x >> d;

    ll prev = 1;
    list<ll> nums;

    while (x){
        if (prev > 1000000000000000000){
            print(-1);
            return;
        }
        ll l = log2(x);
        if (!l){
            nums.push_back(prev);
            break;
        }
        rep (i,l){
            nums.push_back(prev);
        }
        prev += d;
        x -= (1 << l) - 1;
    }
    cout << nums.size() << '\n';
    for (auto n : nums) cout << n << ' ';
    cout <<  '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    work();

    return 0;
}