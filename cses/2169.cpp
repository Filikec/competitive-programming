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
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
 
#include <bits/stdc++.h>
 
using namespace std;
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
 
 
template <class T> struct Treap{
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
 
    Node* getKth(int k){
        Node* c = Root;
        int less=c->c[0]->n;
        int perm = 0;
        while (c != Null){
            less = c->c[0]->n + perm;
            if (less == k-1) return c;
            if (less < k){
                perm += c->k+c->c[0]->n;
                c = c->c[1];
            }else{
                c = c->c[0];
            }
        }
        return c;
    } 
};
 
template<const bool negative = true, const int BITS = 9, typename _RandomAccessIterator>
inline void radix_sort(_RandomAccessIterator _first, _RandomAccessIterator _last, const bool reverse = false)
{
	typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
	if(negative)
	{
		if(!reverse) {
			_RandomAccessIterator _middle = partition(_first, _last, [](value_type a) -> bool {return a<0;});	
			for(auto it = _first; it != _middle; it++)*it *= -1;
			radix_sort<false>(_first, _middle, true);
			for(auto it = _first; it != _middle; it++)*it *= -1;
			radix_sort<false>(_middle, _last);
		} else {
			_RandomAccessIterator _middle = partition(_first, _last, [](value_type a) -> bool {return a>=0;});	
			radix_sort<false>(_first, _middle, true);
			for(auto it = _middle; it != _last; it++)*it *= -1;
			radix_sort<false>(_middle, _last);
			for(auto it = _middle; it != _last; it++)*it *= -1;
		}
		return;
	}
	constexpr int PART = (1<<BITS);
	constexpr int FULL = (1<<BITS)-1;
	int shift = 0;
	auto MAX = *max_element(_first, _last);
	vector<value_type> P[PART];
	while(log2(MAX) >= shift)
	{
		for(auto it = _first; it != _last; it++)P[(((*it)>>shift)&FULL)^(reverse?FULL:0)].push_back(*it);
		auto it = _first;
		for(int i = 0; i < PART; i++)
		{
			for(auto u: P[i]) *it++ = u;
			P[i].clear();
		}
		shift += BITS;
	}
}
 
 
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<pair<pll,int>> v(n);
    Treap<int> t(2*n);
    vll a(n),b(n);
    rep(i,n){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second=i;
    }
 
    for (auto &c : v) t.insert(c.first.second);
    
    for (auto &c : v){
        int less = t.getDif(c.first.second)+t.find(c.first.second)->k-1;
        t.remove(c.first.second);
        a[c.second] = less;
    }
 
    for (auto it = v.rbegin();it!=v.rend();it++) t.insert(it->first.second);
    
 
    for (auto it = v.rbegin();it!=v.rend();it++){
        int more = t.getDif(it->first.second,true)+t.find(it->first.second)->k-1;
        t.remove(it->first.second);
        b[it->second] = more;
    }
 
 
    rep(i,n)cout << a[i] << ' ';
    cout << '\n';
    rep(i,n)cout << b[i] << ' ';
    cout << '\n';
    return 0;
}