#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for (auto &c : v) scanf("%d",&c);;
    sort(v.begin(),v.end());

    int q,t;
    scanf("%d",&q);
    while (q--){
        scanf("%d",&t);
        printf("%lld\n",distance(v.begin(),prev(upper_bound(v.begin(),v.end(),t)))+1);
    } 

    return 0;
}