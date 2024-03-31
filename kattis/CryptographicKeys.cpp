#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;


bool isPrime(long long n){
    for (int i=2;i<=sqrt(n);i++){
        if (n % i) return false;
    }
    return true;
}

int main(){

    long long n;

    cin >> n;

    long long cur = 2;
    
    unordered_map<long long,long long> divisors;
    divisors[10000000000000] = 1;
    while (!isPrime(n)){
        if (n%cur==0){
            n /= cur;
            auto it = divisors.find(cur);
            if (it == divisors.end()){
                divisors[cur] = 1;
            }else{
                divisors[cur]++;
            }
        }else{
            while (n%cur) cur++;
        }
    }

    if (isPrime(n) && n>1){
        auto it = divisors.find(n);
        if (it == divisors.end()){
            divisors[n] = 1;
        }else{
            divisors[n]++;
        }
    }

    long long best = 10000000000000;
    for (auto d : divisors){
        if (d.second > divisors[best] || (d.second==divisors[best] && d.first < best)){
            best = d.first;
        }
    }

    cout << best << '\n';

    return 0;
}