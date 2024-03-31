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
    

bool possible2(vll &v1, vll &v2, ll target, ll k, ll mid){
    list<ll> s;
    for (int i=0;i<v2.size()&&v1[i]<=target-2*mid;i++){
        s.push_back(min(v2[i],target-2*mid)-v1[i]+1);
    }

    ll got = 0;
    ll sum = 0;
    while (sum < k && s.size() && got < mid){
        sum += s.back();
        s.pop_back();
        got++;
    }
    
    return sum>=k;
}

bool possible(vll &v1, vll &v2, ll target, ll k){
    ll lo=0,hi=k;
    
    while (hi-lo>3){
        ll lt = lo + (hi - lo) / 3;
        ll rt = hi - (hi - lo) / 3;

        if (possible2(v1,v2,target,k,lt) < possible2(v1,v2,target,k,rt)){
            lo = lt;
        }else hi = rt;
    }

    int newHi = -1;
    for (;lo<=hi;lo++){
        if (possible2(v1,v2,target,k,lo)){
            newHi = lo;
            break;
        }
    }
    if (newHi==-1) return false;

    lo = 0,hi = newHi;

    while (lo < hi){
        ll mid=(lo+hi)/2;
        if (possible2(v1,v2,target,k,mid)){
            hi = mid;
        }else lo = mid+1;
    }
}
    
void work(){
    ll n,k;
    cin >> n >> k;
    
    vll v1(n),v2(n);
    input(v1);
    input(v2);
    
    
    ll lo=0,hi=1e14;
    
    while (lo<hi){
        ll mid = (lo+hi)/2;
        if (possible(v1,v2,mid,k)){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    
    if (possible(v1,v2,lo,k)){
        cout << lo << '\n';
    }else cout << -1 << '\n';
    
    
}
    
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();
    
    return 0;
}