#include <iostream>
#include <list>

using namespace std;


bool compare(int a, int b){
    return a<b;
}

bool divide(string &num, int div){
    string result;
    int r=0, current=0, i=0;
    
    while (i<num.length()&&current<div){
        current = current*10+num[i++]-'0';
    }
    r = current%div;
    result += to_string(current/div);
    current=r;
    while (i<num.length()){
        current = current*10+num[i++]-'0';
        r = current%div;
        result += to_string(current/div);
        current=r;
    }
    
    if (!r){
        num = result;
        return true;
    }
    return false;
}

int main(){
    string num;
    list<int> digits;

    while (cin >> num){
        digits.clear();
        if (num=="0"){
            cout << 10 << "\n";
            continue;
        }else if(num == "1"){
            cout << 11 << "\n";
            continue;
        }else if(num=="-1"){
            break;
        }
        while (num != "1"){
            bool flag = false;
            for (int i=9;i>=2;i--){
                if (divide(num,i)){
                    flag = true;
                    digits.push_back(i);
                    break;
                }
            }
            if (!flag) break;
        }
        if (num!="1"){
            cout << "There is no such number.\n";
        }else{
            digits.sort(compare);
            if (digits.size()==1) cout << 1;
            for (auto d : digits){
                cout << d;
            }
            cout << "\n";
        }
    }

    return 0;
}