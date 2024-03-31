#include <iostream>

using namespace std;

long long Peaks[200000];


long long getN(){
    char c;
    long long n=0;
    while ((c=getchar()) && c <='9' && c >= '0'){
        n = n*10+(c-'0');
    }
    return n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    n = getN();

    for (int i=0;i<n;i++){
        Peaks[i] = getN();
    }

    long long best = 0;
    
    for (int i=0;i<n;){
        long long prev = 0;
        long long biggest = 0;
        long long first = Peaks[i];
        while (i<n && prev <= Peaks[i]){
            prev = Peaks[i];
            i++;
        }
        biggest = prev;
        while (i<n && prev >= Peaks[i]){
            prev = Peaks[i];
            i++;
        }
        best = max(best,min(biggest-first,biggest-prev));
        if (i == n) break;
        i--;
    }


    printf("%lld\n",best);


    return 0;
}