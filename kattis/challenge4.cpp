#include <iostream>

using namespace std;

int main(){
    int a,b;

    cin >> a >> b;

    int m, o;

    cin >> m >> o;

    int best = 0;
    for (int x=1;x<m;x++){
        int y = m-x;
        if (2*x+y>=o){
            best = max(best,a*x+b*y);
        }
    }

    cout << best << '\n';




    return 0;
}

