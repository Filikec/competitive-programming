#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    long double w,h,x,y,s,r;
    while (cin >> w >> h >> x >> y >> s >> r && (w || h || x || y || s || r)){
        r *= 3.1415926536/180, s /= 100.0;        
        long double X = (x*(1-s*cos(r))-s*sin(r)*y)/(pow((1-s*cos(r)),2)+s*s*sin(r)*sin(r));
        cout << fixed << setprecision(2) << X << ' ' <<  (s*sin(r)*X+y)/(1-s*cos(r)) << '\n';
    }
}