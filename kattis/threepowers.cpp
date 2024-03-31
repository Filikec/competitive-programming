#include <iostream>
#include <climits>
#include <cmath>
#include <list>

using namespace std;

list<string> Result;

string get_pow_3(int power){
    string result = "1", tmp = "";

    for (int i=0;i<power;i++){
        int remainder = 0;
        for (int j=0;j<result.size();j++){
            int digit = result[j]-'0';
            digit = digit*3 + remainder;
            remainder = digit/10;
            digit %= 10;
            tmp += digit+'0';
        }
        if (remainder){
            tmp += remainder + '0';
        }
        result = tmp;
        tmp = "";
    }
    for (int i=0;i<result.size();i++){
        tmp += result[result.size()-1-i];
    }
    return tmp;
}

int main(){
    unsigned long long n;

    while (cin >> n && n){
        cout << "{ ";
        string numbers = "";
        while (n-1){
            unsigned long long power = log2l(n-1);
            n = n-(unsigned long long)pow(2,power);
            Result.push_front(get_pow_3(power));
        }

        while (!Result.empty()){
            cout << Result.front();
            Result.pop_front();
            if (!Result.empty()){
                cout << ", ";
            }
        }
        cout << " }\n";
    }

   


    return 0;
}