#include <iostream>
#include <cmath>

using namespace std;


int main(){

    int n;
    long long r=0;
    cin >> n;
    for (int i=0;i<n;i++){
        int num;
        cin >> num;

        r += pow(num/10,num%10);
    }

    cout <<r << '\n';


    return 0;
}