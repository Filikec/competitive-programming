#include <iostream>
#include <list>
#include <cstring>

using namespace std;

int Dynamic[1000001]; // 0-second player wins

void solve(int n){
    int m;
    cin >> m;

    list<int> nums;
    for (int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    for (int i=1;i<=n;i++){
        Dynamic[i] = 0;
        for (auto num : nums){
            if (i-num>=0 && !Dynamic[i-num]){
                Dynamic[i] = 1;
                break;
            }
        }
    }
    
    if (Dynamic[n]){
        cout << "Stan wins\n";
    }else{
        cout << "Ollie wins\n";
    }

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    
    Dynamic[0] = 0;

    while (cin >> n){
        solve(n);
    }


    return 0;
}