#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char Used[10001][2];


void solve(int n){
    vector<int> numbers;
    numbers.reserve(n);

    cin.get();
    for (int i=0;i<=10000;i++){
        Used[i][0] = 0;
        Used[i][1] = 0;
    }
    for (int i=0;i<n;i++){
        int number;

        cin >> number;
        numbers.push_back(number);
        Used[number][0] = 1;
        Used[number][1] = i;
    }
    bool f = false;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int diff_next = numbers[j] - numbers[i];
            int diff_prev = numbers[i] - numbers[j];
            if (Used[numbers[j]+diff_next][0] && Used[numbers[j]+diff_next][1] > j){
                cout << "no\n";
                f = true;
                break;
            }
           
            if (Used[numbers[i]+diff_prev][0] && Used[numbers[i]+diff_prev][1] < i){
                cout << "no\n";
                f = true;
                break;
            }
        }
        if (f) break;
    }

    if (!f) cout << "yes\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n){
        if (!n) break;
        solve(n);
    }



    return 0;
}