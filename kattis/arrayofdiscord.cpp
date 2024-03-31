#include <bits/stdc++.h>

using namespace std;

long long Nums[100];

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> Nums[i];
    }


    bool got = false;
    for (int i=0;i<n;i++){
        list<int> digits;
        long long num = Nums[i];
        if (!num) digits.push_back(0);  
        while (num){
            digits.push_front(num%10);
            num /= 10;
        }
        long long bigger=0,smaller=0;
        bool aug = false;
        for (auto d : digits){
            int cur = d;
            if (!aug && cur != 9){
                aug = true;
                cur = 9;
            }
            bigger = bigger*10+cur;
        }
        aug = false;
        if (digits.size() == 1) smaller = 0;
        else{
            if (digits.front() != 1){
                digits.front() = 1;
                aug = true;
            }
            for (auto d : digits){
                int cur = d;
                smaller = smaller*10+cur;
                if (!aug && cur != 0 && smaller > 9){
                    smaller /= 10;
                    smaller *= 10;
                    aug = true;
                }
            }
        }
        for (int j=i+1;j<n;j++){
            if (bigger > Nums[j]){
                Nums[i] = bigger;
                got = true;
                break;
            }
        }
        if (got) break;
        for (int j=i-1;j>-1;j--){
            if (smaller < Nums[j]){
                Nums[i] = smaller;
                got = true;
                break;
            }
        }
        if (got) break;
    }

    if (!got){
        cout << "impossible\n";
    }else{
        for (int i=0;i<n;i++){
            cout << Nums[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}