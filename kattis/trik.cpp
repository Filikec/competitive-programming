#include <iostream>

using namespace std;


int Cups[3];

int main(){

    char c;

    Cups[0] = 1;
    while ((c=getchar())!='\n'){
        if (c == 'A'){
            int tmp = Cups[0];
            Cups[0] = Cups[1];
            Cups[1] = tmp;
        }else if (c == 'B'){
            int tmp = Cups[1];
            Cups[1] = Cups[2];
            Cups[2] = tmp;
        }else{
            int tmp = Cups[0];
            Cups[0] = Cups[2];
            Cups[2] = tmp;
        }
    }

    for (int i=0;i<3;i++){
        if (Cups[i]){
            cout << i+1 << '\n';
            break;
        }
    }


    return 0;
}