#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

struct saunaMan{
    long double a,b,c;
    long double t;
};  


int main(){
    int n;

    cin >> n;

    list<saunaMan> men;

    long double aGain, bGain, cGain;

    aGain = bGain = cGain = 0;

    for (int i=0;i<n;i++){
        long double a,b,c;
        long double t;

        cin >> a >> b >> c >> t;
        men.push_back({a,b,c,t});

        aGain += a;
        bGain += b;
        cGain += c;
    }

    men.sort([](saunaMan a,saunaMan b){return a.t < b.t;});

    long double best = 0;

    for (auto m : men){
        
        long double x = -bGain/(2*aGain);

        if (x > m.t){
            best  = max(best,max(cGain,m.t*m.t*aGain+m.t*bGain+cGain));
        }else{
            best = max(best,max(x*x*aGain+x*bGain+cGain,max(m.t*m.t*aGain+m.t*bGain+cGain,cGain)));
        }

        aGain -= m.a;
        bGain -= m.b;
        cGain -= m.c;
    }
    cout << fixed << setprecision(10) << best << '\n';



    return 0;
}