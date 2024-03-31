#include <iostream>

using namespace std;


int main(){
    int n;
    while (cin >> n){
        if (n==1){
            cout << "1\n";
        }else{
            cout << 2*n-2 << "\n"; 
        }
    }


    return 0;
}