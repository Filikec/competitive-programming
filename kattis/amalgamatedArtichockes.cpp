#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

ld P,A,B,C,D;

int N;

ld getPrice(ld n){
    return P*(sin(A*n+B)+cos(C*n+D)+2);
}

int main(){
    
    
    cin >> P >> A >> B >> C >> D >> N;
    
    ld biggest;
    ld best = 0;
    
    for (int i=0;i<N;i++){
        ld price = getPrice(i+1);
        
        if (!i) biggest = price;
        
        best = max(best,biggest-price);
        
        biggest = max(biggest,price);
    }

    cout << fixed << setprecision(18) << best << '\n';
    
    return 0;
}