#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;

int Points[100001][2];
int Points_initial[100001][2];
int Biggest_x[100001];
int Biggest_y[100001];
int N;



double calc_sum_x(int initial, int last, int optimal){
    double sum;

    for (int i = initial; i <= last; i++){
        double temp = abs(Points[i][0]-optimal);
        sum += temp*temp;
    }

    return sum;
}

void optimal_x(int initial, int last, int least, int biggest){
    int optimal;
    double sum, initial_sum;

    if (initial == last){
        return ;
    }

    optimal = (biggest+least)/2;
    initial_sum = calc_sum_x(initial,last,optimal);
    
    for (int i=initial; i<=last; i++){
        Points[i][0] = optimal;
    }

}

double calc_sum(int initial, int last, int optimal){
    double sum = 0;

    for (int i = initial; i <= last; i++){
        double a = abs(Points[i][1]-optimal);
        double b = abs(Points[i][0]-Points_initial[i][0]);
        cout << a << " " << b << ">>>\n";
        sum += a*a + b*b;
    }
    cout << sum << "<<\n";
    return sum;
}

void optimal_y(int initial, int last, int least, int biggest){
    int optimal;
    double sum, initial_sum;

    if (initial == last){
        return ;
    }

    optimal = (biggest+least)/2;
    initial_sum = calc_sum(initial,last,optimal);
    
    while ((sum = calc_sum(initial,last,optimal+1)) < initial_sum){
        optimal++;
        initial_sum = sum;
    }

    while ((sum = calc_sum(initial,last,optimal-1)) < initial_sum){
        optimal--;
        initial_sum = sum;
    }

    cout << optimal << "<<<\n";

    for (int i=initial; i<=last; i++){
        Points[i][1] = optimal;
    }
    
}

int main(){
    int biggest = 0, b_team = -1, least = INT_MAX, l_team = -1;
    cin >> N;   

    for (int i=0;i<N;i++){
        cin >> Points[i][0] >> Points[i][1]; 
        Points_initial[i][0] = Points[i][0];
        Points_initial[i][1] = Points[i][1];
    }

    biggest = Points[0][0];
    b_team = 0;

    for (int i=1;i<N;i++){
        if (Points[i][0] >= biggest){
            optimal_x(b_team,i-1,least,biggest);
            biggest = Points[i][0];
            b_team = i;
            least = biggest;
            l_team = i;
        }else if (Points[i][0] < least){
            least = Points[i][0];
            l_team = i;
        }
    }
    optimal_x(b_team,N-1,least,biggest);

    biggest = Points[0][1];
    b_team = 0;

    for (int i=1;i<N;i++){
        if (Points[i][1] >= biggest){
            optimal_y(b_team,i-1,least,biggest);
            biggest = Points[i][1];
            b_team = i;
            least = biggest;
            l_team = i;
        }else if (Points[i][1] < least){
            least = Points[i][1];
            l_team = i;
        }
    }
    optimal_y(b_team,N-1,least,biggest);


    long double result = 0;

    for (int i=0;i<N;i++){
        int x,y;
        double dist;
        
        x = Points[i][0] - Points_initial[i][0];
        y = Points[i][1] - Points_initial[i][1];

        result += x*x+y*y;
    }
    cout << result << "\n";
    return 0;
}