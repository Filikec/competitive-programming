#include <iostream>
#include <cmath>

using namespace std;

double fib(unsigned long long n){
    return (double) round((powf(1.618033,n)-pow(-0.618033,n))/sqrt(5));
}


int main(){
    unsigned long long n;

    cin >> n;

    cout << fib(n) << "\n";

    return 0;
}