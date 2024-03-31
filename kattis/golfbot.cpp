#include <bits/stdc++.h>

using namespace std;

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


int main(){
    int n,m,count=0,power=524288;

    cin >> n;

    complex<double> *Distances = new complex<double>[power], *Results = new complex<double>[power];
    
    for (int i=0;i<power;i++){
        Distances[i] = complex<double>(0,0);
    }

    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        Distances[tmp] = complex<double>(1,0);
    }
    Distances[0] = complex<double>(1,0);

    complex<double> *fft = FFT(Distances,power,1);

    for (int i=0;i<power;i++){
        Results[i] = fft[i]*fft[i];
    }

    complex<double> *fft_r = FFT(Results,power,-1);

    cin >> m;

    for (int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        cout << tmp << ' ' << abs(fft_r[tmp]) << "<\n";
        if (abs(fft_r[tmp]) > 0.0001){
            count++;
        }
    }

    cout << count << "\n";


    return 0;
}