#include <iostream>


using namespace std;


typedef struct{
    int x,y;
} Point;

Point Points[100000];
long long X[100000], Y[100000];

int get_int(){
    int result = 0;
    char c;

    while ((c=getchar()) >= '0') result=result*10+c-'0';

    return result;
}

int main(){
    int n;

    n = get_int();

    for (int i=0;i<n;i++){
        int x,y;
        x = get_int();
        y = get_int();
        X[x]++,Y[y]++;
        Points[i] = {x,y};
    }
    long long sum = 0;
    for (int i=0;i<n;i++){
        auto curr = Points[i];
        sum += (X[curr.x]-1)*(Y[curr.y]-1);
    }

    printf("%lld\n",sum);


    return 0;
}