#include <stdio.h>
#include <stdlib.h>

typedef struct start{
    struct node *head;
} Start;

typedef struct node{
    struct node *next;
    int id;
} Node;

Start Friendships[10000];
long long int Friends[10000];

int calculate_money(int friend_id){
    long long int owing = 0;
    Node *friend, *friend_next;

    owing += Friends[friend_id];
    Friends[friend_id] = 0;
    
    friend = Friendships[friend_id].head;
    Friendships[friend_id].head = NULL;

    while (friend){
        owing += calculate_money(friend->id);
        friend_next = friend->next;
        free(friend);
        friend = friend_next;
    }
    
    return owing;
}

int main(){
    int n,m,i, friend1, friend2;
    long long int money;
    Node *node1, *node2;

    scanf("%d %d",&n,&m);

    for (i=0;i<n;i++){
        scanf("%lld",&money);

        Friends[i] = money; 
    }

    for (i=0;i<m;i++){
        scanf("%d %d",&friend1,&friend2);

        node1 = (Node *) malloc(sizeof(Node));
        node2 = (Node *) malloc(sizeof(Node));

        node1->id = friend1;
        node2->id = friend2;

        node2->next = Friendships[friend1].head;
        Friendships[friend1].head = node2;

        node1->next = Friendships[friend2].head;
        Friendships[friend2].head = node1;
    }
    
    for (i=0;i<n;i++){
        if (!Friends[i]){
            continue;
        }
        if (calculate_money(i)){
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    printf("POSSIBLE\n");
            
    return 0;
}