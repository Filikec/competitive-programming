#include <iostream>
#include <cmath>

using namespace std;



int main(){
    double n, a;

    cin >> a >> n;


    if ((n*n)/(M_PI*4) >= a){
        cout << "Diablo is happy!\n";
    }else{
        cout << "Need more materials!\n";
    }
    

    return 0;
}