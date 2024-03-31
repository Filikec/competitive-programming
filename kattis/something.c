#include <stdio.h>

typedef struct list{
    struct node *head;
} List;

typedef struct node{
    long long int id;
    struct node *next;
} Node;

List Relations[200001];
long long int Amount[200001][2]; //[0] original amount, [1] how many partners left
long long int Removed[200001];
long long int MyCountry;

int remove_country(long long int n){
    long long int neighbour;
    int left;
    Node *next;

    Removed[n] = 1;
    
    if (n == MyCountry){
        printf("leave\n");
        return 1;
    }

    next = Relations[n].head;

    while (next){

        neighbour = next->id;

        if (Removed[neighbour]){
            next = next->next;
            continue;
        }

        Amount[neighbour][1]++;

        if (Amount[neighbour][1]*2 >= Amount[neighbour][0]){
            if (remove_country(neighbour)){
                return 1;
            }
        }
        next = next->next;
    }

    return 0;
}

int main(){
    long long int c,p,l,c1,c2; //x home, l leave
    Node *next;

    scanf("%lld %lld %lld %lld\n",&c,&p,&MyCountry,&l);

    for (long long int i=0;i<c;i++){
        Relations[i].head = NULL;
    }

    for (long long int i=0;i<p;i++){
        scanf("%lld %lld",&c1,&c2);
        next = (Node *) malloc(sizeof(Node));
        next->id = c2;
        next->next = Relations[c1].head;
        Relations[c1].head = next;
        Amount[c1][0]++;

        next = (Node *) malloc(sizeof(Node));
        next->id = c1;
        next->next = Relations[c2].head;
        Relations[c2].head = next;
        Amount[c2][0]++;
    }
    
    if (!remove_country(l)){
        printf("stay\n");
    }
    


    return 0;
}