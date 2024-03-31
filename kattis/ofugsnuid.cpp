#include <iostream>

using namespace std;

int Mem[100000];

int read_int(){
    char c;
    int result = 0;
    while ((c=getchar()) != '\n'){
        result = result*10+c-'0';
        
    }
    return result;
}


int main(){
    int n;

    n = read_int();

    for (int i=0;i<n;i++){
        Mem[i] = read_int();
    }

    std::ios_base::sync_with_stdio(false);
    for (int i=n-1;i>-1;i--){
        cout << Mem[i] << "\n";
    }

    return 0;
}