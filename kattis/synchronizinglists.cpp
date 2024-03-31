#include <bits/stdc++.h>

using namespace std;

int List1[5000],List2[5000], Map[20001], List3[5000];

void work(int n){
    for (int i=0;i<n;i++){
        cin >> List1[i];
        Map[List1[i]+10000] = i;
    }

    for (int i=0;i<n;i++){
        cin >> List2[i];
    }

    sort(List1,List1+n);
    sort(List2,List2+n);
    
    for (int i=0;i<n;i++){
        List3[Map[List1[i]+10000]] = List2[i];
    }
    
    for (int i=0;i<n;i++){
        cout << List3[i] << "\n";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n){
        if (!n) break;
        work(n);
    }


    return 0;
}