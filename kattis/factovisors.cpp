#include <iostream>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;

map<ll,ll> Divisors;


void getD(ll n){
    ll d = 2;
    while (d <= sqrt(n)){
        if (n%d==0){
            Divisors[d]++;
            n /= d; 
        }else{
            d++;
        }
    }
    if (n>1)Divisors[n]++;
}

ll getCount(ll d, ll f){
    ll count = 0;
    while (f>0){
        f /= d;
        count += f;
    }
    return count;
}

int main(){
    int n,m;
    
    while (cin >> n >> m){
        Divisors.clear();
        getD(m);
        if (!m){
            cout << m << " does not divide " << n << "!\n";
            continue;
        }
        bool good = 1;
        for (auto d : Divisors){
            if (d.second > getCount(d.first,n)){
                good = 0;
                break;
            }
        }
        if (good){
            cout << m << " divides " << n << "!\n";
        }else{
            cout << m << " does not divide " << n << "!\n";
        }
        
    }
    

    return 0;
}