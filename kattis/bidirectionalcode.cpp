#include <iostream>
#include <cmath>
#include <string>
#include <list>

using namespace std;

bool check_pal(string s){
    for (int j=s.size()-1, i=0; i<s.size()/2 && j>s.size()/2;i++,j--){
        if (s[i]!=s[j]) return false;
    }
    return true;
}

string get_biggest_pal(string number){
    string start;

    if (check_pal(number)){
        return number;
    }

    if (number.size()==1) return number;

    for (int i=0;i<number.size()/2;i++){
        start += number[i];
    }
    
    if (number.size()%2){
        start += number[number.size()/2];
    }

    bool f =false;
    for (int i=start.size()-1;i>0;i--){
        if (start[i]>'0'){
            start[i]--;
            f = true;
            break;
        }
    }

    if (!f){
        if (start[0] == '1'){
            start = "0";
            return start;
        }else{
            start[0]--;
        }
    }
    
    string result=start;

    for (int i=number.size()/2-1;i>=0;i--){
        result += start[i];
    }

    for (auto e : result){
        if (e<'0'||e>'9'){
            result = "0";
            break;
        }
    }

    return result;
}


void solve(string number){
    unsigned long long n,num;
    num = stoull(number);
    list<string> palindromes;
    while (n){
        n = stoull(number);
        string pal = get_biggest_pal(number);
        unsigned long long palindrom = stoull(pal);
        if (!palindrom){
            palindrom = 0;
            while (n){
                n /= 10;
                palindrom = palindrom*10+9;
            }
            n = stoull(number);
            palindrom /= 10;
        }
        
        n -= palindrom;
        palindromes.push_back(to_string(palindrom));
        number = to_string(n);
    }

    if (palindromes.size()>10){
        cout << num << "<1\n";
    }else{
        unsigned long long sum = 0;
        for (auto e : palindromes){
            sum += stoull(e);
            if (!check_pal(e)){
                cout << num << "<2\n";
                break;
            }
        }
        
        if (sum != num){
            cout << num << "<3\n";
        }
        cout << palindromes.size() << '\n';
    }

}


int main(){

    solve("400000000004");
    
    return 0;
}