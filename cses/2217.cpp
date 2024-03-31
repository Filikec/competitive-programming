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

int get(int i, vll &v, vll &m){
    int sum = 0;
    if (v[i]>1&&m[v[i]-1]>i) sum++;
    if (v[i]<v.size()&&m[v[i]+1]<i)sum++;
    return sum; 
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n,q;
    cin >> n >> q;
    vll v(n),m(n+1);
    input(v);
    rep(i,n) m[v[i]]=i;
    int count=1;
    rep(i,n){
        if (v[i]>1&&m[v[i]-1] > i) count++;
    }
    
    rep(i,q){
        int a,b;
        cin >> a >> b;
        a--,b--;
        if (a > b) swap(a,b);
        if (a==b){
            cout << count << '\n';
            continue;
        }
        int curA = get(a,v,m);
        int curB = get(b,v,m);
        m[v[a]] = b;
        m[v[b]] = a;
        swap(v[a],v[b]);
        int ca = get(a,v,m);
        int cb = get(b,v,m);
        count += ca-curA+cb-curB;
        if (abs(v[a]-v[b]) == 1){
            if (v[a] < v[b]){
                count += 1;
            }else{
                count -= 1;
            }
        }
        cout << count << "\n";
    }

    
    return 0;
}