#include <stdio.h>

int Relations[200][200]; 
int Neighbours[200][200]; // [x][0] - number of neighbours for x

int get_set_amount(int node){
    int amount, i, j, neigh, neigh_amount, neigh_neigh, count, k, flag;
    int same[200], s = 0, sum;

    amount = Neighbours[node][0];
    count = 0;

    for (i=1;i<=amount;i++){
        neigh = Neighbours[node][i];

        if (!Relations[neigh][node]){
            continue;
        }

        count++;

        neigh_amount = Neighbours[neigh][0];
        s = 0;
        flag = 0;
        
        for (j=1;j<=neigh_amount;j++){
            neigh_neigh = Neighbours[neigh][j];

            if (Relations[neigh_neigh][node]){
                for (k=0;k<s;k++){
                    if (!Relations[same[k]][neigh_neigh]){
                        flag = 1; //does not belong
                        break;
                    }
                }
                if (!flag){
                    same[s++] = neigh_neigh;
                }
            }
        }
        printf("%d]\n",neigh);
    }

    return count;
}

int main(){
    int n, m, p1, p2, i, amount, result = 0;
   
    scanf("%d %d",&n,&m);

    for (i=0;i<m;i++){
        scanf("%d %d",&p1,&p2);
    
        amount = Neighbours[p1][0]++;
        Neighbours[p1][amount+1] = p2;

        amount = Neighbours[p2][0]++;
        Neighbours[p2][amount+1] = p1;

        Relations[p1][p2] = 1;
        Relations[p2][p1] = 1;
        
    }

    for (i=1;i<=n;i++){
        result += get_set_amount(i);
        if (result > 1000){
            printf("Too many maximal sets of friends.\n");
            return 0;
        }
    }

    printf("%d\n",result);
    
    return 0;
}