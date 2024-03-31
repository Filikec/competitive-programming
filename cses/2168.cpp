#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
 
 
typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ord_set;
 
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
 

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<pair<pll,int>> v(n);
    
    vll a(n),b(n);
    rep(i,n){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second=i;
    }
    auto cmp = [](auto a, auto b){return a.first.first==b.first.first?a.first.second>b.first.second:a.first.first<b.first.first;};
    sort(all(v),cmp);
    
    multiset<long long, less<long long>> t,t2;
    for (auto &c : v) t.insert(c.first.second); 
    t2 = t;

    for (auto &c : v){
        t.erase(t.find(c.first.second));
        if (t.size()) a[c.second] = *t.begin() <= c.first.second;
    }
     
    for (auto it = v.rbegin();it!=v.rend();it++){
        t2.erase(t2.find(it->first.second));
        if (t2.size()) b[it->second] = *t2.rbegin()>=it->first.second;
    }
 
 
    rep(i,n)cout << a[i] << ' ';
    cout << '\n';
    rep(i,n)cout << b[i] << ' ';
    cout << '\n';
    return 0;
}