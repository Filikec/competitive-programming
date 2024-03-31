#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;


struct SegmentTreeMax{
    vector<pii> tree; // potentially change type
    int n;

    SegmentTreeMax(int n) : n(n) { 
        int size = 1 << (int) (log2(n)+1);
        tree.resize(2*size-1);  
    }
    private:
        void build(vector<pii> &a, int l, int r, int i=0){
            if (l == r){
                tree[i] = a[l];
                return;
            }

            int mid = (l+r)/2;
            build(a,l,mid,(i+1)*2-1);
            build(a,mid+1,r,(i+1)*2);

            tree[i] = max(tree[(i+1)*2-1],tree[(i+1)*2]);
        }

        pii contained(int l, int r, int cl, int cr, int i){
            if (l <= cl && r >= cr){
                return tree[i];
            }
            if (cl > r || cr < l) return {-1,-1};
            int mid = (cl+cr)/2;
            return max(contained(l,r,cl,mid,(i+1)*2-1),contained(l,r,mid+1,cr,(i+1)*2));
        }

    public:
        void build(vector<pii> &a) { build(a,0,n); }

        pii contained(int l, int r) { return contained(l,r,0,n,0); }
};

struct SegmentTreeMin{
    vector<pii> tree; // potentially change type
    int n;

    SegmentTreeMin(int n) : n(n) { 
        int size = 1 << (int) (log2(n)+1);
        tree.resize(2*size-1);  
    }
    private:
        void build(vector<pii> &a, int l, int r, int i=0){
            if (l == r){
                tree[i] = a[l];
                return;
            }

            int mid = (l+r)/2;
            build(a,l,mid,(i+1)*2-1);
            build(a,mid+1,r,(i+1)*2);

            tree[i] = min(tree[(i+1)*2-1],tree[(i+1)*2]);
        }

        pii contained(int l, int r, int cl, int cr, int i){
            if (l <= cl && r >= cr){
                return tree[i];
            }
            if (cl > r || cr < l) return {1e8,-1};
            int mid = (cl+cr)/2;
            return min(contained(l,r,cl,mid,(i+1)*2-1),contained(l,r,mid+1,cr,(i+1)*2));
        }

    public:
        void build(vector<pii> &a) { build(a,0,n); }

        pii contained(int l, int r) { return contained(l,r,0,n,0); }
};

void work(){
    int n;
    cin >> n;
    SegmentTreeMax stMax(n);
    SegmentTreeMin stMin(n);

    vector<pii> v(n);
    for (int i=0;i<n;i++) cin >> v[i].first, v[i].second = i;
    stMax.build(v);
    stMin.build(v);

    int q;
    cin >> q;
    for (int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        auto r1 = stMax.contained(a,b);
        auto r2 = stMin.contained(a,b);

        if (r1.second == -1 || r2.second == -1 || r1.first == r2.first){
            cout << -1 << ' ' << -1 << "\n";
        }else{
            cout << r1.second+1 << ' ' << r2.second+1 << "\n";
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--){
        work();
    }

    return 0;
}