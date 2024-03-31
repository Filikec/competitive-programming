#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long S[100000], F[100000];
long long S_l,F_l;
long long S_popped = 0, F_popped = 0;

long long work(int s, int f, int last, int nat, long long points){
    if ((s==S_l && nat) || (f==F_l && !nat)){
        return points;
    }

    while (s < S_l && S[s] == -1){
        s++;
    }

    while (f < F_l && F[f] == -1){
        f++;
    }
    
    if (!last){
        if (S[s] < F[f]){
            last = S[s];
            S[s] = -1;
            S_popped++;
            return work(++s,f,last,0,points);
        }else{
            last = F[f];
            F[f] = -1;
            F_popped++;
            return work(s,++f,last,0,points);
        }
    }

    if (nat){
        while (s < S_l && S[s] <= last){
            s++;
        }
        if (s == S_l){
            return points;
        }
        points++;
        last = S[s];
        S[s] = -1;
        S_popped++;
        return work(++s,f,last,!nat,points);
    }

    while (f < F_l && F[f] <= last){
        f++;
    }
    if (f == F_l){
        return points;
    }
    points++;
    last = F[f];
    F[f] = -1;
    F_popped++;
    return work(s,++f,last,!nat,points);
}

int main(){
    long long int result = 0;
    cin >> S_l >> F_l;

    for (int i=0;i<S_l;i++){
        cin >> S[i];
    }

    for (int i=0;i<F_l;i++){
        cin >> F[i];
    }

    sort(S,S+S_l);
    sort(F,F+F_l);

    while (S_l != S_popped && F_l != F_popped){
        result += work(0,0,0,0,0);
    }

    cout << result << '\n';

    return 0;
}