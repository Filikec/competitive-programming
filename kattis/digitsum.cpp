#include <iostream>
#include <cmath>
#include <set>
#include <list>

using namespace std;
    
int Sums[10];

void get_pre(){
    for (int i=1;i<10;i++){
        Sums[i] = Sums[i-1]+i;
    }
}

long long get_sum(long long num){
    long long n, left, right, curr, power = 0, sum =0;
    
    n = num;
    
    if (n <= 0) return 0;
    
    left = n;
    while (left>0){
        curr = left%10;
        left /= 10;
        right = n%((long long)pow(10,power));

        sum += (45*left+Sums[curr-1])*(pow(10,power));
        sum += curr*(right+1);
        
        power++;
    }
    return sum;
}

void solve(){
    long long a,b;
    
    cin >> a >> b;
    
    cout << get_sum(b)-get_sum(a-1) << "\n";
}

int main(){
    int cases;
    get_pre();
    cin >> cases;
    
    for (int c=0;c<cases;c++){
        solve();
    }
}

