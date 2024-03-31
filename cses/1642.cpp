#include <bits/stdc++.h>


using namespace std;


int main(){

    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> v(n);
    for (int i=0;i<n;i++) cin >> v[i].first, v[i].second = i+1;
    sort(v.begin(),v.end());

    int r = v.size()-1;
    for (int l=0;l<v.size();l++){
        while (v[l].first + v[r].first >= x && l < r) r--;
        if (l >= r) break;
        for (int r2=r;r2>l+2;r2--){
            int nx = x - v[l].first - v[r2].first;
            int l1,r1;
            l1 = l+1,r1=r2-1;

            while (l1 < r1){
                while (v[l1].first + v[r1].first > nx && l1 < r1) r1--;
                if (l1 >= r1) break;
                if (v[l1].first+v[r1].first==nx){
                    cout << v[l].second << ' ' << v[r2].second << ' ' << v[l1].second << ' ' << v[r1].second << '\n';
                    return 0;
                }
                l1++;
            }
        }
        
    }

    cout << "IMPOSSIBLE\n";


    return 0;
}
