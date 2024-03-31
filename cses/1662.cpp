    #include <bits/stdc++.h>

    using namespace std;

    int main(){

        int n,x;
        cin >> n >> x;
        set<long long> u;
        vector<long long> d = {0};
        long long ans=0,s=0;
        for (int i=0;i<n;i++){
            long long c;
            cin >> c;
            u.insert(c);
            d.push_back(u.size());
            int b = lower_bound(v.begin(),v.end(),max(u.size()-x));
        }

        cout << ans << '\n';

        return 0;
    }