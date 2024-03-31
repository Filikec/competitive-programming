#include <iostream>


using namespace std;


bool Rooms[150];

int main(){
    int n,b;

    cin >> n >> b;

    for (int i=0;i<b;i++){
        int tmp;
        cin >> tmp;
        Rooms[tmp] = 1;
    }
    bool f=false;
    for (int i=1;i<=n;i++){
        if (!Rooms[i]){
            cout << i << '\n';
            f = true;
            break;
        }
    }
    if (!f) cout << "too late\n";
    



    return 0;
}