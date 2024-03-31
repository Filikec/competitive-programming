#include <bits/stdc++.h>

using namespace std;


int Values[25];

int main(){
    int n;
    cin >> n;


    Values[0] = 0;
    Values[1] = 1;
    Values[2] = 2;
    Values[3] = 4;


    for (int i=4;i<25;i++){
        Values[i] = Values[i-1]+Values[i-2]+Values[i-3];

    }

    cout << Values[n] << "\n";
}