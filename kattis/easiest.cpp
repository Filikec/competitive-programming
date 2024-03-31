#include <bits/stdc++.h>

using namespace std;


long long get_sum(long long n){
    long long result = 0;

    while (n){
        result += n%10;
        n /= 10;
    }

    return result;

}


int main(){

    int n;
    while (cin >> n){
        if (!n) break;
        long long sum = get_sum(n);
        for (long long i=11;i<10000000;i++){
            if (sum == get_sum(n*i)){
                cout << i << '\n';
                break;
            }
        }
    }


    return 0;
}