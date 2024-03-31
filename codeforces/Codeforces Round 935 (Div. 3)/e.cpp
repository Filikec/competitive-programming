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
    int n,x;
    cin >> n >> x;
    vll v(n);
    input(v);

    int pos=0;
    rep(i,n) if (v[i]==x) pos = i+1;
    

    list<int> nums;
    int l,r;
    l=1,r=n+1;
    while (r-l!=1){
        int m=(r+l)/2;
        if (v[m-1]<=x) l=m;
        else r=m;
        nums.push_back(v[m-1]);
    }
    if (v[l-1] == x){
        print(0);
    }else{
        if (!any_of(all(nums),[&](auto n){return n==x;})){
            print(1);
            print(pos,l);
        }else{
            bool f = 0;
            pll sw;
            for (int i=1;i<=n;i++){
                if (v[i-1] < x && !any_of(all(nums),[&](auto n){return n==v[i-1];})){
                    sw = {i,pos};
                    pos=i;
                    f=1;
                    break;
                }
            }
            if (f){
                print(2);
                print(sw.first,sw.second);
            }else{
                print(1);
            }
            print(pos,l);
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