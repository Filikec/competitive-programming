#include <iostream>

using namespace std;


int main(){
    
    
    int n,count=0;
    
    while(cin >> n){
        count++;
        char c = getchar();
        if (c == '-'){
            int n2;
            cin >> n2;
            count += n2-n;
            getchar();
        }
    }
    
    cout << count << '\n';
    return 0;
}