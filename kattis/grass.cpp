#include <iostream>
#include <cmath>
#include <random>
#include <time.h>


using namespace std;


class Treap{
    public:
    typedef struct node{
        long double maxi, key,end;
        long long count, priority; //count = how many key there are, nodes = how many children + 1 (node intself)
        struct node *left, *right, *parent;
    } Node;
    Node Nodes[1000000], Null_node, *Null, *Root;
    int Node_n = 0;
    default_random_engine generator;
    uniform_int_distribution<int> distribution;
    Treap(){
        Null_node.count = 0;
        Null_node.maxi = 0;
        Null_node.end = 0;
        Null_node.key = 0;
        Null = &Null_node;
        Root = Null;
        Node_n = 0;
        generator.seed(time(NULL));
    }
    void clear(){ // clears the whole tree
        Node_n = 0;
        Root = Null;
    }
    void insert(long double key, long double end, long long priority=-1, int count=1){ // inserts key into tree, if key already exists, increases count
        Node *new_node = &Nodes[Node_n++], *parent = Root;
        
        new_node->count = count;
        new_node->key = key;
        new_node->right = Null;
        new_node->left = Null;
        new_node->maxi = end;
        new_node->parent = Null;
        new_node->end = end;
        new_node->priority = distribution(generator);

        if (priority != -1) new_node->priority = priority;

        if (Root == Null){
            Root = new_node;
            return;
        }

        while (true){
            parent->maxi = max(parent->maxi,end);
            if (key < parent->key){
                if (parent->left == Null){
                    parent->left = new_node;
                    new_node->parent = parent;
                    break;
                }
                parent = parent->left;
            }else{
                if (parent->right == Null){
                    parent->right = new_node;
                    new_node->parent = parent;
                    break;
                }
                parent = parent->right;
            }
        }
        insertion_fix(new_node);
    }
    void print(Node *node){ // prints out the whole tree (doesn't print '\n' after)
        if (node == Null){
            return;
        }
        cout << "[" << node->key << "|" << node->end << "|" << node->maxi << " ";
        print(node->left);
        print(node->right);
        cout << "]";
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
        node->maxi = max(max(node->left->maxi,node->right->maxi),node->end);
        y->maxi = max(max(y->left->maxi,y->right->maxi),y->end);
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
        node->maxi = max(max(node->left->maxi,node->right->maxi),node->end);
        y->maxi = max(max(y->left->maxi,y->right->maxi),y->end);
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
};

Treap *Interval_tree;

long double Maxi=0;

void get_biggest(long double start, long double end, Treap::Node *node, Treap *tree){
    if (node->key <= end && node->end >= start) Maxi = max(Maxi,node->end);

    if (node->left != tree->Null && node->left->maxi >= start){
        get_biggest(start,end,node->left,tree);
    }
    
    if (node->right != tree->Null && node->key <= end && node->right->maxi >= start){
        get_biggest(start,end,node->right,tree);
    }
}


long double get_length(long double r, long double w){
    return sqrt(r*r-w*w/4);
}

int main(){
    int n,l,w;
    
    Interval_tree = new Treap;

    while (cin >> n >> l >> w){
        Interval_tree->clear();

        for (int i=0;i<n;i++){
            long double dist,a,b,x,r;

            cin >> x >> r;

            if (r < w/2) continue;

            if (r != w/2){
                dist = get_length(r,w);
            }else{
                dist = 0;
            }

            a = x-dist;
            b = x+dist;
            
            Interval_tree->insert(a,b);
        }

        int count=0;
        long double curr_x=0;


        while (curr_x < l){
            Maxi = 0;
            get_biggest(curr_x,curr_x,Interval_tree->Root,Interval_tree);
            count++;
            if (!Maxi || Maxi==curr_x) break;
            curr_x = Maxi;
        }

        if (curr_x < l){
            cout << "-1\n";
        }else{
            cout << count << "\n";
        }
    }
    
    return 0;
}