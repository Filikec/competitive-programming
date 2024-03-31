#include <bits/stdc++.h>

#define MOD 1000000000

using namespace std;


double fib(long long n){
    long double left=1,right=1;


    for (int i=0;i<n;i++){
        left *= 1.618033;
        right *= -0.618033;
    }

    return round((left-right)/(sqrt(5)));
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << '\n';
}