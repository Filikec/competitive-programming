#include <bits/stdc++.h>


using namespace std;



int main(){


    int n;
    cin >> n;

    int used = 0,cur=1,levels=0;
    while (used<n){
        used += cur*cur;
        cur+=2;
        levels++;
    }
    if (used > n){
        levels--;
    }

    cout << levels << "\n";

    return 0;
}