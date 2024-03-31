#include <iostream>
#include <iomanip>

using namespace std;


long long Dynamic[150],Fac[150];

void get_count(){
    Dynamic[0] = 0;
    Dynamic[1] = 0;
    Dynamic[2] = 1;
    Fac[0] = 1;
    for (int i=3;i<15;i++){
        Dynamic[i] = (i-1)*(Dynamic[i-1]+Dynamic[i-2]);
    }
    for (int i=1;i<15;i++){
        Fac[i] = Fac[i-1]*i;
    }
}

int main(){

    int n;

    cin >> n;

    get_count();    

    if (n <= 10){
        cout << fixed << setprecision(8) << 1-((double) Dynamic[n])/((double)Fac[n]) << "\n";
    }else{
        cout << "0.63212056\n";
    }


    return 0;
}