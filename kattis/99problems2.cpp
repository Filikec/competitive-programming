#include <iostream>
#include <ctime>
#include <climits>
#include <unordered_set>

using namespace std;

class Treap{
    public:
    struct Node{
        long long k, n, key, pr; // k = how many keys there are, n = how many children + k (node intself)
        Node *p, *c[2];
        Node(){}
        Node(long long k, long long n, long long key, long long pr, Node *p, Node *c1, Node *c2) : k(k), n(n), key(key), pr(pr), p(p) {
            this->c[0] = c1;
            this->c[1] = c2;
        }
    };
    Node Null_node, *Null, *Root;
    Treap(){
        Null = &Null_node;
        Null_node = {0,0,0,-1,Null,Null,Null};
        Root = Null;
        srand(time(NULL));
    }
    void clear(){ // clears the whole tree
        clearNode(Root);
        Root = Null;
    }
    void updateNode(Node*cur,Node*prev,int k,int key){
        *cur = {k+prev->k,k+prev->n,key,prev->pr==-1?rand()*rand()%LLONG_MAX:prev->pr,prev->p,prev->c[0],prev->c[1]};
        for (int i=0;i<2;i++) if (prev->c[i] != Null) prev->c[i]->p = cur;
    }
    void insert(long long key, int k=1){ // inserts key into tree, if key already exists, increases k
        Node *new_node = new Node(), *p = Root;
        if (Root == Null || Root->key==key){
            updateNode(new_node,Root,k,key);
            Root = new_node;
            return;
        }
        int cmp = key>p->key;
        while (p->c[cmp]!=Null && p->c[cmp]->key!=key){
            p->n+=k;
            p = p->c[cmp];
            cmp = key>p->key;
        }
        p->n+=k;
        updateNode(new_node,p->c[cmp],k,key);
        new_node->p = p;
        p->c[cmp] = new_node;        
        fix(new_node);  
    }
    Node *find(long long key){ // return Null if key is not in tree, node pointer otherwise
        Node *node = Root;
        while (node != Null && node->key != key){
            node = node->c[key>node->key];
        }
        return node;
    }
    void delete_node(Node *node){ // deletes all appearances of key in tree
        if (node == Null){
            return;
        }
        while (node->c[0] != Null && node->c[1] != Null){
            rotate(node,node->c[0]->pr > node->c[1]->pr);
        }
        replace(node,node->c[node->c[0] == Null]);
    }
    void remove(long long key){ //removes key from tree, if k > 1, decreases k
        Node *node = find(key);
        if (node == Null){
            return;
        }
        if (node->k > 1){
            node->k--;
            while (node != Null){
                node->n--;
                node = node->p;
            }
            return;
        }else{
            delete_node(node);
        }
    }
    private:
    void clearNode(Node*n){
        if (n==Null) return;
        clearNode(n->c[0]);
        clearNode(n->c[1]);
        delete n;
    }
    void rotate(Node *node, bool rt){
        Node *y = node->c[!rt];
        node->c[!rt] = y->c[rt];

        if (y->c[rt] != Null){
            y->c[rt]->p = node;
        }
        y->p = node->p;
        if (node->p == Null){
            Root = y;
        }else{
            node->p->c[node != node->p->c[0]] = y;
        }
        y->c[rt] = node;
        node->p = y;
        // keep k precise
        node->n = node->c[0]->n + node->c[1]->n + node->k;
        y->n = y->c[0]->n + y->c[1]->n + y->k;
    }
    void fix(Node *node){//fixes heap property after insertion
        while (node != Null && node->p->pr < node->pr && node->p != Null){
            rotate(node->p,node->p->c[0] == node);
        }
    }
    void replace(Node *node, Node *child){//replaces child with it's p
        child->p = node->p;
        if (child->p == Null){
            Root = child;
        }else{
            node->p->c[node->p->c[0] != node] = child;
        }
        long long k = node->k;
        while (node != Null){
            node->n -= k;
            node = node->p;
        }
    }   
};

Treap treap;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;

    cin >> n >> q;

    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        treap.insert(tmp);
    }

    for (int i=0;i<q;i++){
        int t, d;
        cin >> t >> d;
        
        treap.insert(d);
        auto it = treap.find(d);

        if (t==1){
            if (it->c[1] == treap.Null){
                cout << "-1\n";
            }else{
                cout << it->c[1]->key << '\n';
                treap.remove(it->c[1]->key);
            }
        }else{
            if (it->k > 1){
                cout << it->key << '\n';
                treap.remove(it->key);
            }else if (it->c[0] != treap.Null){
                cout << it->c[0]->key << '\n';
                treap.remove(it->c[0]->key);
            }else{
                cout << "-1\n";
            }
        }
        treap.remove(it->key);
    }


}