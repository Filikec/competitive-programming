#include <iostream>
#include <cmath>

using namespace std;



int main(){

    int cases;
    cin >> cases;
    for (int c=0;c<cases;c++){
        int n,k;
        scanf("%d %d",&n,&k);
        int needed = (2<<(n-1)) - 1;
        if (k%(needed+1)==needed){
            printf("Case #%d: ON\n",c+1);
        }else{
            printf("Case #%d: OFF\n",c+1);
        }
        
    }

    return 0;
}