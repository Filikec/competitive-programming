#include <bits/stdc++.h>

using namespace std;

void work(){
    int n;
    cin >> n;
    int lo=1,hi=n;
    bool b=1;
    for (int i=0;i<n;i++) b?cout<<lo++:cout<<hi--,cout <<' ',b=!b;
    cout << '\n';
}

int main(){

    int t;
    cin >> t;
    while (t--) work();

    return 0;
}