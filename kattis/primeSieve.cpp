#include <iostream>
#include <vector>

using namespace std;

vector<bool> Prime(100000001,1);

int main(){

    long long n,q;

    cin >> n >> q;

    Prime[1] = false;
    long long count = 0;
    for (long long i=2;i<=n;i++){
        if (Prime[i]){
            count++;
            for (long long j=i*i;j<=n;j+=i){
                Prime[j] = false;
            }
        }
    }
    cout << count << "\n";

    for (long long i=0;i<q;i++){
        long long tmp;
        cin >> tmp; 
        if (!Prime[tmp]){
            cout << "0\n";
        }else{
            cout << "1\n";
        }
    }
    

    return 0;
}