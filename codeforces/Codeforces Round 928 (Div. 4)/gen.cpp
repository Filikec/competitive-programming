#include <bits/stdc++.h>

using namespace std;

void work(){
    int a = rand()%7;
    int b = rand()%7;
    for (int i=0;i<7;i++){
        for (int j=0;j<7;j++){
            if (i==a && j == b) cout << "W";
            else cout << "B";
        }
        cout << '\n';
    }
}

int main(){

    cout << 200 << '\n';

    for (int i=0;i<200;i++) work();

    return 0;
}