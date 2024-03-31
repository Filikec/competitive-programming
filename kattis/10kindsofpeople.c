#include <stdio.h>

typedef struct node{
    struct node *parent;
    char value;
} Node;

Node Positions[1000][1000];

Node *get_root(Node *node){
    
    while (node->parent){
        node = node->parent;
    }
    return node;
}

int Set;

int main(){
    int n, m, i, j, lines, x1, y1, x2, y2;
    char string[1000];

    scanf("%d %d",&n,&m);

    for (i=0;i<n;i++){
        scanf("%s",string);
        for (j=0;j<m;j++){
            Positions[i][j].value = string[j];
            Positions[i][j].parent = NULL;
            if (i && Positions[i-1][j].value == Positions[i][j].value){
                Positions[i][j].parent = get_root(&Positions[i-1][j]);

            }
            if (j && Positions[i][j-1].value == Positions[i][j].value){
                if (get_root(&Positions[i][j-1]) != get_root(&Positions[i][j]))
                get_root(&Positions[i][j])->parent = get_root(&Positions[i][j-1]);

            }

            
        }
    }

    scanf("%d",&lines);

    for (i=0;i<lines;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if (get_root(&Positions[x1-1][y1-1]) == get_root(&Positions[x2-1][y2-1])){
            if (Positions[x1-1][y1-1].value == 48){
                printf("binary\n");
            }else{
                printf("decimal\n");
            }
        }else{
            printf("neither\n");
        }
    }


    return 0;
}