#include <iostream>

using namespace std;


bool Impossible[1000][1000];
int Count[1000], PossibleCount[1000];


int main(){
    int n,m;

    cin >> n >> m;
    cin.get();
    for (int i=0;i<m;i++){
        bool switches[1000], lights[1000];
        for (int j=0;j<n;j++) switches[j] = cin.get()=='1';
        cin.get();
        for (int j=0;j<n;j++) lights[j] = cin.get()=='1';
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                Impossible[j][k] = switches[j]^lights[k];
            }
        }
    }


    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (!Impossible[i][j]) PossibleCount[i]++;
        }
    }
    

    return 0;
}

