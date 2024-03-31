#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,count=0;
    while (cin >> n){
        count++;
        char c = getchar();
        if (c == '-'){
            int next;
            cin >> next;
            count += next-n;
            getchar();
        }
    }

    cout << count << '\n';

    return 0;
}