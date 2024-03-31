#include <stdio.h>

int Length, Amount;
char nodes[100000][100];
int vertex[10000];
int in[10000];
int pairs[20000];
int edges[1000][999];
int p;

int get_diff(char *, char *);

int main(int argc, char **argv){
    int  i, j, k, total_diff, diff,size,connection,node;
    int least[2];

    total_diff = 0;

    scanf("%d %d",&Amount,&Length);
    
    
    for (i=0;i<Amount;i++){
        getchar();
        for (j=0;j<Length;j++){
            nodes[i][j] = getchar();
        }
    }

    for (i=0;i<Amount-1;i++){
        for (j=i+1;j<Amount;j++){
            edges[i][j] = get_diff(nodes[i],nodes[j]);
        }
    }


    vertex[0] = 0;
    in[0] = 1;
    size = 1;

    for (i=0;i<Amount-1;i++){
        least[0] = Length+1;
        for (j=0;j<size;j++){
            node = vertex[j];
            for (k=0;k<Amount;k++){
                if (in[k]){
                    continue;
                }

                diff = node<k?edges[node][k]:edges[k][node];

                if (diff < least[0]){
                    least[0] = diff;
                    least[1] = k;
                    connection = node;
                }
            }
        }

        pairs[p++] = connection;
        pairs[p++] = least[1];

        total_diff += least[0];
        vertex[size++] = least[1];
        in[least[1]] = 1;
    }

    printf("%d\n",total_diff);

    for (i=0;i<p;i+=2){
        printf("%d %d\n",pairs[i],pairs[i+1]);
    }


    return 0;  
}

int get_diff(char *a, char*b){
    int i, count;
    
    count = 0;
    
    for (i=0;i<Length;i++){
        if (a[i]!=b[i]){
            count++;
        }
    }
    return count;
}

