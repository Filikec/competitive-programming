    #include <bits/stdc++.h>

    using namespace std;

    int main(){

        int n,x;
        cin >> n >> x;

        map<long long,long long> m = {{0,1}};

        long long ans=0,s=0;
        for (int i=0;i<n;i++){
            long long c;
            cin >> c;
            s += c;
            ans += m[s-x];
            m[s]++;
        }

        cout << ans << '\n';

        return 0;
    }