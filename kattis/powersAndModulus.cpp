#include <iostream>


using namespace std;


int main(){

    
    long long a,b;

    cin >> a >> b;

    if (a%2) {
        cout << "0\n"; 
    }else {
        long long n = (a/2);
        
        for (int i=0;i<b-1;i++){
            n *= n;
            n %= a;
        }
        cout << n << "\n";
    }

    return 0;
}