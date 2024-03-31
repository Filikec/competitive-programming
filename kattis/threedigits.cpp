#include <iostream>
#include <cmath>

using namespace std;

unsigned long long Last[10000001];

int main(){
    Last[0] = 1;
    for (long long i=1;i<100;i++){
        long long tmp = ((long long)Last[i-1])*i;
        while (tmp%10==0) tmp /= 10;
        for (int k=0;k<10&&tmp;k++){
            Last[i] += (tmp%10)*pow(10,k);  
            tmp /= 10;
        }
    }

    int n;

    cin >> n;
    int result = 0;
    long long last = Last[n];
    for (int i=0;i<3;i++){
        result += last%10*pow(10,i);
        last /= 10;
    }

    if (n > 7 && log10(result) < 2) cout << 0;
    cout << result << "\n";
    
    
    return 0;
}