#include <iostream>
#include <random>

using namespace std;


class Treap{
    public:
    typedef struct node{
        long long count, priority, key, nodes; //count = how mant appearances of this key, nodes = how many nodes including itself
        struct node *left, *right, *parent;
    } Node;
    Node Nodes[1000000], *Root, Null_node, *Null = &Null_node;
    int Node_count;
    default_random_engine generator;
    uniform_int_distribution<long long> distribution;
    Treap(){
        Node_count = 0;
        Null_node.count = 0;
        Root = Null;
        distribution = distribution;
    }
    void clear(){
        Node_count = 0;
        Root = Null;
    }
    Node *find(long long value){ //if return Null (in class), isn't present
        Node *node = Root;

        while (node != Null && node->key != value){
            if (value < node->key){
                node = node->left;
            }else{
                node = node->right;
            }
        }

        return node;
    }
    void insert(long long value, long long priority=-1){
        Node *new_node = &Nodes[Node_count++], *parent = Root;

        if (priority == -1) priority = get_priority();

        new_node->count = 1;
        new_node->nodes = 1;
        new_node->key = value;
        new_node->left = Null;
        new_node->right = Null;
        new_node->priority = priority;
        
        if (Root == Null){
            new_node->parent = Null;
            Root = new_node;
            return;
        }

        while (true){
            parent->nodes++;
            if (value < parent->key){
                if (parent->left == Null){
                    parent->left = new_node;
                    new_node->parent = parent;
                    break;
                }
                parent = parent->left;
            }else if (value > parent->key){
                if (parent->right == Null){
                    parent->right = new_node;
                    new_node->parent = parent;
                    break;
                }
                parent = parent->right;
            }else{
                Node_count--;
                parent->count++;
                return;
            }
        }
        insertion_fix(new_node); 
    }
    void print(Node *node){
        if (node == Null){
            return;
        }
        cout << "[" << node->key << ":" << node->nodes << " ";
        print(node->left);
        print(node->right);
        cout << "]";
    }
    bool is_treap(Node *node){
    
        if (node == Null) return true;

        if (!is_treap(node->left) || !is_treap(node->right)) return false;

        if (node->parent == Null || node->parent->priority >= node->priority) return true;

        return false;
    }
    private:
    void insertion_fix(Node *node){
        while (node->parent != Null && node->parent->priority < node->priority){
            if (node->parent->right == node){
                left_rotate(node->parent);
            }else{
                right_rotate(node->parent);
            }
        }
    }
    long long get_priority(){
        return distribution(generator);
    }
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

        // keep nodes precise
        node->nodes = node->left->nodes + node->right->nodes + node->count;
        y->nodes = y->left->nodes + y->right->nodes + node->count;
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

        // keep nodes precise
        node->nodes = node->left->nodes + node->right->nodes + node->count;
        y->nodes = y->left->nodes + y->right->nodes + y->count;
    }

};

int Numbers[100000];

int get_count(long long key, Treap *treap, bool is_less=false){
    Treap::Node *node = treap->Root;
    int more = 0, less = 0;

    while (node != treap->Null && node->key != key){
        if (key > node->key){
            less += node->left->nodes+1;
            node = node->left;
        }else if (key < node->key){
            more += node->right->nodes+1;
            node = node->right;
        }
    }

    if (node != treap->Null){
        more += node->right->nodes;
        less += node->left->nodes;
    }
    
    if (is_less){
        return less;
    }
    return more;


}

Treap *Tree;

long long find_median(){
    Treap::Node *node = Tree->Root;
    long long left = node->left->nodes, right = node->right->nodes, value;

    while (abs(right-left) > 1){
        if (right > left){
            node = node->right;
            left += node->left->nodes+1;
            right -= node->left->nodes+1;
        }else{
            node = node->left;
            right += node->right->nodes+1;
            left -= node->right->nodes+1;
        }
    }
    value = node->key;
    if (right == left){
        return value;
    }

    if (right > left){
        node = node->right;
        left += node->left->nodes+1;
        right -= node->left->nodes+1;
    }else{
        node = node->left;
        right += node->right->nodes+1;
        left -= node->right->nodes+1;
    }

    while (abs(right-left) > 1){
        if (right > left){
            node = node->right;
            left += node->left->nodes+1;
            right -= node->left->nodes+1;
        }else{
            node = node->left;
            right += node->right->nodes+1;
            left -= node->right->nodes+1;
        }
    }

    value += node->key;
    return value/2;
}




void work(){
    long long n, result = 0;
    Tree->clear();
    cin >> n;

    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        Tree->insert(tmp);
        result += find_median();
    }

    cout << result << "\n";

    
}

int main(){
    Tree = new Treap;
    long long result = 0;
    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        work();
    }
}