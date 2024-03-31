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
    ll n;
    cin >> n;
    vector<pll> v(n);
    
    rep(i,n){
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    


    ll got=0;
    ll prev = v[0].first;
    ll prevv = n-1*(v.back().first==0);
    ll left = 0;
    rep(i,n){
        if (got < v[i].first){
            got++;
            if (prev != v[i].first) prevv -= 2;
            v[i].first = prevv;
            left = i;
        }else{
            break;
        }
    }

    bool f = true;

    for (int i=left+1;i<n;i++){
        if (v[i].first){
            int pi = v[i].first-1;
            v[i].first = (v[pi].first-1)*-1;
            if (pi+1 < n && v[pi].first == v[pi+1].first) f = false;
        }
        else v[i].first = -n;
    }

    
    for (auto x : v){
        if (x.first < -n || x.first > n || !x.first) f = false;
    }

    if (f){
        cout << "YES\n"; 
        sort(v.begin(),v.end(),[](auto a, auto b){return a.second < b.second;});
        for (auto c : v) cout << c.first << ' ';
        cout << '\n';
    }else{
        cout << "NO\n";
    }
    
    
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}