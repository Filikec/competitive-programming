#include <iostream>
#include <algorithm>

using namespace std;

int Trees[1000000];

bool compare(int n1, int n2){
    return n1 > n2;
}

int main(){
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Trees[i];
    }

    sort(Trees,Trees+n,compare);


    for (int i=0;i<n;i++){
        Trees[i] += i+1;
    }

    int biggest = 0;
    for (int i=0;i<n;i++){
        if (biggest < Trees[i]){
            biggest = Trees[i];
        } 
    }
    
    cout << biggest+1 << "\n";


    return 0;
}