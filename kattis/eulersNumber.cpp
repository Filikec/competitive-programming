#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    
    int n;
    
    cin >> n;
    
    
    if (n >= 15){
        cout << "2.718281828458995\n";
    }else{
        long double fac = 1;
        long double e = 0;
        for (int i=0;i<=n;i++){
            e += 1.0/fac;
            fac *= i+1;
        }
        cout << fixed << setprecision(12) << e << "\n";
        
    }
    
    
    return 0;
}