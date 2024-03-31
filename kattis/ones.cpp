#include <iostream>

using namespace std;

int main(){
    int modulo,n,ten,count;

    while (scanf("%d",&n)==1){
        modulo = 1%n;
        ten = 10%n;
        count = 1;

        while (modulo){
            modulo = (modulo*ten)%n;
            modulo = (modulo+1)%n;
            count++;
        }

        printf("%d\n",count);

    }
    



    return 0;
}