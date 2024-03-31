#include <iostream>
#include <algorithm>

using namespace std;

char Sieve[9999999];
int Digits[7];

int main(){
    int cases;
    for (long long i=2;i<10000000;i++){
        if (Sieve[i]){
            continue;
        }
        for (long long j=i+i;j<10000000;j+=i){
            Sieve[j] = 1;
        }
    }
    char c;
    int n,count,l;
    cin >> cases;
    getchar();
    for (int cas=0;cas<cases;cas++){
        l=0;
        count = 0;
        while ((c=getchar())!='\n'){
            Digits[l++] = c-'0';
        }

        for (int j=0;j<=l;j++){
            int tmp;
            if (j){
                tmp = Digits[j-1];
                Digits[j-1]=0;
                sort(Digits,Digits+l);
                l--;
            }
            while (next_permutation(Digits,Digits+l)){
                if (!Digits[0]) continue;
                int num = 0;
                for (int i=0;i<l;i++){
                    num = num*10 + Digits[i];
                }
                cout << num << "<\n";
                if (!Sieve[num]) count++;
            }
            if (l==1 && !Sieve[Digits[0]]) count++;
            if (j){
                Digits[l++] = tmp;
            }
        }
        cout << count << '\n';
        
    }
    

    return 0;
}