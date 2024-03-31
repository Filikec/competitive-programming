#include <bits/stdc++.h>

using namespace std;




int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
   
    list<string> s = {"0","1"};
    int p=2;
    for (int i=1;i<n;i++){
        for (int j=0;j<p;j++){
            auto cur = s.front();
            s.pop_front();
            if (j%2) s.push_back("1"+cur),s.push_back("0"+cur);
            else s.push_back("0"+cur),s.push_back("1"+cur);
        }
        p *= 2;
    }

    for (auto &c : s) cout << c << '\n';

    return 0;
}