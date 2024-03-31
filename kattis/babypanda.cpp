#include <iostream>


using namespace std;

int main(){
    long long n,m,count=0;

    cin >> n >> m;



    while (n-- && m){
        m /= 2;
        if (m%2) count++;
    }

    cout << count << '\n';

    return 0;
}