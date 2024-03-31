#include <iostream>


using namespace std;


void solve(int n){
    string s;

    int left=0,right=0;

    for (int i=0;i<n;i++){
        int num;
        cin >> s >> num;
        if (s[0] == 'D'){
            left += num;
            cout << "DROP 1 " << num << '\n';
        }else{
            if (!right){
                right = left;
                cout << "MOVE 1->2 " << left << '\n';
                left = 0;
                right -= num;
                cout << "TAKE 2 " << num << '\n';
            }else if (right < num){
                cout << "TAKE 2 " << right << '\n';
                num -= right;
                right = 0;
                cout << "MOVE 1->2 " << left << '\n';
                right += left;
                left = 0;
                cout << "TAKE 2 " << num << '\n';
                right -= num;
            }else{
                cout << "TAKE 2 " << num << '\n';
                right -= num;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n){
        if (!n) break;
        solve(n);
        cout << '\n';
    }

    return 0;
}


