#include <iostream>
#include <iomanip>

using namespace std;

int Points[1000][2];
int P;

int main(){
    float result;
    cout << fixed;
    while (true){
        cin >> P;
        result = 0;
        if (!P){
            return 0;
        }
        for (int i=0;i<P;i++){
            cin >> Points[i][0] >> Points[i][1];
        }

        for (int i=0;i<P-1;i++){
            result += Points[i][0]*Points[i+1][1];
        }
        result += Points[P-1][0]*Points[0][1];
        for (int i=0;i<P-1;i++){
            result -= Points[i][1]*Points[i+1][0];
        }
        result -= Points[P-1][1]*Points[0][0];
        if (result < 0){
            cout << "CW\n";
        }else{
            cout << "CCW\n";
        }

        cout << setprecision(1) << abs(result/2) << "\n";
    }


    return 0;
}