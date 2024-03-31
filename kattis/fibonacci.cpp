#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;



string addition(string s1, string s2){
    long long i1 = s1.length()-1, i2 = s2.length()-1;
    int remainder = 0;
    int digit;
    string result = "";

    while (i1 > -1 && i2 > -1){
        digit = s1[i1--]-'0' + s2[i2--]-'0'+remainder;
        if (digit > 9){
            remainder = 1;
        }else{
            remainder = 0;
        }
        digit = digit%10;
        digit += '0';
        result += (char)digit;
        
    }

    while (i1 > -1){
        result += s1[i1--] + remainder;
        if (remainder) remainder = 0;
    }
    while (i2 > -1){
        result += s2[i2--] + remainder;
        if (remainder) remainder = 0;
    }

    if (remainder) result += remainder+'0';

    for (unsigned long long i=0;i<result.length()/2;i++){
        swap(result[i],result[result.length()-i-1]);
    }
    return result;
    
}


void fib(unsigned long long n){
    string f1,f2,temp;

    f1 = "0";
    f2 = "1";
    if (n == 1){
        cout << f2 <<"\n";
        return;
    }else if (!n){
        cout << f1 << "\n";
        return;
    }

    for (unsigned long long i=1;i<n;i++){
        temp = addition(f1,f2);
        f1 = f2;
        f2 = temp;
    }

    cout << f2 << "\n";
}


int main(){
    unsigned long long n;

    cin >> n;

    fib(n);
    
    return 0;
}