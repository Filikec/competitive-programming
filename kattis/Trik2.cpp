#include <iostream>
#include <algorithm>

using namespace std;



int main(){


    int a,b,c;


    a = 1;
    b = c = 0;


    char d;

    while (cin>>d){
        if (d == 'A'){
            swap(a,b);
        }else if (d == 'B'){
            swap(b,c);
        }else{
            swap(a,c);
        }
    }

    if (a){
        cout << "1";
    }else if (b){
        cout << 2;
    }else{
        cout << 3;
    }
    cout << '\n';


    return 0;
}