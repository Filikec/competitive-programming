#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int count, w, h;

    cin >> count >> w >> h;

    long long prepona = sqrt(w*w+h*h);

    for (int i=0;i<count;i++){
        int l;
        cin >> l;

        if (l <= prepona) cout << "DA\n";
        else cout << "NE\n";
    }




    return 0;
}