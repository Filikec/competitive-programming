#include <iostream>
#include <cmath>

using namespace std;


long long largestDiv(long long n){
    for (long long i=sqrt(n)+1;i>0;i--){
        if (n%i==0){
            return max(i,n/i); 
        }
    }
}

int main(){


    long long n;

    cin >> n;

    long long div = largestDiv(n);
    cout << n-div << "\n";


    return 0;
}