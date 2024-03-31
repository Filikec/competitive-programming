#include <iostream>

using namespace std;

int main(){
    unsigned long long n1,n2;

    cin >> n1;
    while (!cin.eof()){
        cin >> n2;
        cout << (n1>n2?n1-n2:n2-n1) << "\n";
        cin >> n1;
    }


    return 0;
}