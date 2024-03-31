#include <iostream>
#include <algorithm>

using namespace std;


int Socks[100000];


int main(){

    int s,c,k;

    cin >> s >> c >> k;

    for (int i=0;i<s;i++){
        cin >> Socks[i];
    }

    sort(Socks,Socks+s,[](int a,int b){return a<b;});

    int needed = 0;
    int cur = -2100000000;
    int cap = 0;
    for (int i=0;i<s;i++){
        if (Socks[i]-cur > k || cap == c){
            needed++;
            cap = 0;
        }
        cap++;
        cur = Socks[i];
    }
    cout << needed << '\n';

    return 0;
}