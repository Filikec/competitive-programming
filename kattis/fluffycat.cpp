#include <iostream>
#include <list>
#include <cmath>

using namespace std;


list<pair<int,int>> Possible;

int X,Y;

void get_possible(int d){
    for (int i=1;i<=sqrt(d);i++){
        double tmp = sqrt(d-i*i);
        if (tmp == (int)tmp){
            Possible.push_back(make_pair(i+X,d+Y));
            Possible.push_back(make_pair(i-X,d-Y));
        }
    }
}

int main(){
    int dist;

    cout << 0;

    cin >> dist;


    return 0;  
}