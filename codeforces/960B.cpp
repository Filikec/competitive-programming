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
    ll n,k1,k2;
    cin >> n >> k1 >> k2;

    vll v1(n),v2(n);
    vpll v(n);

    input(v1),input(v2);
    
    rep(i,n){
        v[i] = {v1[i],v2[i]};
    }

    rep(i,k1){
        sort(all(v),[](auto a, auto b){return abs(a.first-a.second) > abs(b.first-b.second);});
        if (v.front().first > v.front().second) v.front().first--;
        else if (v.front().first < v.front().second) v.front().first++;
        else v.back().first++;
    }

    rep(i,k2){
        sort(all(v),[](auto a, auto b){return abs(a.first-a.second) > abs(b.first-b.second);});
        if (v.front().second > v.front().first) v.front().second--;
        else if (v.front().second < v.front().first) v.front().second++;
        else v.back().second++;
    }

    ll sum = 0;
    rep(i,n){
        sum += (v[i].first-v[i].second)*(v[i].first-v[i].second);
    }

    print(sum);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    work();

    return 0;
}