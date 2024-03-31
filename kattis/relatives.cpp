#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;


int main(){

    long long n;
    while (cin >> n){
        if (!n) break;
        unordered_set<long long> used;
        for (int i=2;i<=sqrt(n);i++){
            if (n%i==0){
                used.insert(i);
                used.insert(n/i);
            }
        }
        cout << n-1-used.size() << "<\n";
    }


    return 0;
}