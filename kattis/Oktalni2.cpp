#include <iostream>
#include <list>

using namespace std;


int main(){


    string s;

    cin>>s;


    list<int> n;
    for (int i=s.size()-1;i>=0;){
        int power = 1;
        int digit = 0;
        while (i>=0&&power<8){
            digit += (s[i]-'0')*power;
            power *= 2;
            i--;
        }
        n.push_front(digit);
    }

    for (auto d : n){
        cout << d;
    }
    cout<<"\n";

    return 0;
}