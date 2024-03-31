#include <bits/stdc++.h>

using namespace std;

#define OFFSET 50000

int rev(int num, int N){
    int result = 0, i=0;

    N = log2(N);

    while (num){
        int bit = num%2;
        result += bit*(1<<(N-1-i++));
        num /= 2;
    }

    return result;
}

complex<double> *FFT (complex<double> *Array, int N, int flag){
    complex<double> *array = new complex<double>[N];

    for (int i=0;i<N;i++){
        array[rev(i,N)] = Array[i];
    }

    for (int length=2;length<=N;length*=2){

        complex<double> base = complex<double>(cos(-flag*2.*M_PI/length),sin(-flag*2.*M_PI/length));

        for (int k=0;k<N;k+=length){
            complex<double> w_p = complex<double>(1,0);
            for (int p=k;p<k+(length>>1);p++){
                complex<double> even = array[p];
                complex<double> odd = array[p+(length>>1)];
                array[p] = even+w_p*odd;
                array[p+(length>>1)] = even-w_p*odd;
                w_p *= base;
            }
        }
    }
    if (flag==-1){
        for (int i=0;i<N;i++){
            array[i]/=N;
        }
    }

    return array;
}


int Count[100001];
unordered_set<int> Original;

int main(){
    int n,m,power=262144;

    cin >> n;

    complex<double> *Distances = new complex<double>[power], *Results = new complex<double>[power];
    
    for (int i=0;i<power;i++){
        Distances[i] = complex<double>(0,0);
    }

    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        Original.insert(tmp);
        tmp+=OFFSET;
        Count[tmp]++;
        Distances[tmp]+=complex<double>(1,0);
    }

    complex<double> *fft = FFT(Distances,power,1);

    for (int i=0;i<power;i++){
        Results[i] = fft[i]*fft[i];
    }

    complex<double> *fft_r = FFT(Results,power,-1);

    unsigned long long count = 0;
    for (auto e : Original){
        unsigned long long add = 0;
        
        if (abs(fft_r[e+OFFSET*2]) > 0.00000001){
            add = (unsigned long long) round(abs(fft_r[e+OFFSET*2]));
            if (!e){ // if 0 - it can be 0+0=0
                add -= Count[OFFSET]*Count[OFFSET];
                add *= Count[OFFSET];
                if (Count[OFFSET] >= 3) add += Count[OFFSET]*(Count[OFFSET]-1)*(Count[OFFSET]-2);
            }else{  
                if (e%2==0){// if is divisible by 2 = it can be e/2 + e/2 = e
                    add -= Count[e/2+OFFSET];
                }
                add -= 2*Count[e+OFFSET]*Count[OFFSET]; //0+e = e
                add *= Count[e+OFFSET];
                add += 2*Count[e+OFFSET]*(Count[e+OFFSET]-1)*Count[OFFSET];
            }
        }
        if (add > 0) count += add;
    }

    cout << count << "\n";

    return 0;
}


/*
4
-1 -2 -3 -4


5
0 1 2 3 4

5
1 1 2 2 3

7
0 1 1 2 2 2 3
111111111111

6
1 1 2 2 2 3


3
0 1 1 

3
0 0 0
*/