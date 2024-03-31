#include <iostream>
#include <cmath>

using namespace std;



int main(){

    int c, e, m;
    
    cin >> c >> e >> m;

    if (c!=4 || e%2){
        cout << "impossible\n";
        return 0;
    }

    

   for (int i=1;i<=sqrt(m);i++){
       int a,b;
       if (i){
           a = i, b = m/a;
           if (m%i) continue;
       }else{
           a = 0, b = 0;
       }
       if (2*(a+b)+4 == e+c){
           cout << a+2 << ' ' << b+2 << '\n';
           return 0;
       }

   }

    cout << "impossible\n";
    return 0;
}