#include <iostream>
#include <algorithm>

using namespace std;

long long Nums[100];

int main(){
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Nums[i];
    }

    sort(Nums,Nums+n);

    for (long long i=2;i<=Nums[1];i++){
        int remainder = Nums[0]%i;

        for (int j=1;j<n;j++){
            if (Nums[j]%i != remainder){
                remainder = -1;
                break;
            }
        }

        if (remainder != -1){
            cout << i << " " << remainder << "<\n";
        }

    }


    return 0;
}