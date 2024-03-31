#include <stdio.h>
#include <math.h>

void fibonacci(int);
void ladder(void);
void song(void);
int happy_int(int);
int sum_sqrt(int);

int main(int argc, char **argv){
    int n, result;
    scanf("%d",&n);
    result = happy_int(n);
    if (result == 1){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}


void fibonacci(int n){
    int i, temp;
    int n1 = 0,n2 = 1;
    
    for (i=0;i<n;i++){
        printf("%d\n",n2);
        temp = n2;
        n2 += n1;
        n1 = temp;
    }
}

void song(){
    int i, j;
    char lyrics[6][150] = {"a partridge in a pear tree.\n","two turtle doves, and","three French hens,","four calling birds,","five golden rings,","six geese a-laying,"};
    for (i=0;i<6;i++){
        printf("On the %dst day of \"Xmas\", my true love sent to me\n",i+1);
        for (j=i;j>=0;j--){
            printf("%s\n",lyrics[j]);
        }
    }
}

void ladder(){
    int h,a;
    double deg;

    scanf("%d %d",&h, &a);
    deg = a * (3.1415926/180);
    printf("%f\n",deg);
    printf("%d",((int)(h/sin(deg)+1)));
}

int happy_int(int n){
    int used[150];
    int i,j;
    i=0;
    while (n != 1){
        used[i] = n;
        for (j=0;j<i;j++){
            if (n==used[j]){
                return 0;
            }
        }
        n = sum_sqrt(n);
        i++;
    }
    return n;
}

int sum_sqrt(int n){
    int sum,i;
    sum = 0;
    while (n){
        sum += (n%10)*(n%10);
        n /= 10;
    }
    
    return sum;
}