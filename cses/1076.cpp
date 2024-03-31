#include <bits/stdc++.h>

using namespace std;

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
        int less=0,perm=0;
        while (c != Null){
            less = c->c[0]->n + perm;
            if (less == k-1 || c->k > abs(less-k+1)) return c;
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


int main(){

    int n,k;
    cin >> n >> k;

    Treap<long long> t(n);
    list<long long> q;
    for (int i=0;i<k;i++){
        long long c;
        cin >> c;
        q.push_back(c);
        t.insert(c);
    }


    for (int i=0;i<n-k;i++){
        long long c;
        cin >> c;
        cout << t.getKth(t.Root->n/2+t.Root->n%2)->v << " ";
        t.remove(q.front());
        q.pop_front();
        t.insert(c);
        q.push_back(c);
    }
    cout << t.getKth(t.Root->n/2+t.Root->n%2)->v << "\n";

    return 0;
}