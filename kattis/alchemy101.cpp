#include <iostream>
#include <list>


using namespace std;


int Distance[1001][1001];


int solve(){
    int n;
    cin >> n; 

    for (int i=1;i<=n;i++){
        for (int j=0;j<=n;j++){
            Distance[i][j] = 0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=0;j<=n;j++){
            ;
        }
    }
}

int main(){
    int cases;

    cin >> cases;
    for (int c=0;c<cases;c++){
        int a,b;

        cin  >> a >> b;

        cout << (a^b) << "\n";
    }


    return 0;
}