#include <iostream>

using namespace std;


int Dynamic[50000];
char Chars[50000];

int main(){
    char c;
    int i=0, most = 0;;
    while ((c=getchar())!='\n'){
        int maxim = 1;
        for (int j=0;j<i;j++){
            if (Chars[j] < c){
                maxim = max(maxim,Dynamic[j]+1);
            }
        }
        Chars[i] = c;
        Dynamic[i] = maxim;
        most = max(most,maxim);
        i++;
    }
    cout << 26-most << "\n";

    return 0;
}