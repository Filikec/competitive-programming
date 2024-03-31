#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    int n;
    double price=0,cost;
    cin >> cost >> n;

    for (int i=0;i<n;i++){
        double x,y;

        cin >> x >> y;

        price += x*y*cost;
    }

    cout << fixed << setprecision(7) <<  price << '\n';


    return 0;
}