#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int Nums[50];


long long comb(long double n, long double take){
    long double r = 1;

    take = min(take,n-take);

    while (take){
        r *= n--;
        r /= take--;
    }
    return round(r);
}

int main(){


    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Nums[i];
    }   

    sort(Nums,Nums+n);
    long long result = 0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int biggest = Nums[i]+Nums[j];
            int least = max(Nums[i],Nums[j]);


            int count = 0;

            for (int i=0;i<n;i++){
                if (Nums[i] > least && Nums[i] < biggest) count++;
            }
            
            for (int i=1;i<=count;i++){
                result += comb(count,i);
            }

        }
    }

    cout << result << '\n';

    return 0;
}
