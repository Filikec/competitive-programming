#include <iostream>
#include <climits>
#include <iomanip>
#include <cmath>

using namespace std;

long double Saved[141];

long double pick(long double g, long double n){
    long double result = 1,tmp = 1;

    if (g>n || g < 2 || n < 2){
        return 0;
    }

    for (int i=0;i<g;i++){
        result *= n-i;
        tmp *= g-i;
    }
    return result/tmp;
}

long double work(long double n){
    long double result = 0;
    for (long double i=2;i<=n-2;i++){
        result += pick(i,n) * pick(n-i,n-i)/2;
    }
    result += Saved[(int)n-1]*n;
    Saved[(int)n] = result;
    return result;
}

long double all(long double n){
    long double result = 1;
    for (int i=0;i<n;i++){
        result *= (n-1);
    }
    return result;
}

int main(){
    Saved[1] = 0;
    for (int i=2;i<141;i++){
        cout <<fixed<<setprecision(10)<< i << " " << 1-work(i)/all(i) << "\n";
    }

}