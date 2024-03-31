#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    long double a,b,c, tmp;

    cin >> a >> b >> c;

    if (a>b){
        tmp = a/c;
        cout << fixed << setprecision(7) << tmp*b << "\n";
    }else{
        tmp = b/c;
        cout << fixed << setprecision(7) << tmp*a << "\n";
    }



    return 0;
}