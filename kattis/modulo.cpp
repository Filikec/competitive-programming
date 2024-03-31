#include <iostream>

using namespace std;

int count = 0;
int Modulo[42];
int main(){
    int n;
    for (int i=0;i<10;i++){
        cin >> n;
        if (!Modulo[n%42]){
            Modulo[n%42] = 1;
            count++;
        }
    }


    cout << count << "\n";

    return 0;
}