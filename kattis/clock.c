#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    struct Node *next;
    int degrees;
} Node;

Node *first1, *first2;
int hands;

int check_e(int);
void insert(int, Node *, int);

int main(){
    int i,j,value;
    Node *next;

    first1 = NULL;
    first2 = NULL;

    scanf("%d",&hands);
    scanf("%d",&(hands1->degrees));
    first1 = hands1;

    for (i=1;i<hands;i++){
        scanf("%d",&value);
        insert(value,first1,1);
    }

    next = first1;

    while (next){
        printf("%d<\n",next->degrees);
        next = next->next;
    }

    return 0;
}  

void insert(int value, Node *next, int flag){
    
    if (next->degrees > value){
        if (flag){
            first1 = in;
        }else{
            first2 = in;
        }

        in->next = next;

        return;
    }

    while (next->next){
        if (next->next->degrees > in->degrees){
            in->next = next->next;
            next->next = in;
            return;
        }
        next = next->next;
    }

    next->next = in;

    printf("%d %d<\n",in->degrees,next->degrees);
}