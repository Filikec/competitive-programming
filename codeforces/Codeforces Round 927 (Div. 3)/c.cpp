#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


template<class T>
struct SegmentTree{
    vector<T> tree;
    int n;
    int m;

    SegmentTree(int n, int m) : n(n), m(m) { 
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

            tree[i] = tree[i*2+1]*tree[i*2+2]%m;
        }

        ll contained(int l, int r, int cl, int cr, int i){
            if (l <= cl && r >= cr){
                return tree[i];
            }
            if (cl > r || cr < l) return 1;
            int mid = (cl+cr)/2;
            // merge results
            return contained(l,r,cl,mid,i*2+1)*contained(l,r,mid+1,cr,i*2+2)%m;
        }

    public:
        void build(vector<T> &a) { build(a,0,n); }

        ll contained(int l, int r) { return contained(l,r,0,n,0); }
};

void work(){
    ll n,m;
    cin >> n >> m;

    vector<ll> v(n);

    for (auto &c : v) cin >> c;

    SegmentTree<ll> seg(n,m);
    seg.build(v);

    int lo=0,hi=n-1;
    string s;
    cin >> s;
    for (auto c : s){
        cout << seg.contained(lo,hi) << ' ';
        if (c == 'L') lo++;
        else hi--;
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