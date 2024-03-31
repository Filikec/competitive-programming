#include <iostream>
#include <string>
#include <list>

using namespace std;


int main(){
    int n;
    cin >> n;

    int len = n/25+(n%25!=0);
    int dif = len*25-n;
    bool f = dif%2;

    if (len == 1){
        cout << 'a';
        cout << (char)('a'+n) << '\n';
        return 0;
    }

    cout << 'a';
    cout << (char)('z'-dif/2);

    for (int i=0;i<len-2;i++) if (i%2) cout << 'z'; else cout << 'a';

    if (f){
        if (len%2){
            cout << 'y';
        }else{
            cout << 'b';
        }
    }else{
        if (len%2){
            cout << 'z';
        }else{
            cout << 'a';
        }
    }

    return 0;
}