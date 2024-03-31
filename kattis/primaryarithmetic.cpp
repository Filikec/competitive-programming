#include <iostream>


using namespace std;


void add(long long a, long long b){
    int r=0, count = 0;
    while (r || a || b){
        if (r) count++;
        int digit = a%10+b%10+r;
        r = digit/10;
        a /= 10;
        b /= 10;
    }
    if (!count){
        cout << "No carry operation.\n";
    }else if (count == 1){
        cout << "1 carry operation.\n";
    }else{
        cout << count << " carry operations.\n";
    }

    
}

int main(){
    long long a, b;

    while (cin >> a >> b){
        if (!a && !b) break;
        add(a,b);
    }

    return 0;
}