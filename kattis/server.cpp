#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,t;
    cin >> n >> t;

    int sum = 0,used=0;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
        if (sum > t) break;
        used++;
    }

    cout << used << "\n";



    return 0;
}