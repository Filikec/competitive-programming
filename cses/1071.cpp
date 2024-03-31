#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while (t--){
        long long x,y;
        cin >> y >> x;
        long long layer = max(x,y);
            
        if (layer==x){
            if (layer%2) cout << layer*layer-y+1 << '\n';
            else cout << (layer-1)*(layer-1)+1+y-1 << '\n';
        }else{
            if (layer%2==0) cout << layer*layer-x+1 << '\n';
            else cout << (layer-1)*(layer-1)+1+x-1<< '\n';
        }
    }


    

    return 0;
}