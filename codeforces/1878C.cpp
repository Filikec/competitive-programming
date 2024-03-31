#include <bits/stdc++.h>

using namespace std;

long long getSum(long long a,long long b){
    return (b-a)*(b-a+1)/2+(b-a+1)*a;
}

void work(){
    long long n,k,x;
    cin >> n >> k >> x;

    long long last = getSum(n-k+1,n);
    long long first = getSum(1,k);

    if (first <= x && last >= x) cout << "YES\n";
    else cout << "NO\n";
}

int main(){

    int t;
    cin >> t;
    while (t--) work();


    return 0;
}