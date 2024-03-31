#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int get_int(char f){
    char c;
    int result = f-'0';

    while ((c = cin.get()) != '\n'){
        result = result*10+c-'0';
    }

    return result;
}

int main(){

    vector<int> left,right;
    int med = -1;
    char c;
    while (cin >> c){
        int num;
        if (c == '#'){
            cin.get();
            ;
        }else{
            num = get_int(c);
            if (med == -1){
                med = num;
            }else{
                
            }
        }
    }




    return 0;
}