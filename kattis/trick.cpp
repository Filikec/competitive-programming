#include <iostream>
#include <cmath>

using namespace std;



int get_reverse(int n){
    int mod = pow(10,(long long)log10(n));
    int result = n%mod;
    result = result*10+n/mod;
    return result;
}

int main(){
    double x;
    bool f = false;
    cin >> x;

    if (x>=10){
        cout << "No solution\n";
        return 0;
    }

    for (double e=0;e<8;e++){
        for (double d=1;d<10;d++){
            double a = (pow(10,e+1)-1)/(10-x);
            a *= d;
            if (a !=  floor(a)) continue;
            cout << a << "\n";
            double tmp = a*x;
            if (a > 100000000) continue;
            if (get_reverse(floor(a)) == floor(tmp)){
                cout <<(int) a << endl;
                if (!f) f = true;
            }
        }
    }

    if (!f) cout << "No solution\n";

    return 0;
}