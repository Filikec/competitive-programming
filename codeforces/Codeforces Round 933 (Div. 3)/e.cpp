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
struct SegmentTree{
    vector<T> tree; // potentially change type
    int n;

    SegmentTree(int n) : n(n) { 
        int size = 1 << (int) (log2(n)+1);
        tree.resize(2*size-1);  
    }
    private:
        void insert(T v, int ind, int l, int r, int i=0){
            if (l == r && ind == l){
                tree[i] = v;
                return;
            }
            if (l > ind) return;
            if (r < ind) return;

            int mid = (l+r)/2;
            insert(v,ind,l,mid,i*2+1);
            insert(v,ind,mid+1,r,i*2+2);

            tree[i] = min(tree[i*2+1],tree[i*2+2]);
        }

        long long contained(int l, int r, int cl, int cr, int i){
            if (l <= cl && r >= cr){
                return tree[i];
            }
            if (cl > r || cr < l) return 1e18;
            int mid = (cl+cr)/2;
            // merge results
            return min(contained(l,r,cl,mid,i*2+1),contained(l,r,mid+1,cr,i*2+2));
        }

    public:
        void insert(T v, int ind) { insert(v,ind,0,n); }

        long long contained(int l, int r) { return contained(l,r,0,n,0); }
};


ll solve(vll &v, vll &dp, ll d){
    for (auto &c : dp) c = 1e18;
    
    dp[0] = 1;
    SegmentTree<ll> st(v.size());
    st.insert(1,0);

    ll b = 1e18;
    for (int i=1;i<v.size();i++){
        dp[i] = st.contained(max(0,i-d-1),i-1)+v[i]+1;
        st.insert(dp[i],i);
        if (v.size()-i-2 <= d) b = min(b,dp[i]);
    }
    return dp[v.size()-1];

}

void work(){
    ll n,m,k,d;
    cin >> n >> m >> k >> d;
    vector<vll> g(n);
    vector<vll> dp(n);
    vll s(n); 
    rep(i,n){
        dp[i].resize(m);
        rep(j,m){
            int c;
            cin >> c;
            g[i].push_back(c);
        }
    }

    rep(i,n){
        s[i] = solve(g[i],dp[i],d);
    }

    ll best = 1e18;
    for (int i=0;i+k<=n;i++){
        ll sum = 0;
        for (int j=0;j<k;j++){
            sum += s[i+j];
        }
        best = min(best,sum);
    }

    cout << best << '\n';

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) work();

    return 0;
}