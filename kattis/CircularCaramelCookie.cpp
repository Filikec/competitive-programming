#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool possible(double t,double s){    
    t *= t;
    double y=1;
    double count=0;
    while (true){
        if (y*y > t) break;
        double x = floor(sqrt(t-y*y));
        if (x<1) break;
        count += x;
        y++;
    }
    return count*4>s;
}

int main(){
    double s;
    cin >> s;
    
    double a=0,b=max(sqrt(s),10.0);

    while (abs(a-b) > 0.00000000001){
        double mid = (a+b)/2.0;
        if (possible(mid,s)){
            b = mid;
        }else{
            a = mid;
        }
    }

    cout << fixed << setprecision(10) <<  a << '\n';
    return 0;
}

