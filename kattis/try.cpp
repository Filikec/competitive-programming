#include <cmath>
#include <iostream>

using namespace std;


int main(){

    long double x,y;
    cin >> x >> y;
    auto a = atan2(y,x)*(180.0 / 3.1415926535);
    if (a < 0){
        cout << 360+a << '\n';
    }else{
        cout << a << '\n';
    }

    return 0;
}