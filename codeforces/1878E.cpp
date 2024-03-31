#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

template <class T>
struct SegmentTree{
    vector<T> tree; // potentially change type
    int n;

    SegmentTree(int n) : n(n) { 
        int size = 1 << (int) (log2(n)+1);
        tree.resize(2*size-1);  
    }
    private:
        void build(vector<T> &a, int l, int r, int i=0){
            if (l == r){
                tree[i] = a[l];
                return;
            }

            int mid = (l+r)/2;
            build(a,l,mid,i*2+1);
            build(a,mid+1,r,i*2+2);

            tree[i]=tree[i*2+1]&tree[i*2+2];
        }

        long long contained(int l, int r, int cl, int cr, int i){
            if (l <= cl && r >= cr){
                return tree[i];
            }
            if (cl > r || cr < l) return 0xFFFFFFFF;
            int mid = (cl+cr)/2;

            ll a = contained(l,r,cl,mid,i*2+1);
            ll b = contained(l,r,mid+1,cr,i*2+2);
            return a&b;
        }

    public:
        void build(vector<T> &a) { build(a,0,n); }

        long long contained(int l, int r) { return contained(l,r,0,n,0); }
};


void work(){
    int n;
    cin >> n;

    vector<ll> v(n);
    for (auto &c : v) cin >> c;
    SegmentTree<ll> t(n);
    t.build(v);

    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        ll l,k;
        cin >> l >> k;

        int lo=l-1,hi=n-1;
        while (lo<hi){
            int mid = (lo+hi)/2+(lo+hi)%2;
            int cur = t.contained(l-1,mid);
            if (cur < k) hi = mid-1;
            else lo = mid;
        }
        int cur = t.contained(l-1,lo);
        if (cur >= k) cout << lo+1 << ' ';
        else cout << "-1 ";        
    }
    cout << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;
}