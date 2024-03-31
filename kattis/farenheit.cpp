#include <iostream>
#include <algorithm>

using namespace std;

int main(){


    long long a,b;
    cin>>a;
    cin.get();
    cin>>b;

    long long g = __gcd(a,b);
    if (g){
        a /= g;
        b /= g;
    }

    a -= 32*b;

    g = __gcd(a,b);

    if (g){
        a /= g;
        b /= g;
    }

    a *= 5;
    b *= 9;

    g = __gcd(a,b);

    if (g){
        cout << a/g << '/' << b/g << '\n';
    }else{
        cout << a << '/' << b << '\n';
    }
   

    return 0;
}