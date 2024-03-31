#include <iostream>


using namespace std;



int main(){
    int a, b, c, count=0;

    cin >> a >> b >> c;


    while (abs(b-a)>1||abs(c-b)>1){
        if (b-a > c-b){
            c = b;
            b = b-1;
        }else{
            a = b;
            b = b+1;
        }
        count++;
    }


    cout << count << '\n';

    return 0;
}