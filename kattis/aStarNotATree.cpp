#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

pair<double,double> Points[100];
double Sx, Sx2, Sy, Sy2;

int main(){
    double n;
    cin >> n;
    Sx=Sx2=Sy=Sy2=0;
    for (int i=0;i<n;i++){
        double x,y;
        cin >> x >> y;
        Points[i] = {x,y};
        Sx += x;
        Sx2 += x*x;
        Sy += y;
        Sy2 += y*y;
    }

    double best = -1;
    double bx,by;
    for (double y=0;y<=10000.0;y++){
        for (double x=0;x<=10000;x++){
            double sum = n*x*x-2*x*Sx+Sx2+n*y*y-2*y*Sy+Sy2;
            if (best == -1  || best > sum){
                best = sum;
                bx = x;
                by = y;
            }
        }
    }

    double sum = 0;
    for (int i=0;i<n;i++){
            sum += sqrt((x-Points[i].first)*(x-Points[i].first)+(y-Points[i].second)*(y-Points[i].second));
        }

    cout << fixed << setprecision(7) <<  best*2 << '\n';

    return 0;
}