#include <iostream>
#include <list>

using namespace std;

list<int>;

int main(){

    long long n,b=0;

    cin >> n;

    while (n){
        int dig = n%2;
        n /= 2;
        b = b*2+ dig;
    }
    n=0;
    while (b){
        int dig = b%10;
        b /= 10;
        n = n*10+dig;
    }

    cout << n << "\n";


    return 0;
}