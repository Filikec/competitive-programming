#include <bits/stdc++.h>

using namespace std;


int Stops[31];


int main(){ 
  
    Stops[1] = 1;
    for (int i=2;i<=30;i++){
        Stops[i] = Stops[i-1]*2+1; 
    }

    int c;

    cin >> c;

    for (int i=0;i<c;i++){
        int k;
        cin >> k;
        cout << Stops[k] << '\n';
    }


    return 0;
}