#include <iostream>
#include <set>

using namespace std;

int Nums[100000];

int main(){
    int n;

    cin >> n;


    set<int> left, right;

    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        right.insert(tmp);
        Nums[i] = tmp;
    }

    int count=0;
    for (int i=0;i<n;i++){
        if ((!left.size() || *prev(left.end()) <= Nums[i]) && (!right.size() || *right.begin() >= Nums[i])){
            count++;
        }
        left.insert(Nums[i]);
        right.erase(Nums[i]);
    }

    cout << count << '\n';
    

    return 0;
}