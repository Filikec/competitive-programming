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



void work(){
    ll n,m;
    cin >> n >> m;
    vector<map<ll,list<ll>>> g(n);
    vll d(n);
    vector<set<ll>> vs(n);
    fill(all(d),1e10);

    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        g[a][c].push_back(b);
        g[b][c].push_back(a);
    }

    int s,t;
    cin >> s >> t;
    s--,t--;

    auto cmp = [&](ll a, ll b){return d[a]<d[b]?true:d[a]==d[b]&&a<b;};
    set<ll,decltype(cmp)> q(cmp);
    q.insert(s);
    d[s] = 0;
    while (q.size()){
        auto cur = *q.begin();
        q.erase(q.begin());

        if (cur == t){
            cout << d[cur] << '\n';
            return;
        }

        for (auto &p : g[cur]){
            if (vs[cur].count(p.first)) continue;

            n = p.second.front();
            ll dist = d[cur]+1;
            ll colour = p.first;

            if (any_of(p.second.begin(),p.second.end(),[&](auto &n){return d[n]>=dist;})){
                list<ll> bfsq = {cur};
                unordered_set<ll> v = {cur};
                
                while (bfsq.size()){
                    auto cur = bfsq.front();
                    bfsq.pop_front();
                    vs[cur].insert(colour);
                    for (auto n : g[cur][colour]){
                        if (d[n] > dist){
                            q.erase(n);
                            d[n] = dist;
                            q.insert(n);
                        }
                        if (!v.count(n) && !vs[n].count(colour)) bfsq.push_back(n), v.insert(n);
                    }
                }
            }
        }
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