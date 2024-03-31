#include <iostream>

using namespace std;

typedef struct rb_node{
    long long key;
    bool color; // true - red
    struct rb_node *left, *right, *parent;

} RB_node;

RB_node RB_sent, RB_nodes[500000], *RB_root;
RB_node *RB_nil = &RB_sent;


void rb_left_rotate(RB_node *x){
    RB_node *y = x->right;

    x->right = y->left;

    if (y->left != RB_nil){
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == RB_nil){
        RB_root = y;
    }else if (x->parent->left == x){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rb_right_rotate(RB_node *x){
    RB_node *y = x->left;

    x->left = y->right;

    if (y->right != RB_nil){
        y->right->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == RB_nil){
        RB_root = y;
    }else if (x->parent->left == x){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

void rb_insert_fixup(RB_node *z){
    RB_node *y,*x;
    while (z->parent->color){ // while is red
        if (z->parent == z->parent->parent->left){
            y = z->parent->parent->right;
            if (y->color){
                z->parent->color = false;
                y->color = false;
                y->parent->parent->color = true;
                z = z->parent->parent;
            }else if (z == z->parent->right){
                z = z->parent;
                rb_left_rotate(z);
            }else{
                z->parent->color = false;
                z->parent->parent->color = true;
                rb_right_rotate(z->parent->parent);
            }
        }
    }
}

void rb_insert(RB_node *z){
    RB_node *y = RB_nil;
    RB_node *x = RB_root;

    while (x != RB_nil){
        y = x;
        if (z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if (y == RB_nil){
        RB_root = z;
    }else if (z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }
    z->left = RB_nil;
    z->right = RB_nil;
    z->color = true;
    rb_insert_fixup(z);
}

int main(){
    




    return 0;
}