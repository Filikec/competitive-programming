#include <bits/stdc++.h>

using namespace std;

int Prepare[101];

void preprocess(){
    Prepare[99] = 0;

    for (int i=98;i>0;i--){
        if (!Prepare[i+1] || !Prepare[i+2]) Prepare[i] = 1;
        else Prepare[i] = 0;
    }
}


int main(){
    int n;
    preprocess();
    cout << "1\n";

    while (cin >> n){
        if (n == 99) break;

        if (!Prepare[n+1]) cout << n+1 << "\n";
        else cout << n+2 << "\n";
    }

    return 0;
}