#include <iostream>
#include <cmath>

using namespace std;

void solve(long long n){

    bool f= false;
    for (long long b=1;b<=100001;b++){
        if (b*b-(b-1)*(b-1) > n){
            break;
        }
        double a;
        a = sqrt(b*b-n);

        if (a == (long long) a){
            cout << a << " " << b << "\n";
            f = true;
            break; 
        }

    }

    if (!f) cout<<"impossible\n";
}

int main(){
    long long n;

    cin >> n;
    solve(n);


    return 0;
}