#include <iostream>
#include <vector>
#include <set>

using namespace std;

void work(){
    int n;
    cin >> n;

    vector<long long> v(n-1);
    for (auto &c : v) cin >> c;

    long long prev =  0;
    set<long long> u;
    for (auto &c : v){
        if (c-prev <= 0 || u.count(c-prev) || c-prev > n){
            cout << "NO\n";
            return;
        }
        u.insert(c-prev);
        prev = c;
    }
    cout << "YES\n";

}

int main(){
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) work();


    return 0;
}