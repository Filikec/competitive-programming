#include <bits/stdc++.h>


using namespace std;

int Lounges[200000], Routes[200000];


int main(){

    int n,m;

    for (int i=0;i<n;i++){
        Lounges[i] = -1;
    }


    for (int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;

        if (!c){
            if (Lounges[a]==1 || Lounges[b]==1){
                cout << "impossible\n";
                return 0;
            }
            Lounges[a] = 0;
            Lounges[b] = 0;
        }else if (c==2){
            if (!Lounges[a] || !Lounges[b]){
                cout << "impossible\n";
                return 0;
            }
            Lounges[a] = 1;
            Lounges[b] = 1;
        }else{
            if (!Lounges[a] && !Lounges[b]){
                cout << "impossible\n";
                return 0;
            }
            if (Lounges[a] == 1 && Lounges[b] == 1){
                cout << "impossible\n";
                return 0;
            }
        }
    }

    return 0;
}