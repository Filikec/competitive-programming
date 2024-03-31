#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;


bool is_prime(int n){

    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0) return false;
    }
    return true;
}


int get_sqaure_sum(int n){
    int sum = 0;
    while (n){
        int digit = n%10;
        sum += digit*digit;
        n /= 10;
    }
    return sum;
}

void solve(){
    int dataset,num,original;

    cin >> dataset >> num;
    original = num;

    if (!is_prime(num) || num < 7){
        cout << dataset << ' ' << original << ' ' << "NO\n";
        return;
    }

    unordered_set<int> Used;
    while (!Used.count(num) && num!=1){
        Used.insert(num);
        num = get_sqaure_sum(num);
    }
    cout << dataset << ' ' << original << ' ';
    if (num==1){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }


}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        solve();
    }





    return 0;
}