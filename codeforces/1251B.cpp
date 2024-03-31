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


int getpla(string &s){
    int count = 0;
    rep(i,s.size()/2){
        if (s[i] != s[s.size()-1-i]) count++;
    }
    return count;
}

void work(){
    int n;
    cin >> n;

    list<int> ns;
    rep(i,n){
        string s;
        cin >> s;
        ns.push_back(getpla(s));
    }
    int count = forall(ns,0,[](auto a, auto b){return a+b;});
    ns.sort();

    while (ns.size()){
        if (count>=2*ns.front()) count -= ns.front(), ns.pop_front();
        else break;
    }
    cout << n-ns.size() << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}