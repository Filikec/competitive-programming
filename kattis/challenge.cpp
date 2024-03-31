#include <iostream>
using namespace std;

int DNA[200000], Needed[200000],Or[200000];

int main(){

    int n,k,r;
    cin >> n >> k >> r;

    int needed = 0;
    for (int i=0;i<n;i++) cin >> DNA[i];
    for (int i=0;i<r;i++){
        int b,v;
        cin >> b >> v;
        Needed[b] += v;
        Or[b] = 1;
        needed += v;
    }

    int start = 0, best = 200001;

    for (int i=0;i<n;i++){
        if (Or[DNA[i]]){
            if (Needed[DNA[i]]>0) needed--;
            Needed[DNA[i]]--;
        }

        while (start < i && (Needed[DNA[start]] < 0 || !Or[DNA[start]])){
            if (Or[DNA[start]]) Needed[DNA[start]]++;
            start++;
        }

        if (needed <= 0){
            best = min(best,i-start+1);
        }
    }
    if (best == 200001){
        cout << "impossible\n";
    }else cout << best << '\n';

    return 0;   
}
