#include <iostream>
#include <time.h>
#include <random>

using namespace std;


class Treap{
    public:
    typedef struct node{
        long long count, nodes, key, priority, assistant; //count = how many key there are, nodes = how many children + 1 (node intself)
        struct node *left, *right, *parent;
    } Node;
    Node Nodes[1000000], Null_node, *Null, *Root;
    int Node_n = 0;
    default_random_engine generator;
    uniform_int_distribution<int> distribution;
    Treap(){
        Null_node.count = 0;
        Null_node.nodes = 0;
        Null = &Null_node;
        Root = Null;
        Node_n = 0;
        generator.seed(time(NULL));
    }
    void clear(){ // clears the whole tree
        Node_n = 0;
        Root = Null;
    }
    void insert(long long key, long long assistant, long long priority=-1, int count=1){ // inserts key into tree, if key already exists, increases count
        Node *new_node = &Nodes[Node_n++], *parent = Root;
        
        new_node->count = count;
        new_node->nodes = count;
        new_node->key = key;
        new_node->assistant = assistant;
        new_node->right = Null;
        new_node->left = Null;
        new_node->parent = Null;
        new_node->priority = distribution(generator);
        if (priority != -1) new_node->priority = priority;

        if (Root == Null){
            Root = new_node;
            return;
        }

        while (true){
            parent->nodes+=count;
            if (key < parent->key){
                if (parent->left == Null){
                    parent->left = new_node;
                    new_node->parent = parent;
                    break;
                }
                parent = parent->left;
            }else if (key > parent->key){
                if (parent->right == Null){
                    parent->right = new_node;
                    new_node->parent = parent;
                    break;
                }
                parent = parent->right;
            }else{
                if (priority!=-1) parent->priority = priority;
                parent->count+=count;
                Node_n--;
                new_node = parent;
                break;
            }
        }
        insertion_fix(new_node);
    }
    void insert(Node *new_node){ // inserts key into tree, if key already exists, increases count
        Node *parent = Root;
        new_node->left = Null;
        new_node->right = Null;
        new_node->parent = Null;
        new_node->nodes = new_node->count;
        if (Root == Null){
            Root = new_node;
            return;
        }

        while (true){
            parent->nodes+=new_node->count;
            if (new_node->key < parent->key){
                if (parent->left == Null){
                    parent->left = new_node;
                    new_node->parent = parent;
                    break;
                }
                parent = parent->left;
            }else if (new_node->key > parent->key){
                if (parent->right == Null){
                    parent->right = new_node;
                    new_node->parent = parent;
                    break;
                }
                parent = parent->right;
            }else{
                parent->count+=new_node->count;
                Node_n--;
                return;
            }
        }
        insertion_fix(new_node);
    }
    Node *find(long long key){ // return Null if key is not in tree, node pointer otherwise
        Node *node = Root;
        while (node != Null){
            if (key < node->key){
                node = node->left;
            }else if (key > node->key){
                node = node->right;
            }else{
                break;
            }
        }
        return node;
    }
    void print(Node *node){ // prints out the whole tree (doesn't print '\n' after)
        if (node == Null){
            return;
        }
        cout << "[" << node->key << "|" << node->count << "|" << node->nodes << " ";
        print(node->left);
        print(node->right);
        cout << "]";
    }
    void delete_node(Node *node){ // deletes all appearances of key in tree
        if (node == Null){
            return;
        }
        while (node->left != Null && node->right != Null){
            if (node->left->priority > node->right->priority){
                right_rotate(node);
            }else{
                left_rotate(node);
            }
        }
        if (node->left == Null){
            replace(node,node->right);
        }else{
            replace(node,node->left);
        }
    }
    void remove(Node *node){ //removes node from tree, if count > 1, decreases count
        if (node == Null){
            return;
        }
        if (node->count > 1){
            node->count--;
            while (node != Null){
                node->nodes--;
                node = node->parent;
            }
            return;
        }else{
            delete_node(node);
        }
    }
    void remove(long long key){ //removes key from tree, if count > 1, decreases count
        Node *node = find(key);
        if (node == Null){
            return;
        }
        if (node->count > 1){
            node->count--;
            while (node != Null){
                node->nodes--;
                node = node->parent;
            }
            return;
        }else{
            delete_node(node);
        }
    }
    void push_to_top(Node *node){ // pushes node to be the root
        if (node == Null){
            return;
        }
        node->priority = Root->priority+1;
        insertion_fix(node);

    }
    void push_to_top(long long key){ // if node with given key exists, pushes it to be the root, creates a new node to be the root with given key otherwise
        Node *node = find(key);
        if (node == Null){
            insert(key,Root->priority+1);
            return;
        }
        node->priority = Root->priority+1;
        insertion_fix(node);
    }

    private:
    void left_rotate(Node *node){ //exchange node with its right child
        Node *y = node->right;
        node->right = y->left;

        if (y->left != Null){
            y->left->parent = node;
        }
        y->parent = node->parent;
        
        if (node->parent == Null){
            Root = y;
        }else if(node == node->parent->left){
            node->parent->left = y;
        }else{
            node->parent->right = y;
        }

        y->left = node;
        node->parent = y;

        // keep count precise
        node->nodes = node->left->nodes + node->right->nodes + node->count;
        y->nodes = y->left->nodes + y->right->nodes + y->count;
    }
    void right_rotate(Node *node){ //exchange node with its left child
        Node *y = node->left;
        node->left = y->right;

        if (y->right != Null){
            y->right->parent = node;
        }
        y->parent = node->parent;
        
        if (node->parent == Null){
            Root = y;
        }else if(node == node->parent->left){
            node->parent->left = y;
        }else{
            node->parent->right = y;
        }

        y->right = node;
        node->parent = y;

        // keep count precise
        node->nodes = node->left->nodes + node->right->nodes + node->count;
        y->nodes = y->left->nodes + y->right->nodes + y->count;
    }
    void insertion_fix(Node *node){//fixes heap property after insertion
        while (node != Null && node->parent->priority < node->priority && node->parent != Null){
            if (node->parent->left == node){
                right_rotate(node->parent);
            }else{
                left_rotate(node->parent);
            }
        }
    }
    void replace(Node *node, Node *child){//replaces child with it's parent
        child->parent = node->parent;

        if (child->parent == Null){
            Root = child;
        }else if (node->parent->left == node){
            node->parent->left = child;
        }else{
            node->parent->right = child;
        }
        int count = node->count;
        while (node != Null){
            node->nodes -= count;
            node = node->parent;
        }
    }
    bool is_treap(Node *node){ //returns whether tree follows heap property
        if (node == Null) return true;

        if (node->parent == Null) return true;

        if (node->parent->priority < node->priority) return false;

        return (is_treap(node->left) && is_treap(node->right));
    }
};


#include <list>
#include <unordered_set>

int Assistants[100000][2];
Treap *A, *B;


int main(){
    int n, k;

    A = new Treap();
    B = new Treap();

    cin >> n >> k;

    for (int i=0;i<n;i++){
        cin >> Assistants[i][0] >> Assistants[i][1];
        A->insert(Assistants[i][0],i);
        B->insert(Assistants[i][1],i);
    }

    

    return 0;
}