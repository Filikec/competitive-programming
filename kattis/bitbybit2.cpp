#include <iostream>

using namespace std;


char myOr(char l, char r){
    if (l == 't' || r == 't') return 't';
    if (l == 'f' && r == 'f') return 'f';
    return '?';
}

char myAnd(char l, char r){
    if (l == 'f' || r == 'f') return 'f';
    if (l == 't' && r == 't') return 't';
    return '?';
}

char Register[32];

void clearRegister(){
    for (int i=0;i<32;i++) Register[i] = '?';
}

void printRegister(){
    for (int i=31;i>=0;i--){
        char v = Register[i];
        if (v == 't'){
            cout << '1';
        }else if (v == 'f'){
            cout << '0';
        }else{
            cout << '?';n
        }
    }
}

void work(int n){
    string s;
    int r;
    
    clearRegister();
    
    for (int i=0;i<n;i++){
        cin >> s;
        cin >> r;
        if (s == "SET"){
            Register[r] = 't';
        }else if (s == "CLEAR"){
            Register[r] = 'f';
        }else{
            int r2;
            cin >> r2;
            if (s == "OR"){
                Register[r] = myOr(Register[r],Register[r2]);
            }else{
                Register[r] = myAnd(Register[r],Register[r2]);
            }
        }
    }
    printRegister();
    cout << '\n';
}

int main(){
    
    int n;
    
    while (cin >> n){
        if (!n) break;
        work(n);
    }
    
    return 0;
}