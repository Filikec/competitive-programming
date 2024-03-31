#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int h,v;
    
    cin >> h >> v;
    
    double r = h/sin(M_PI/180*v);
    int r_i = (int) r;

    cout << (r-r_i==0?r_i:r_i+1) << "\n";

    return 0;
}