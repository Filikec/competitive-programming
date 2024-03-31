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

            // up function
        }

        long long contained(int l, int r, int cl, int cr, int i){
            if (l <= cl && r >= cr){
                // return result
            }
            if (cl > r || cr < l) return false;
            int mid = (cl+cr)/2;
            // merge results
            return contained(l,r,cl,mid,i*2+1) + contained(l,r,mid+1,cr,i*2+2);
        }

    public:
        void build(vector<T> &a) { build(a,0,n); }

        long long contained(int l, int r) { return contained(l,r,0,n,0); }
};

template <class T> 
struct Treap{
    struct Node{
        long long k,n,p; // k - amount of values, n - amount of nodes (children+k)
        Node* c[2];
        T v;
    };

    Node NullNode, *Null, *Root;
    vector<Node> nodes;
    int used;

    Treap(int n) : used(0) {
        srand(time(NULL));
        nodes.resize(n);
        Root = Null = &NullNode;
        NullNode = {0,0,-1,Null,Null};
    }

    void clear(){
        Root = Null;
        used = 0;
    }

    Node* find(T v){
        auto cur = Root;
        while (cur != Null && cur->v != v) cur = cur->c[v>cur->v];
        return cur;
    }

    void insert(T v){
        Node *newN = &nodes[used++];
        *newN = {1,1,abs(rand()*rand()%LLONG_MAX),Null,Null,v};
        Root = insertNode(newN,Root);
    }

    Node *fix(Node *n){
       if (max(n->c[0]->p,n->c[1]->p) > n->p) n = rotate(n);
       return n;
    }

    void remove(T v){
        if (find(v) != Null) Root = removeNode(v,Root);
    }

    void erase(T v){
        Node* n;
        if ((n=find(v)) != Null) n->k=1, Root = removeNode(v,Root);
    }

    Node* rotate(Node *n){
        bool rt = n->c[0]->p>n->c[1]->p;
        Node *y = n->c[!rt];
        n->n -= y->n-y->c[rt]->n;
        n->c[!rt] = y->c[rt];
        y->n -= y->c[rt]->n-n->n;
        y->c[rt] = n;
        return y;
    }

    long long getDif(int v, bool bigger=0){
        auto node = Root;
        int count = 0;
        while (node->v != v && node != Null)
            count += (node->c[bigger]->n + node->k)*((v<node->v)==bigger), node = node->c[v>node->v];
        count += node->c[bigger]->n;
        return count;
    }

    Node* insertNode(Node *n, Node *c){
        if (c == Null) return n;
        c->n++;
        if (c->v == n->v) c->k++,used--;
        else c->c[n->v>c->v] = insertNode(n,c->c[n->v>c->v]), c = fix(c);
        return c;
    }   

    Node* removeNode(T v, Node* c){
        if (c == Null) return Null;
        if (c->v != v) c->n--, c->c[v>c->v] = removeNode(v,c->c[v>c->v]), c = fix(c);
        else if (c->k>1) c->k--,c->n--;
        else if (c->c[0]!=Null&&c->c[0]!=Null) c = removeNode(v,rotate(c));
        else c = c->c[c->c[0]==Null];
        return c;
    }       
};

struct PushRelabel{
    struct Edge{
        ll dest,back;
        ll f,c;
    };
    vector<vector<Edge>> g;
    vector<ll> ec;
    vector<Edge *> cur;
    vector<vector<ll>> hs;
    vector<ll> H;
    PushRelabel(ll n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

    void addEdge(ll s, ll t, ll cap, ll rcap=0){
        if (s == t) return;
        Edge e = {t,(ll)g[t].size(),0,cap};
        g[s].push_back(e);
        e = {s,(ll)g[s].size()-1,0,rcap};
        g[t].push_back(e);
    }

    void addFlow(Edge &e, ll f){
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[back.dest] -= f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }

    ll calc(ll s,ll t){
        ll v = g.size(); H[s] = v; ec[t] = 1;
        vector<ll> co(2*v); co[0] = v-1;
        for (ll i=0;i<v;i++) cur[i] = g[i].data();
        for (Edge& e : g[s]) addFlow(e, e.c);

        for (ll hi=0;;){
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            ll u = hs[hi].back(); hs[hi].pop_back();
            
            while (ec[u] > 0)
                if (cur[u] == g[u].data() + g[u].size()){
                    H[u] = 1e9;
                    for (Edge &e : g[u]) if (e.c && H[u] > H[e.dest]+1)
                        H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        for (ll i=0;i<v;i++) if (hi < H[i] && H[i] < v) --co[H[i]], H[i] = v+1;
                    hi = H[u];
                }else if (cur[u]->c && H[u] == H[cur[u]->dest]+1){
                    addFlow(*cur[u],min(ec[u],cur[u]->c));
                }else ++cur[u];
        }
    }

    bool leftOfMinCut(ll a) { return H[a] >= (ll)g.size();}
};

void work(){
    int n;
    cin >> n;
    int p=0;
    bool s=true;
    for (int i=0;i<n;i++){
        int cur=0;
        char c;
        for (int j=0;j<n;j++) cin >> c, cur += c-'0'; 
        if (p && cur && p != cur) s = false;
        p = cur;
    }
    if (s) cout << "SQUARE\n";
    else cout << "TRIANGLE\n";
        
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;
}