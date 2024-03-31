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

template<class T>
auto input(T &v) {for (auto &c:v) cin >> c;}

template<class A, class B, class C>
auto forall(A &v, B n, C f){for (auto &c : v) n = f(n,c); return n;}


void work(){
    int n,x,y;
    cin >> n >> x >> y;

    vll v(x);
    input(v),sort(all(v));
    
    ll count = 0;
    ll prev = v[0];

    priority_queue<ll,vector<ll>,greater<ll>> pqo,pqe;
    
    for (int i=1;i<x;i++){
        if (v[i]-prev-1 == 1) count++;
        else if (v[i]-prev-1 > 1){
            if ((v[i]-prev-1) % 2) pqo.push(v[i] - prev - 1);
            else pqe.push(v[i] - prev - 1);
        }
        prev = v[i];
    }

    ll dif = abs(prev-(v[0]+n))-1;
    if (dif == 1) count++;
    else if (dif > 1){
        if (dif%2) pqo.push(dif);
        else pqe.push(dif);
    }


    while (pqo.size() && y){
        auto cur = pqo.top();
        pqo.pop();
        if (y >= cur/2){
            count += cur-cur/2;
            x += cur/2;
            y -= cur/2;
        }else{
            count += y;
            x += y;
            y = 0;
        }
    }

    while (pqe.size() && y){
        auto cur = pqe.top();
        pqe.pop();
        if (y >= cur/2){
            count += cur-cur/2;
            x += cur/2;
            y -= cur/2;
        }else{
            count += y;
            x += y;
            y = 0;
        }
    }
    cout << count + max(0,x-2) << '\n';

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}