#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long   ll;
typedef long double ld;

int R[1000],C[1000];

int main(){
    int m,n;

    cin >> m >> n;

    for (int i=0;i<m;i++){
        cin >> R[i];
        if (R[i]==n){
            for (int j=0;j<n;j++){
                C[j]--;
            }
            R[i]=0;
        }
    }

    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        C[i] += tmp;
        
        if (C[i]==m){
            for (int j=0;j<m;j++){
                R[j]--;
            }
            C[i]=0;
        }
    }


    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (R[i]>0 && C[j]>0){
                R[i]--;
                C[j]--;
            }
        }
    }

    for (int i=0;i<m;i++){
        if (R[i]!=0){
            cout << "No\n";
            return 0;
        }
    }

    for (int i=0;i<n;i++){
        if (C[i]!=0){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}