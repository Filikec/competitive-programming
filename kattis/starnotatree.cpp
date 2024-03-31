#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


typedef pair<double, double> point;

point Points[100];

int main(){
    int n;
    cin >> n;

    double x=0,y=0;
    for (int i=0;i<n;i++){
        cin >> Points[i].first >> Points[i].second;
    }
    
    double pos_x;
    double best_l= 1000001;
    for (int d=0;d<=10000;d++){
        double length=0;
        for (int i=0;i<n;i++){
            length += sqrt((Points[i].first-d)*(Points[i].first-d));
            cout << length << "\n";
        }
        if (length < best_l){
            pos_x = d;
        }
    }

    double pos_y;
    best_l= 1000001;
    for (int d=0;d<=10000;d++){
        double length=0;
        for (int i=0;i<n;i++){
            length += sqrt((Points[i].second-d)*(Points[i].second-d));
        }
        if (length < best_l){
            pos_y = d;
        }
    }
    
    double result = 0;
    for (int i=0;i<n;i++){
        result += (Points[i].first-pos_x)*(Points[i].first-pos_x)+(Points[i].second-pos_y)*(Points[i].second-pos_y);
    }

    cout << fixed << setprecision(12) << result << '\n';

    return 0;
}