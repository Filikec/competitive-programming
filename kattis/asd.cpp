#include <iostream>
#include <list>

using namespace std;


void solve(){
    int n;

    cin >> n;

    if (n < 4){
        cout << "1\n" << n << '\n';
        return;
    }
    list<int> result;

    for (int i=1;i<4;i++){
        result.push_back(i);
    }
    
    int num = 4;
    while (num+3<n){
        for (int i=0;i<4;i++){
            result.push_back(num++);
        }
    }
    result.push_back(n);

    cout << result.size() << '\n';
    for (auto e : result){
        cout << e << ' ';
    }
    cout << '\n';
}


int main(){
    int n;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;

    

    for (int i=0;i<n;i++){
        solve();
    }
}