#include <iostream>

using namespace std;



unsigned long long Fib[100000];


int main(){

    Fib[0] = 1;
    Fib[1] = 1;

    for (int i=2;i<88;i++){
        Fib[i] = Fib[i-1]+Fib[i-2];
    }

    for (int i=88;i<=100000;i++){
        Fib[i] = 10000000000000000000;
    }

    int n,k;

    cin >> n >> k;
    n--;
    while (n >= 2){
        if (k > Fib[n-2]){
            n -= 2;
        }else{
            n--;
            k -= Fib[]
        }
    }


    return 0;
}