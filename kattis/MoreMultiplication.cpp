#include <bits/stdc++.h>

using namespace std;


void add(long long a, long long b, long long c, long long d){
    long long u = a*d+c*b;
    long long d2 = b*d;

    cout << u/__gcd(u,d2) << " / " << d2/__gcd(u,d2) << '\n';
}

void times(long long a, long long b, long long c, long long d){
    long long u = a*c;
    long long d2 = b*d;

    cout << u/__gcd(u,d2) << " / " << d2/__gcd(u,d2) << '\n';
}
int main(){

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        long long a,b,c,d;
        char o;
        cin >> a >> b >> o >> c >> d;


        if (o == '+'){
            add(a,b,c,d);
        }else if(o=='-'){
            add(a,b,-c,d);
        }else if (o=='*'){  
            times(a,b,c,d);
        }else{
            times(a,b,d,c);                     
        }
    }

    return 0;
}