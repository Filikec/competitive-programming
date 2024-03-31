#include <bits/stdc++.h>

using namespace std;



long long getDigs(long long n){
    long long o=n;
    long long pow=0;
    while (n) pow++,n/=10;

    long long prev=1;
    long long sum=0;
    for (int i=1;i<pow;i++){
        sum += i*(prev*10-prev);
        prev*=10;
    }
    sum += (o-prev+1)*pow;
    return sum;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--){
        long long n;
        cin >> n;
        long long l,r;
        l = 0, r = 1e17;

        while (l<r){
            long long mid = (l+r)/2;
            if (getDigs(mid) > n) r = mid;
            else if (getDigs(mid) < n) l = mid+1;
            else l = r = mid;
        }
        long long c = getDigs(l);
        cout << to_string(l)[to_string(l).size()-c+n-1] << '\n';
    }
    

    
}