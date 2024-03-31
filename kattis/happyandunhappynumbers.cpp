#include <bits/stdc++.h>


using namespace std;


int Happy[1000001]; //0 - idk, -1 no, 1 yes, 2 searching
int Sums[1000001];

int get_int(){
    char c;
    int result = 0;

    while ((c = getchar()) >= '0'){
        result *= 10;
        result += c-'0';
    }

    return result;
}

int is_happy(int n){
    if (n < 0 || n > 1000000) return -1;
    if (Happy[n] == 2){
        return -1;
    }
    
    if (Happy[n] == -1) return -1;
    if (Happy[n] == 1){
        return 1;
    }
    Happy[n] = 2;
    int sum = 0;
    int old = n;
    while (n){
        int digit = n%10;
        sum += digit*digit;
        n /= 10;
    }
    Happy[old] = is_happy(sum);

    return Happy[old];
}

void preprocess(){
    Happy[1] = 1;
    for (int i=0;i<1000001;i++){
        if (is_happy(i) == 1){
            Sums[i] = 1;
        }
    }
    for (int i=1;i<1000001;i++){
        Sums[i] += Sums[i-1];
    }
}


int main(){
    preprocess();

    int n;

    n = get_int();

    for (int i=0;i<n;i++){
        int a,b;
        a = get_int();
        b = get_int();
        printf("%d\n",Sums[b]-Sums[a-1]);
    }


    return 0;
}
