#include <iostream>

using namespace std;


char Board[200][200];
int H,G,R,C,K;


bool check(int x,int y){
    char sign = Board[x][y];

    if (x+K<=R){
        bool f = false;
        for (int i=x;i<x+K;i++){
            if (Board[i][y]!=sign){
                f = true;
                break;
            }
        }
        if (!f) return true;
    }
    if (y+K<=C){
        bool f = false;
        for (int i=y;i<y+K;i++){
            if (Board[x][i]!=sign){
                f = true;
                break;
            }
        }
        if (!f) return true;
    }
    if (y-K>=-1 && x+K<=R){
        bool f = false;
        for (int i=0;i<K;i++){
            if (Board[x+i][y-i]!=sign){
                f = true;
                break;
            }
        }
        if (!f) return true;
    }
    if (y+K<=C && x+K<=R){
        bool f = false;
        for (int i=0;i<K;i++){
            if (Board[x+i][y+i]!=sign){
                f = true;
                break;
            }
        }
        if (!f) return true;
    }

    return false;

}

void solve(){
    cin >> C >> R >> K;

    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> Board[i][j];
        }
    }

    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            if (Board[i][j] != '.' && check(i,j)){
                if (Board[i][j] == 'x') H++;
                else G++;
                return;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        solve();
    }

    cout << H << ":" << G << "\n";

    return 0;   
}