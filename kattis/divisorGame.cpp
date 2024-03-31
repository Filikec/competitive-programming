#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(long long a){
    for (int d=2;d<sqrt(q);d++){
        if (!(a%d)) return false;
    }
    return true;
}


void work(){
    long long a,b;

    cin >> a >> b;

    long long win,lose;
    win = lose = 1;
    for (long long i=a+1;i<=b;i++){
        long long newWin,newLose;
        if (isPrime(i)){
            newWin = win
        }
    }
    win--;
    lose--;
}


int main(){

    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        work();
    }

    return 0;
}

