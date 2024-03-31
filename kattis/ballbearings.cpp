#include <bits/stdc++.h>


using namespace std;

void work(){
    long double D, d, s;
    cin >> D >> d >> s;

    long double side = D/2 - d/2, x = d+s;
    
    long double angle = acos((side*side+side*side-x*x)/(2*side*side));

    cout << int ((M_PI*2)/angle) << '\n';
}


int main(){
    int cases;
    cin >> cases;
    for (int c=0;c<cases;c++){
        work();
    }
    


    return 0;
}