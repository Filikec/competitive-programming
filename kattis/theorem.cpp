#include <iostream>

using namespace std;


int main(){



    for (int n=3;;n++){
        for (int a=2;;a++){
            for (int b=2;;a++){
                for (int c=2;;a++){
                    if (a*a + b*b == c*c){
                        return 0;
                    }
                }
            }
        }   
    }

}