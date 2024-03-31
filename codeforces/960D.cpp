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

ll depth(ll x){
    return log2(x);
}

void path(vll &vs, vll &ns, ll x){
    ll d = depth(x);

    ll shift = 0;
    rep(i,d+1){
        shift *= 2;
        shift += ns[i];
    }

    
    ll len = 1 << d;
    ll target = len+(-shift - vs[d] + x-len+2*len)%len;
    ll cur = target;
    while (target!=1){
        cout << cur << ' ';
        d--;
        len = 1 << d;
        target /= 2;
        cur = len+(target-len-vs[d]+2*len)%len;
    }
    cout << "1\n";
}



void work(){
    ll q;
    vll vs(100),ns(100);

    cin >> q;

    rep(i,q){
        ll t,x,k;
        cin >> t >> x;
        if (t == 3) path(vs,ns,x);
        else{
            cin >> k;
            ll d = depth(x);
            ll m = (1 << d);
            if (t == 1){
                vs[d] = (vs[d]+k%m+m)%m;
            }else{
                ns[d] = (ns[d]+k%m+m)%m;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    work();

    return 0;
}