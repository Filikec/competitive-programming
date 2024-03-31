#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double n = 0;

    while (cin >> n){
        int i = 0;
        while (n){
            n /= 9;
            if (n <= 1){
                cout << "Stan wins.\n";
                break;
            }
            n /= 2;
            if (n <= 1){
                cout << "Ollie wins.\n";
                break;
            }
        }
    }



    return 0;
}