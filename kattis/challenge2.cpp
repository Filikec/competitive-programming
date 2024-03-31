#include <iostream>
#include <algorithm>

using namespace std;


bool work(long long a, long long b){
    if (a < b){
        swap(a,b);
    }

    if (a % b == 0) return true;

    long long d = a/b;

    return !work(a-d*b,b)||(d-1!=0&&!work(a-(d-1)*b,b));
}

int main(){


    long long a,b;

    cin >> a >> b;

    if (work(a,b)){
        cout << "win\n";
    }else{
        cout << "lose\n";
    }



    return 0;   
}