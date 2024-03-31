#include <iostream>


using namespace std;


int main(){

    int n;
    cin >> n;


    int best = 99;

    for (int i=99;i<=100000;i+=100){
        if (abs(i-n) <= abs(n-best) && best < i){
            best = i;
        }
    }

    cout << best << '\n';


    return 0;
}