#include <iostream>
#include <cmath>

using namespace std;



bool f1(long double m, long double n, long double val){
    if (m < val) return false;
    if (!n) return true;
    return f1(m,n-1,val*n);
}

bool f2(long double m, long double n, long double val){
    long double l = log2l(m);
    return l >= n;
}

bool f3(long double m, long double n, long double val){
    long double s = sqrtl(sqrtl(m));
    return s >= n;
}

bool f4(long double m, long double n, long double val){
    long double r = log(m)/3.0, s = log(n);
    return r >= s;
}

bool f5(long double m, long double n, long double val){
    long double s = sqrtl(m);
    return s >= n;
}

bool f6(long double m, long double n, long double val){
    return m >= n*log2l(n);
}

bool f7(long double m, long double n, long double val){
    return m >= n;
}

bool (*funcs[8])(long double, long double, long double) = {NULL, f1, f2, f3, f4, f5, f6 ,f7};




int main(){

    int m,n,t;

    cin >> m >> n >> t;


    if (funcs[t](m,n,1)){
        cout << "AC\n";
    }else{
        cout << "TLE\n";
    }


    return 0;
}