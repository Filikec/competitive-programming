#include <iostream>

using namespace std;


char Teeth[16];



int main(){
    int n;

    cin >> n;
    getchar();
    for (int i=0;i<n;i++){
        char c;
        int n=0;
        c = getchar();
        n = getchar();
        getchar();
        if (c == '+' || c == '-'){
            n += 7-'0';
        }else{
            n = c-'1';
        } 
        
        char problem = getchar();
        getchar();
        if (Teeth[n]!='b') Teeth[n] = problem;
    }

    int result = 0;
    for (int i=0;i<8;i++){
        if (Teeth[i] == 'b'){
            result++;
            break;
        }else if (!Teeth[i]) result = 0;
    }

    if (!result){
        cout << "1\n";
        return 0;
    }

    for (int i=8;i<16;i++){
        if (Teeth[i] == 'b'){
            result++;
            break;
        }else if (!Teeth[i]) result = 0;
    }

    if (!result){
        cout << "2\n";
        return 0;
    }
    cout << "0\n";



    return 0;
}