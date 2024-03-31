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
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll count=0;
    rep(i,n){
        
        if (i+2<n && s[i]=='p' && s[i+1]=='i' && s[i+2]=='e'){
            count++;
            i += 2;
        }else if (i+2<n && s[i]=='m' && s[i+1]=='a' && s[i+2]=='p'){
            if (i+4<n && s[i+3] == 'i' && s[i+4] == 'e'){
                count++;
                i += 4;
            }else{
                count++;
                i += 2;
            }
        }
    }
    print(count);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}