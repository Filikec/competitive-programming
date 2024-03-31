#include <iostream>
#include <list>
#include <cmath>
#include <iomanip>
#include <algorithm>

#define INF 1000000.0

using namespace std;

double Houses[100000];


bool possible(double target, int n, int m){
    double last = -INF;
    for (int i=0;i<m;i++){
        auto h = Houses[i];
        if (abs(h-last) <= target) continue;
        if (!n) return false;
        last = h+target;
        n--;
    }
    return true;
}

void work(){
    int n,m;
    cin>>n>>m;

    list<double> houses;
    for (int i=0;i<m;i++){
        cin >> Houses[i];
    }
    sort(Houses,Houses+m);

    double a=0.0,b=1000000.0;

    while (abs(a-b)>0.01){
        double mid = (a+b)/2.0;
        if (possible(mid,n,m)){
            b = mid;
        }else{
            a = mid+0.001;
        }
    }

    cout << fixed << setprecision(1) << a << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        work();
    }

    return 0;
}

