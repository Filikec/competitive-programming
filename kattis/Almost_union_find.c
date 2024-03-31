#include <stdio.h>
#include <stdlib.h>

typedef struct child{
    struct node *node;
    struct child *next;
    struct child *prev;
} Child;

typedef struct node{
    struct node *prev;
    struct child *child;
    long long int number; // add list of children
} Node;

typedef struct set{
    long long int cardinality;
    long long int sum;
    Node *root; 
} Set;

Set Sets[100001]; // each set
Node Numbers[100001]; //each number
Child Children[100001]; //each number


void print_node(Node *node){
    Child *child;

    printf("%lld ",node->number);
    child = node->child;

    while (child){
        print_node(child->node);
        child = child->next;
    }
}

Set *get_set(long long int n1){
    Node *next;

    next = &Numbers[n1];

    while (next->prev){
        next = next->prev;
    }
    
    return &Sets[next->number];
}

void remove_child(Child *child){
    Node *parent, *node;
    Set *set1, *set2;

    node = child->node;
    parent = node->prev;

    if (!parent){ // the node is a root node of a set
        return;
    }
    
    if (child->prev && child->next){ // the node is a child of a node and is neither first nor last
        child->prev->next = child->next;
        child->next->prev = child->prev;
    }
    
    if (!child->prev){ // the node is the first child of another node
        parent->child = child->next;
        if (child->next){
            child->next->prev = NULL;
        }
    }
    
    if (!child->next){ // the node is the last child of a node
        if (child->prev)
            child->prev->next = NULL;
    }
    
    child->prev = NULL;
    child->next = NULL;
}

void add_node_as_child(Node *node1, Node *node2){
    Child *new_child;
    
    new_child = &Children[node1->number];

    if (node2->child){
        node2->child->prev = new_child;
    }

    new_child->next = node2->child;
    node2->child = new_child;

    node1->prev = node2;

}

void print_set(long long int n1){
    Set *set;

    set = get_set(n1);
    printf("%lld %lld\n",set->cardinality,set->sum);
    return;
}

void move_num(long long int n1, long long int n2){
    Set *set1, *set2, *new_set;
    Node *node1, *node2, *next, *root, *new_root;
    Child *next_child, *next_next_child;

    set1 = get_set(n1);
    set2 = get_set(n2);

    if (set1 == set2){
        return;
    }

    node1 = &Numbers[n1];
    node2 = set2->root;

    if (node1 == set1->root){
       
        root = set1->root;
        if (root->child){
           
            new_root = root->child->node;
            new_root->prev = NULL;

            new_set = &Sets[new_root->number];
            new_set->cardinality = set1->cardinality - 1;
            new_set->sum = set1->sum - n1;
            new_set->root = new_root;

            set1->cardinality = 0;
            set1->sum = 0;

            next_child = root->child->next;
                
            while (next_child){
                
                next_next_child = next_child->next;

                next_child->prev = NULL;
                next_child->next = new_root->child;
                if (new_root->child){
                    new_root->child->prev = next_child;
                }
                
                new_root->child = next_child;

                next_child->node->prev = new_root;

                next_child = next_next_child;
            }
            root->child = NULL;

        }
        set1->root = NULL;
    }else{
        root = node1->prev;

        next_child = node1->child;

        while (next_child){

            next_next_child = next_child->next;

            if (root->child){
                root->child->prev = next_child;
            }
            
            next_child->prev = NULL;
            next_child->next = root->child;
            
            root->child = next_child;

            next_child->node->prev = root;

            next_child = next_next_child;
        }

        node1->child = NULL;

    }


    remove_child(&Children[n1]);
    
    add_node_as_child(node1,node2);

    set2->cardinality++;
    set2->sum += n1;

    if (set1->cardinality){
        set1->cardinality--;
        set1->sum -= n1;
    }
    

    return;
}

void union_nums(long long int n1, long long int n2){
    Set *set1, *set2; //set1 will be transfered to set2
    Node *root1, *root2;
    Child *new_child;
    
    set1 = get_set(n1);
    set2 = get_set(n2);

    if (set1 == set2){
        return;
    }

    add_node_as_child(set1->root,set2->root);

    set2->cardinality += set1->cardinality;
    set2->sum += set1->sum;

    set1->cardinality = 0;
    set1->sum = 0;
    set1->root = NULL;
}

int main(){
    long long int n, m, i, n1, n2, cases, command;


    for (cases=0;cases<20;cases++){
         if (scanf("%lld %lld",&n,&m) == EOF){
            return 0;
        }

        for (i=1;i<=n;i++){
            Numbers[i].number = i;
            Numbers[i].prev = NULL;
            Numbers[i].child = NULL;

            Sets[i].sum = i;
            Sets[i].root = &Numbers[i];
            Sets[i].cardinality = 1;

            Children[i].next = NULL;
            Children[i].prev = NULL;
            Children[i].node = &Numbers[i];
        }

        for (i=0;i<m;i++){
            scanf("%lld %lld",&command,&n1);
            if (command == 1){
                scanf("%lld",&n2);
                union_nums(n1,n2);
            }else if(command == 2){
                scanf("%lld",&n2);
                move_num(n1,n2);
            }else{
                print_set(n1);
            }
        }
    }
   
    return 0;
}