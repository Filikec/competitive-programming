#include <iostream>

using namespace std;


int main(){
    int n,mod=0;
    
    cin >> n;

    for (int i=0;i<n;i++){
        int money;
        cin >> money;
        mod = (mod+(money%3))%3;
    }

    if (!mod){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }



    return 0;
}