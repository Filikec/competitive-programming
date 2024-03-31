#include <bits/stdc++.h>

using namespace std;



bool cmp(int a, int b){
    return a < b;
}

int main(){

    int n, m;


    cin >> n >> m;

    int accepted  = 0;
    for (int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        n -= tmp;
        if (n<0){
            break;
        }
        accepted++;
    }

    cout << m-accepted << "\n";

    return 0;
}