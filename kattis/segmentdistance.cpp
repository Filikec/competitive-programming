#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;



void solve(){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    double dist,a1,a2,b1,b2;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;



    dist = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    dist = min(dist,sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4)));
    dist = min(dist,sqrt((x2-x4)*(x2-x4)+(y2-y4)*(y2-y4)));
    dist = min(dist,sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)));

    a1 = x2-x1, a2 = y2-y1;
    b1 = x4-x3, b2 = y4-y3;

    if ((b1 && a1*b2/b1 == a2) || (b2 && a2*b1/b2 == a1) || (a1 && b1*a2/a1 == b2) || (a2 && b2*a1/a2 == b1)){
        if (b1 == a1 || b2 == a2) {
            cout << "0.00\n";
            return;
        }
        if (x1)
    }

    cout << fixed << setprecision(2) << dist << '\n'; 
}

int main(){

    
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        solve();
    }
    

    return 0;
}