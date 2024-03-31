#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Store{
    long long t,h;
};

Store Stores[200000];
long long Dynamic[200001];

#define MAX 10000000


int main(){
    long long n;

    cin >> n;

    for (long long i=0;i<n;i++){
        long long t,h;
        cin >> t >> h;
        Stores[i] = {t,h};
    }

    sort(Stores,Stores+n,[&](Store a, Store b){return a.h<b.h;});

    for (long long i=1;i<=n;i++) Dynamic[i] = MAX;
    
    int L = 0;
    for (long long i=0;i<n;i++){
        long long t,h;
        t = Stores[i].t, h = Stores[i].h;
        long long lo=0,hi=n;


        long long maxTime = h-t;
        
        while (lo<hi){
            long long mid = ceil((lo+hi)/2.0);
            if (Dynamic[mid] <= maxTime){
                lo = mid;
            }else if (Dynamic[mid] > maxTime){
                hi = mid-1;
            }
        }
        lo++;
        while (lo && Dynamic[lo-1]+t < Dynamic[lo]){
            Dynamic[lo] = Dynamic[lo-1]+t;
            lo--; 
        }
        
    }   

    long long most = 0;
    for (long long i=0;i<=n;i++){
        if (Dynamic[i]!=MAX) most = i;
    }

    cout << most << "\n";

    return 0;
}