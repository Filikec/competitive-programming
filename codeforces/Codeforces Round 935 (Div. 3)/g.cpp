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

void work(){
    int n,d;
    cin >> n >> d;
    vll k(n),p(n);
    list<int> sl;
    auto cmp1 = [&](auto a, auto b){return p[a.first]==p[b.first]?a.second>b.second:p[a.first]<p[b.first];};
    auto cmp2 = [&](auto a, auto b){return a.second==b.second?k[a.first]>k[b.first]:a.second>b.second;};
    auto cmp3 = [&](auto a, auto b){return p[a]==p[b]?a<b:p[a]>p[b];};
    priority_queue<pll,vector<pll>,decltype(cmp1)> q(cmp1);
    priority_queue<pll,vector<pll>,decltype(cmp2)> ev(cmp2);
    set<ll,decltype(cmp3)> sq(cmp3);


    rep(i,n) cin >> p[i] >> k[i], sl.push_back(i), sq.insert(i);

    ll id=0;
    rep(i,d){   
        while (ev.size() && ev.top().second == i+1) q.push({ev.top().first,id++}),ev.pop();
        int cur;
        if (q.size() && p[*sq.begin()] < p[q.top().first]){
            cur = q.top().first;
            q.pop();
        }else{
            cur = sl.front();
            sl.pop_front();
            if (!sl.size()){
                print(i+1);
                return;
            }
            sq.erase(cur);
        }
        ev.push({cur,i+2+k[cur]});
    }

    print(-1);
}   

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}