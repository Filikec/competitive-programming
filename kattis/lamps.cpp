#include <iostream>

using namespace std;



int main(){
    double i=5, l=60,h,p,k=0,d=0;
    int t = 0;

    cin >> h >> p;

    while (l>=i){
        t += h;
        d++;
        if (t > 1000) t %= 1000, i += 5;

        i += h*p*60/100000;
        l += h*p*11/100000;
    }

    cout << d << '\n';

    return 0;
}