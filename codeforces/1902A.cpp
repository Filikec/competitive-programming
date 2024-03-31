#include <bits/stdc++.h>

using namespace std;

void work(){
    int n;
    cin >> n;
    
    char c;
    int count[2];
    count[0] = count[1] = 0;
    for (int i=0;i<n;i++){
        cin >> c;
        count[c-'0']++;
    }

    if (count[0] > count[1]) cout << "YES\n";
    else if (count[1] && count[0]) cout << "YES\n";
    else cout << "NO\n";

}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    while (t--) work();

    return 0;
}
