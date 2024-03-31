#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>


using namespace std;

long long S[40];
pair<long double, long double> D[40];

long long pow(long long p){
    long long r = 1;
    while (p--){
        r *= 2;
    }

    return r;
}

long double get(int s, long long needed){
    if (needed == 1) return 0;
    return D[s].first*needed/2+get(s-1,needed/2);
}

int main(){
    int n;
    cin >> n;

    for (int i=2;i<n+1;i++){
        cin >> S[i];
    }

    D[2] = {0.5946035575013605,0.42044820762685725};

    for (int i=3;i<=30;i++){
        long double b = D[i-1].first/2.0;
        long double a = D[2].first*b/D[2].second;

        D[i] = {a,b};
    }


    long double best = 1e300;



    while (true){
        
    }

    if (best == 1e300){
        cout << "impossible\n";
    }else{
        cout << fixed << setprecision(10) << best << '\n';
    }
    


    return 0;
}
