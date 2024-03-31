#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int Nums[300000];

void rev(int s, int e){
    for (int i=0;i<=(e-s)/2;i++) swap(Nums[s+i],Nums[e-i]);
}

bool isSorted(int n){
    for (int i=1;i<n;i++) if (Nums[i] < Nums[i-1]) return false;
    return true;
}

int main(){
    int n;

    cin >> n;

    
    for (int i=0;i<n;i++){
        cin >> Nums[i];
    }

    bool good = 1;

    int ind = 0;
    for (int i=1;i<n;i++){
        if (Nums[i] < Nums[i-1]){
            good = 0;
        }else if (!good){
            ind = i-1;
            break;
        }
    }

    if (good){
        cout << "YES\n";
        return 0;
    }
    int end = ind;
    while (ind && Nums[ind] < Nums[ind-1]){
        ind--;
    }
    int start = ind;

    rev(start,end);

    if (isSorted(n)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }



    

    return 0;
}
