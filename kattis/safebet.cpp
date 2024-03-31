#include <iostream>

using namespace std;


class Treap{
    public:
    typedef struct node{
        struct node *p,*l,*r;
        int key;
    } Node;

    Node null_node, *Null = &null_node, *Root = Null;
    Treap(){
        null_node.key = 1000001;
    }
    void add_node(int k){
        Node *new_node = new Node;
        new_node->l = Null;
        new_node->r = Null;
        new_node->p = Null;
        new_node->key = k;
        if (Root == Null){
            Root = new_node;
            return;
        }

        Node *node = Root;
        while (true){
            if (k < node->key){
                if (node->l == Null){
                    node->l = new_node;
                    new_node->p = node;
                    break;
                }
                node = node->l;
            }else{
                if (node->r == Null){
                    node->r = new_node;
                    new_node->p = node;
                    break;
                }
                node = node->r;
            }
        }
    }

    Node *find_next(int k){
        Node *next = Root,*best=Null;
        while (next!=Null&&next->key!=k){
            if (k < next->key){
                if (next->key < best->key) best = next;
                next = next->l;
            }else{
                next = next->r;
            }
        }
        if (next == Null) return best;
        next = next->r;
        while (next!=Null){
            if (next->key < best->key) best = next;
            next = next->l;
        }
        return best;
    }
};

Treap Graph[1000000];

int main(){
    cout << Graph[0].find_next(1)->key << '\n';
    return 0;
}