#include <bits/stdc++.h>

using namespace std;


bool is_prime(int n){
    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0) return false;
    }
    return true;
}


int main(){
    int n;

    while (cin>>n){
        if (!n) break;

        int i = 2*n+1;
        while (!is_prime(i++));

        cout << i;
        if (!is_prime(n)) cout << " (" << n << " is not prime)";
        cout << '\n';
    }


    return 0;
}