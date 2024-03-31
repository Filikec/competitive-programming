#include <iostream>

using namespace std;


void solve(){
    int a,b,c;

    cin >> a >> b >> c;

    if (a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    if (!c){
        cout << "Yes\n";
        return;
    }

    if (c == a || c == b){
        cout << "Yes\n";
        return;
    }

    if (c > b){
        cout << "No\n";
        return;
    }

    int dif = a%b;

    if (b%2==0){
        if (c > dif && c <= b/2){
            cout << "Yes\n";
            return;
        }
    }else{
        if (c > dif){
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}


int main(){
    int cases;

    cin >> cases;
    for (int c=0;c<cases;c++){
        solve();
    }

}