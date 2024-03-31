#include <iostream>
#include <cmath>
#include <list>

using namespace std;



int main(){
    long long n;

    cin >> n;
    list<long long >front,back;
    for (long long i=1;i<=sqrt(n);i++){
        if (!(n%i)){
            front.push_back(i-1);
            if (n/(i)-1 != i-1) back.push_front(n/(i)-1);
        }
    }
    
    for (auto p : front){
        cout << p << " ";
    }
    for (auto p : back){
        cout << p << " ";
    }
    cout << '\n';



    return 0;
}