#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ll> vld;
typedef vector<pll> vpll;

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


bool possible(ll n, vpll v, vpll &o, ll got){
    auto cmp = [&](auto a, auto b){return a==b?false:o[a].second < o[b].second;};
    set<ll,decltype(cmp)> heap(cmp);


    

    cout << n << "<\n";
    int l = 0;
    while (l < v.size() && v[l].first <= n){
        n -= v[l].first;
        heap.insert(l);
        l++;
    }

    cout << l << "<\n";
    while (heap.size() && *heap.begin() <= l+got && l < v.size()){
        auto cur = *heap.begin();
        heap.erase(heap.begin());

        n += o[cur].first;
        while (l < v.size() && v[l].first <= n){
            n -= v[l].first;
            heap.insert(l);
            l++;
        }
    }

    return l == v.size();
}

void work(){
    int n;
    cin >> n;
    vpll v(n);
    for (auto &c : v) cin >> c.second >> c.first;
    ll got = 0;

    sort(all(v),[](auto a, auto b){return a.second > b.second;});
    while (v.size() && v.back().second <= got) got++,v.pop_back();
    sort(all(v));

    ll lo,hi;
    lo = 0, hi = 1e18;

    while (lo < hi){
        ll mid = (lo+hi)/2;

        if (possible(mid,v,v,got)){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }

    cout << lo << '\n';
}

int main(){
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}