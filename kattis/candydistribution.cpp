#include <iostream>

using namespace std;

typedef struct move{
    long long ppl, candy;
} Move; 

unsigned long long get_gcd(unsigned long long ppl, unsigned long long candy){
    unsigned long long lo, hi;
    Move last, now, tmp;

    if (ppl<candy){
        lo = ppl;
        hi = candy;
    }else{
        lo = candy;
        hi = ppl;
    }

    last.candy = 1;
    last.ppl = 0;
    now.ppl = 1;
    now.candy = 1;

    while (hi%lo){
        unsigned long long tmp;
        
        tmp = lo;
        lo = hi%lo;
        hi = tmp;

    }

    return lo;
}

void solve(){
    unsigned long long k,c;
    cin >> k >> c;

    if (get_gcd(k,c)!=1){
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    unsigned long long mod = c%k,times=1,r=0,d=c%k;
    while (mod!=1){
        int tmp = (k-mod)/(d);
        if (tmp){
            times += tmp;
            mod = (mod+tmp*(d))%k;
        }else{
            mod = (mod+(d))%k;
            times++;
        }
        cout << mod << "\n";
        
    }

    cout << times <<"\n";

}

int main(){

    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        solve();
    }

    return 0;
}