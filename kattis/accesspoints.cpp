#include <iostream>
#include <iomanip>

using namespace std;


double Points[100000][2],N;



double solve(int ind){
    double most = Points[0][ind],first = 0, last = 0;
    double dist = 0,count=1,sum=Points[0][ind];
    for (int i=1;i<N;i++){
        if (Points[i][ind] < most){
            count++;
            sum += Points[i][ind];
        }else{
            double point = sum/count;
            for (int j=first;j<i;j++){
                dist += (Points[j][ind]-point)*(Points[j][ind]-point);
            }
            first = i, count = 1, sum = Points[i][ind], most = Points[i][ind];
        }
    }
    double point = sum/count;
    for (int j=first;j<N;j++){
        dist += (Points[j][ind]-point)*(Points[j][ind]-point);
    }
    
    return dist;
}

int main(){

    cin >> N;


    for (int i=0;i<N;i++){
        cin >> Points[i][0] >> Points[i][1];
    }

    double result = 0;

    result += solve(0);
    result += solve(1);
    cout << fixed << setprecision(7) << result <<'\n';
    return 0;
}