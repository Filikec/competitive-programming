#include <iostream>
#include <cmath>

using namespace std;

string to_bin(int n){
    string s = "";
    char digit;
    while (n){
        digit = n%2;
        n /= 2;
        s += digit+'0';
    }
    return s;
}

bool is_pal(string s){
    for (int i=0;i<=s.length()/2;i++){
        if (s[i] != s[s.length()-i-1]) return false;
    }
    return true;
}

int to_int(string s){
    int result = 0;
    for (int i=0;i<s.length();i++){
        result *= 2;
        result += s[s.length()-i-1]-'0';
    }
    return result;
}

int main(){
    int n;
    int sum = 0, count = 0;
    float add = 0.5;

    cin >> n;
    
    while (sum < n){
        if (count%2==0) add*=2;
        sum += add;
        count += 1;
    }
    int number = pow(2,count)-1;
    
    if (sum == n){
        cout << number << "\n";
        return 0;
    }

    string s = to_bin(number);
    int ind = s.length()%2?s.length()/2:s.length()/2-1;
    int decide = 2;
    char repl = '0';
    cout << sum-n << "\n";
    int i = 0;
    int smth = sum-n;
    while (smth){
        if (smth%decide==0){
            repl = '1';
        }else{
            repl = '0';
        }
        smth /= 2;

        s[ind-i] = repl;
        s[s.length()-ind-1+i] = repl;
        decide*=2;
        i++;
   
    }
    cout << s <<" " << sum  <<"\n";
    
    cout << to_int(s) << "\n";
    return 0;
}