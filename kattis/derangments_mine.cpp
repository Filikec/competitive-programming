#include <iostream>

using namespace std;

int main(){
    int n,m;
    unsigned long long ans;
    cin >> n;
    
    m = n-1;
    ans = 1;
    for (int i=0;i<n-1;i++){
        ans *= m--;
    }
    cout << ans << "\n";

    return 0;
}