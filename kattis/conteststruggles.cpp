#include <bits/stdc++.h>


using namespace std;



int main(){
    int n,k;
    double d,s,res;
    cin >> n >> k >> d >> s;
    res = (n*d-s*k)/(n-k);
    if (res > 100 || res < 0){
        cout << "impossible\n";
    }else{
        cout << fixed << setprecision(8)<< res << '\n';
    }
    




    return 0;
}