#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;


struct SegmentTree{
    vector<int> tree; // potentially change type
    int n;

    SegmentTree(int n) : n(n) { 
        int size = 1 << (int) (log2(n)+1);
        tree.resize(2*size-1,1e8);  
    }
    private:
        void build(vector<int> &a, int l, int r, int i=0){
            if (l == r){
                tree[i] = {a[l]};
                return;
            }

            int mid = (l+r)/2;
            build(a,l,mid,(i+1)*2-1);
            build(a,mid+1,r,(i+1)*2);

            tree[i] = min(tree[2*i+1],tree[2*i+2]);
        }

        int contained(int l, int r, int cl, int cr, int i){
            if (l <= cl && r >= cr){
                return tree[i];
            }
            if (cl > r || cr < l) return 1e8;
            int mid = (cl+cr)/2;
            // merge results
            return min(contained(l,r,cl,mid,(i+1)*2-1), contained(l,r,mid+1,cr,(i+1)*2));
        }

    public:
        void build(vector<int> &a) { build(a,0,n); }

        int contained(int l, int r) { return contained(l,r,0,n,0); }

        void insert(int v, int s, int l, int r, int i=0){
            if (l == r){
                if (l == s){
                    tree[i] = v;
                }
                return;
            }
            int mid = (l+r)/2;
            insert(v,s,l,mid,(i+1)*2-1);
            insert(v,s,mid+1,r,(i+1)*2);

            tree[i] = min(tree[2*i+1],tree[2*i+2]);
        }
};

SegmentTree Tree(3*1e5);
vector<int> W(3*1e5);

list<int> getCycle(list<pii> &s, int lowest){
    int curN = -1;
    int curL = W[s.front().second];
    int cur = s.front().first;
    s.pop_front();
    list<int> path;
    while (lowest != curL || cur != curN){
        auto p = s.front();
        s.pop_front();
        curN = p.first;
        if (p.second != 1e8) curL = min(curL,W[p.second]);
        path.push_back(curN);
    }

    return path;
}

pair<int,bool> findBest(vector<list<pii>> &g, int cur, map<int,int> &used, int size, set<int> &es, list<pii> &s, int lowest = -1){
    pair<int,bool> best = {1e8,0}; 
    for (auto n : g[cur]){
        if (es.count(n.second)) continue;
        es.insert(n.second);
        Tree.insert(W[n.second],size,0,3*1e5);
        s.push_front(n);
        if (used.count(n.first)){
            best.first = min(best.first,Tree.contained(used[n.first]+1,size));
            if (best.first == lowest){
                auto l = getCycle(s,lowest);
                cout << l.size() << '\n';
                for (auto n : l) cout << n << ' ';
                cout << '\n';
                return {1,1};
            }
        }else{
            used[n.first] = size;
        }
        auto res = findBest(g,n.first,used,++size,es,s,lowest);
        if (res.second) return res;
        best.first = min(best.first,res.first);
    }
    size--;
    if (s.size()) s.pop_front();
    return best;
}


void work(){
    int n,m;
    cin >> n >> m;

    vector<list<pair<int,int>>> g(2*n);

    for (int i=0;i<m;i++){
        int a,b,v;
        cin >> a >> b >> v;
        W[i] = v;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }

    map<int,int> indices;
    set<int> es;
    list<pii> s;
    int best = 1e8;
    for (int i=1;i<=n;i++){
        if (!indices.count(i)){
            indices[i] = 0;
            Tree.insert(1e8,0,0,3*1e5);
            s.clear();
            best = min(best,findBest(g,i,indices,1,es,s).first);
        }
    }
    cout << best << ' ';

    indices.clear(),es.clear();
    for (int i=1;i<=n;i++){
        if (!indices.count(i)){
            s = {{i,1e8}};
            indices[i] = 0;
            Tree.insert(1e8,0,0,3*1e5);
            if (findBest(g,i,indices,1,es,s,best).second) break;
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