#include <iostream>


using namespace std;


int Counters[10];


int main(){
    string s;

    cin >> s;

    for (int i=0;i<s.size();i++){
        Counters[s[i]-'0']++;
    }


    for (int count=0;count<=1000;count++){
        for (int i=1;i<10;i++){
            if (Counters[i]==count){
                cout << string(count+1, i+'0') << "\n";
                return 0;
            }
        }
    }


    return 0;
}



