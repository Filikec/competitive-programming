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


string add(string m){
    int l=-1;
    for (int i=m.size()-1;i>=0&&m[i]=='1';i--){
        m[i]='0';
        l = i;
    }
    if (l!=-1){
        if (l) m[l-1] = '1';
        else m = "1"+m;
    }else if(m.size()){
        m.back() = '1';
    }
    
    return m;
}

ll from(string s){
    ll r = 0;
    ll pow = 1;
    for (int i=0;i<s.size();i++){
        r += (s[s.size()-1-i]=='1')*pow;
        pow *= 2;
    }
    return r;
}


void work(){
    int n;
    cin >> n;
    vll v(n);
    input(v);


    string got;
    string original;

    vll d(n-1);
    for (int i=1;i<n;i++) d[i-1] = v[i]-v[i-1];
    
    for (auto c : d){
        string need;
        if (!c){
            need = "01";
        }else if (c==1){
            need = "0";
        }else if (c < 0){
            for (int i=0;i<abs(c);i++) need += "1";
            need = "01"+need;
        }else{
            cout << "-1\n";
            return;
        }
        // print(original,got,need);
        for (int i=0;i<min(got.size(),need.size());i++){
            if (got[got.size()-1-i] != need[need.size()-1-i]){
                cout << "-1\n";
                return;
            }
        }

        if (need.size() > original.size()){
            for (int i=original.size();i<need.size();i++){
                original = need[need.size()-1-i]+original;
            }
        }
        
        if (need.size() >= got.size()) got = add(need);
        else got = add(got);
        
    }

    int count = 0;
    for (auto c : original) count += c=='1';
    
    if (count > v[0]){
        cout << "-1\n";
        return;
    }
    
    for (int i=0;i<v[0]-count;i++) original = "1"+original;

    cout << from(original) << '\n';
    
}
    
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();
    
    return 0;
}