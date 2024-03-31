#include <bits/stdc++.h>

using namespace std;

int Primes[1000001];

int main(){

    long long n, k;

    cin >> n >> k;

    for (long long i=2;i<=n;i++){
        if (!Primes[i]){
            Primes[i] = 1;
            if (--k==0){
                cout << i << '\n';
                return 0;
            }
            for (long long j=i*i;j<=n;j+=i){
               
                if (!Primes[j]){
                    Primes[j] = 1;
                    k--;
                }
                if (!k){
                    cout << j << '\n';
                    return 0;
                }
            }
        }
    }   


    return 0;
}