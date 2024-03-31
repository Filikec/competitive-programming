#include <stdio.h>
#include <stdlib.h>

int get_worth(int,int);
int get_sum(float,float);
int get_count(int,int,int);

int main(int argc, char **argv){
    int k, m,i,start,end,count;
    
    scanf("%d %d",&k,&m);


    printf("%d %d %d\n",get_count(1,m,k),get_sum(1,20),get_worth(1,30));

    end = 30;
    start = 1;
    for (i=0;i<4;i++){
        end = get_worth(start,end);
        printf("%d<\n",end);
        count += end;
        end--;
    }

    count += get_sum(start,end);
    printf("%d\n",count);

    for (i=1;i<=100;i++){
        printf("%d ",i);
    }
    printf("\n");


    return 0;
}

int get_count(int a1, int an, int k){
    int n1,n2,index;

    if (k == 1){
        return get_sum(a1,an);
    }

    if (a1 == an){
        return a1;
    }


    index = get_worth(a1,an);
    
    n1 = get_count(index+1,an,k) + index;
    n2 = get_count(a1,index-1,k-1) + index;

   

    return n1>n2?n1:n2;

}



int get_worth(int a1, int an){
    int i, diff_last,diff;

    diff = 5051;
    diff_last = diff;
    
    for (i=0;i<=an;i++){
        if (a1+1+i > an){
            return an-1;
        }
        
        diff = abs(get_sum(a1,a1+i)-get_sum(a1+2+i,an));

        if (diff > diff_last){
            return a1+i;
        }

        diff_last = diff;
        
    }
    return 0;
}

int get_sum(float a1, float an){
    float n = an-a1+1;
    return (int)((2*a1+n-1)*((n)/2));
}