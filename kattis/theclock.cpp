#include <iostream>

using namespace std;


struct Time{
    int hours, minutes;
};


int main(){
    Time time = {0,0};

    int angle;

    cin >> angle;

    int n = 0;

    while (n != angle){
        n += 55;
        n %= 3600;
        time.minutes++;
        time.hours += time.minutes / 60;
        time.minutes %= 60;
    }


    printf("%.2d:%.2d",time.hours,time.minutes);


    return 0;    
}
