#include <iostream>

using namespace std;


int main(){
    
    
    int cases;
    
    cin >> cases;
    
    for (int c=0;c<cases;c++){
        long long kids;
        long long mod = 0;
        cin >> kids;
        for (int k=0;k<kids;k++){
            long long candy;
            cin >> candy;
            mod += (candy%kids);
            mod %= kids;
        }
        
        if (!mod)cout << "YES\n";
        else cout << "NO\n";
    }
    
    
    return 0;
}