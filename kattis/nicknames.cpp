#include <bits/stdc++.h>

using namespace std;


typedef struct node{
    struct node *children[26];
    int count;
} Node;


Node Nodes[1000000], Root;
int Used;

int main(){
    int a;

    scanf("%d",&a);
    getchar();
    for (int i=0;i<a;i++){
        char c;
        Node *current = &Root;
        while ((c=getchar())!='\n'){
            if (current->children[c-'a'] == NULL){
                Node *new_node = &Nodes[Used++];
                current->children[c-'a'] = new_node;
            }
            current = current->children[c-'a'];   
            current->count++;
        }
    }

    scanf("%d",&a);
    getchar();
    for (int i=0;i<a;i++){
        char c;
        Node *current = &Root;
        while ((c=getchar())!='\n'){
            if (current){
                current = current->children[c-'a'];
            }
        }
        if (current) printf("%d\n",current->count);
        else printf("0\n");
    }


    return 0;
}