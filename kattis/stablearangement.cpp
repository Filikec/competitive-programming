#include <bits/stdc++.h>


using namespace std;


void work(){
    int r, s;

    cin >> s >> r;

    if ((s+1)/2 < r){
        cout << -1 << '\n';
        return;
    }

    for (int i=0;i<s;i++){
        for (int j=0;j<s;j++){
            if (i == j && i%2==0){
                cout << 'R';
            }else{
                cout << '.';
            }
            
        }
        cout << '\n';
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        work();
    }



    return 0;
}