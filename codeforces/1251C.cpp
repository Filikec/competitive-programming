#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ll> vld;

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
    string s;
    cin >> s;
    list<pll> odd,even;

    rep(i,s.size()){
        if ((s[i]-'0')%2) odd.push_back({i,s[i]-'0'});
        else even.push_back({i,s[i]-'0'});
    }

    odd.sort();
    even.sort();

    while (odd.size() && even.size()){
        if (odd.front().second < even.front().second) cout << odd.front().second, odd.pop_front();
        else cout << even.front().second, even.pop_front();
    }

    while (odd.size()) cout << odd.front().second, odd.pop_front();
    while (even.size()) cout << even.front().second, even.pop_front();
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