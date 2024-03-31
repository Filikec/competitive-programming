#include <iostream>
#include <cmath>

using namespace std;


int main(){


    int c,e,m;

    cin >> c >> e >> m;



    if (c != 4){
        cout << "impossible\n";
        return 0;
    }

    for (int i=2;i<=sqrt(c+e+m);i++){
        if ((c+e+m)%i==0){
            int a = i;
            int b = (c+e+m)/i; 
            if (m == (a-2)*(b-2)){
                cout << max(a,b) << ' ' << min(b,a) << '\n';
                return 0;
            }

        }
    }

    cout << "impossible\n";



    return 0;
}