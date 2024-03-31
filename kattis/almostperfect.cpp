#include <iostream>
#include <cmath>

using namespace std;


int main(){
    long long n, sum;
    
    while (cin >> n){
        sum = 1;
        for (int i=2;i<=sqrt(n);i++){
            if (n%i==0){
                sum += i;
                if (i != n/i){
                    sum += n/i;
                }
            }
        }
        cout << sum << "\n";
        long long diff = abs(sum-n);
        if (!diff){
            cout << n << " perfect\n";
        }else if (diff <= 2){
            cout << n << " almost perfect\n";
        }else{
            cout << n << " not perfect\n";
        }
    }

    return 0;
}