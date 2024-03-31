#include <iostream>
#include <list>

using namespace std;


typedef struct node{
    int prio, key, count;
    struct node *p,*l,*r;
} Node;


Node Nodes[2000], Null_node, *Null = &Null_node, *Root;
int Used;

void clear(){
    Root = Null;
    Used = 0;
}

void right_rotate(Node *parent){ //changes places with left child
    Node *child = parent->l;

    child->p = parent->p;

    if (parent->p == Null){
        Root = child;
    }else if (parent->p->l == parent){
        parent->p->l = child;
    }else{
        parent->p->r = child;
    }

    parent->l = child->r;
    child->r->p = parent;

    child->r = parent;
    parent->p = child;
}

void left_rotate(Node *parent){ //changes places with right child
    Node *child = parent->r;

    child->p = parent->p;

    if (parent->p == Null){
        Root = child;
    }else if (parent->p->l == parent){
        parent->p->l = child;
    }else{
        parent->p->r = child;
    }

    parent->r = child->l;
    child->l->p = parent;

    child->l = parent;
    parent->p = child;
}

void fixup(Node *node){
    Node *parent;

    while ((parent=node->p)!=Null && parent->prio < node->prio){
        if (parent->l == node){
            right_rotate(parent);
        }else{
            left_rotate(parent);
        }
    }
}

Node *add_node(int key, int count){
    Node *new_node = &Nodes[Used++];

    *new_node = {rand(),key,count,Null,Null,Null};

    if (Root == Null){
        Root = new_node;
        return;
    }

    Node *parent = new_node->p;

    while (true){
        if (key < parent->key){
            if (parent->l == Null){
                parent->l = new_node;
                new_node->p = parent;
                break;
            }
            parent = parent->l;
        }else if (key > parent->key){
            if (parent->r == Null){
                parent->r = new_node;
                new_node = parent;
                break;
            }
            parent = parent->r;
        }else{
            parent->count+=count;
            Used--;
            return parent;
        }
    }
    fixup(new_node);
    return new_node;
}

Node * find(int key){
    Node *parent = Root;

    while (parent && parent->key != key){
        if (key < parent->key){
            parent = parent->l;
        }else if (key > parent->key){
            parent = parent->r;
        }
    }

    return parent;
}

void change_nodes(Node *parent, Node *child){ //assume parent doesn't have second child
    child->p = parent->p;
    if (parent->p == Null){
        Root = child;
    }else if (parent->p->l == parent){
        parent->p->l = child;
    }else{
        parent->p->r = child;
    }
}

void remove_node(Node *node){
    if (node->count > 1){
        node->count--;
        return;
    }

    Node *left, *right;

    while ((left = node->l) != Null && (right = node->r) != Null){
        if (left->prio > right->prio){
            right_rotate(node);
        }else{
            left_rotate(node);
        }
    }

    left = node->l, right = node->r;

    if (left == Null){
        change_nodes(node,node->r);
    }else{
        change_nodes(node,node->l);
    }
}

Node *find_closest(int key){
    Node *curr = Root;
    Node *closest = Root;


    while (curr && curr->key != key){
        if (curr->key > key){
            if (closest->key > curr->key) closest = curr;
            curr = curr->l;
        }else{
            if (closest->key > curr->key) closest = curr;
            curr = curr->r;
        }
    }

    if (curr == Null) return Null;

    
    curr = curr->r;
    while (curr!=Null){
        if (closest->key > curr->key) closest = curr;
        curr = curr->l;
    }

    return closest;
}

#define DELTA 10000000


int Count[20000001];
list<int> Slots;


bool cmp(int a, int b){
    return a < b;
}

int main(){
    int n,s,t;
    long long time=0;

    cin >> n >> s >> t;


    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if (!Count[tmp+DELTA]){
            Slots.push_back(tmp);
        }
        Count[tmp+DELTA]++;
        
    }

    Slots.sort(cmp);


    int last_slot = 0;
    for (auto curr : Slots){
        int amount = Count[curr+DELTA];
        clear();
        for (auto e : Slots){
            add_node(e,Count[e+DELTA]);
        }
        int curr_slot = (curr%s+t%s)%s;
        remove_node(find(curr));

        while (Root != Null){
            Node *new_node = find_closest(curr);
            
        }
    }

    return 0;
}