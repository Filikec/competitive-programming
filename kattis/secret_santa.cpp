#include <iostream>

using namespace std;

int fact(int n){
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}


int main(){
    double n, i;

    cin >> n;

    cout << 1 - 1/n;

    return 0;
}