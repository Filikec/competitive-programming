#include <iostream>

#define INF 500001

using namespace std;




int main(){
    int n, b, h, w;
    int mini = INF;
    cin >> n >> b >> h >> w;
    for (int i=0;i<h;i++){
        int price;
        bool possible = false;
        cin >> price;
        for (int j=0;j<w;j++){
            int cap;
            cin >> cap;
            if (cap>=n) possible = true;
        }
        if (possible) mini = min(mini,price*n);
    }

    if (mini > b){
        cout << "stay home\n";
    }else{
        cout << mini << "\n";
    }





    return 0;
}