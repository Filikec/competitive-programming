#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


set<int> Sums;
vector<int> Nums;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,c=1;

    Nums.reserve(10000);
    while (cin >> n){
        cout << "Case " << c++ << ":\n";
        Nums.clear();
        Sums.clear();
        for (int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            for (auto e : Nums){
                Sums.insert(e+tmp);
            }
            Nums.push_back(tmp);
        }

        int m;

        cin >> m;

        for (int i=0;i<m;i++){
            int least = 10000001, sum;
            int curr;
            cin >> curr;
            for (auto e : Sums){
                if (abs(e-curr) < least){
                    least = abs(e-curr);
                    sum = e;
                }
            }
            cout << "Closest sum to " << curr << " is " << sum << ".\n";
        }

    }



    return 0;
}