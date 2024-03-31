#include <iostream>
#include <iomanip>

using namespace std;

double white,lower,upper,symbols;
int n;
char c;

int main(){
    while ((c=getchar())!='\n'){
        n++;
        if (c >= 'a' && c <= 'z' ){
            lower++;
        }else if (c >= 'A' && c <= 'Z'){
            upper++;
        }else if (c == '_'){
            white++;
        }else{
            symbols++;
        }
    }

    cout << fixed << setprecision(6) << white/n << "\n" << lower/n << "\n" << upper/n << "\n" << symbols/n << "\n";

    

    return 0;
}