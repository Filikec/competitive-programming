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
auto forall(A &v, B n, C f){ for (auto &c : v) n = f(n,c); return n; }


bool possible(ll mid, vll &v, set<ll> &d, vector<ll> &f){
    bool p = 0;
    for (auto i=1;i<v.size();i++){
        if (v[i]-v[i-1] > mid){
            if (p) return false;
            else{
                p = 1;
                bool ex = 0;
                for (auto n : d){
                    ll maxv = mid+v[i-1]-n;
                    ll minv = v[i]-mid-n;
                    int s = distance(f.begin(),upper_bound(f.begin(),f.end(),maxv));
                    int t = distance(f.begin(),lower_bound(f.begin(),f.end(),minv));
                    if (s-t > 0){
                        ex = 1;
                        break;
                    }
                }
                if (!ex) return false;
            }
        }
    }
    return true;
}

void work(){
    ll n,m,k;
    cin >> n >> m >> k;

    vll v(n),f(k);
    set<ll> d;
    input(v);
    rep(i,m){
        ll c;
        cin >> c;
        d.insert(c);
    }
    input(f);
    sort(all(f));
    
    ll lo,hi;
    lo = 0, hi = 1e10;

    while (lo<hi){
        ll mid = (lo+hi)/2;
        if (possible(mid,v,d,f)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}