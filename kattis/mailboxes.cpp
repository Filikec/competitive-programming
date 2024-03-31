#include <iostream>


using namespace std;


int getSum(int a, int n){
    return n*a+n*(n-1)/2;
}


void work(){
    int n,m;
    cin >> n >> m;

    int a=1,b=m;
    while (n--!=1){
        int dif=1000000000;
        int an,bn;
        for (int i=1;i<=b;i++){
            int t = max(getSum(a,i-1),getSum(i+1,b-i));
            if (t < dif){
                dif = t;
                if (getSum(a,i-1) < getSum(i+1,b-i)){
                    an = i+1;
                    bn = b;
                }else{
                    an = a;
                    bn = i-1;
                }
            }
        }
        a = an;
        b = bn;
        cout << a << ' ' << b << '\n';
    }
    cout << getSum(a,b) << '\n';
}

int main(){

    int c;

    cin >> c;

    for (int i=0;i<c;i++) work();

    return 0;
}