#include <iostream>

using namespace std;


int main(){
    
    int a,b;
    
    cin >> a >> b;
    
    
    for (int i=0;i<b;i++){
        for (int j=0;j<15;j++){
            cout << (char) ('a' + rand()%20);
        }
        cout << ' ';
    }
    cout << '\n';
    
    
    return 0;
}