#include <bits/stdc++.h>

using namespace std;


int main(){

    long long n,p;

    cin >> n >> p;

    long long sum = 0;
    long long biggest = 0;
    for (long long i=0;i<n;i++){
        long long tmp;
        cin >> tmp;
         
        if (sum + tmp-p > 0){
            sum += tmp-p;
        }else{
            sum = 0;
        }
        biggest = max(biggest,sum);
    }

    cout << biggest << '\n';

    return 0;
}