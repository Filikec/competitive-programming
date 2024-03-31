#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int n,c=0;

    while (cin >> n){
        cout << "Case " << ++c << ": " << ceill(log10l(3.0)+n*log10l(3.0)-n*log10l(2.0)) << '\n';
    }

    

    return 0;

}