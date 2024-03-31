#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    unsigned long long p=0;
    unsigned long long add=0;
    unsigned long long pall=1;
    cout << 0 << '\n';
    for (int i=2;i<=n;i++){
        p += 4*max(i-2,0), p += 4*max(i-3,0);
        if (i > 2) p += 2, add+=2;
        unsigned long long added = 2*i-1;
        pall += added*(added-1)/2 + added*(i-1)*(i-1);
        cout << pall-p-add-1 << '\n';
    }

    return 0;
}