#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <list>

using namespace std;



long long GCD(long long a, long long b){

    if (a < b){
        long long tmp = a;
        a = b;
        b = tmp;
    }

    long long m=1;
    while (m){
        m = a%b;
        a = b;
        b = m;
    }

    return a;

}

long long pow_(long long n, long long p){
    long long result = 1;

    while (p--){
        result *= n;
    }
    return result;
}

int main(){

    string sn;
    int d;

    cin >> sn >> d;

    int realsCount = 0;
    int decI = 0;

    for (int i=0;i<sn.size();i++){
        if (sn[i] == '.'){
            realsCount = sn.size()-(i+1);
            decI = i;
        }
    }

    list<int> repeating;
    for (int i=0;i<d;i++){
        repeating.push_front(sn[sn.size()-1-i] -'0');
    }

    long long x1 = 0, y1 = 1;
    for (auto d : repeating){
        x1 *= 10;
        x1 +=d;
        y1 *= 10;
    }
    y1--;

    y1 *= pow_(10,sn.size()-decI-1-d);

    long long x2=0,y2=1;
    for (int i=0;i<decI;i++){
        x2 *= 10;
        x2 += sn[i]-'0';
    }

    for (int i=0;i<realsCount-d;i++){
        x2*=10;
        x2 += sn[i+decI+1]-'0';
        y2 *= 10;
    }
    long long gcdY = GCD(y1,y2);
    long long y = (y1/gcdY)*(y2);
    long long x = x1*(y/y1)+x2*(y/y2);

    long long gcd = GCD(x,y);
    cout << x/gcd << '/' << y/gcd << "\n";

    return 0;
}