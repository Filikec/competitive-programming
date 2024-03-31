#include <iostream>

using namespace std;


int main(){
    int c,can=0,must=0;

    while ((c=getchar())!='\n'){
        if (c=='a'){
            can++;
        }
    }

    while ((c=getchar())!='\n'){
        if (c=='a'){
            must++;
        }
    }

    if (must > can){
        cout << "no\n";
    }else{
        cout<< "go\n";
    }



    return 0;
}