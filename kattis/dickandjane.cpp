#include <iostream>
#include <list>

using namespace std;


int main(){
    float s,p,y,j,Spot,Yertel,Puff,d=12;

    cin >> s;
    while (!cin.eof()){
        cin  >> p >> y >> j;

        Yertel = (d+j-s-2*p)/3;
        Puff = Yertel+p;
        Spot = Yertel+y;

        if (Yertel+Puff+Spot != d+j){
            Spot++;
        }
        if (Yertel+Puff+Spot != d+j){
            Puff++;
        }


        cout <<Spot << " " << Puff << " " << Yertel << "\n";   
        cin >> s;
    }
    

    return 0;
}