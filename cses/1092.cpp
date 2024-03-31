#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long all = n*(n+1)/2;
    
    if (all%2){
        cout << "NO\n";
        return 0;
    }

    long long c=1;
    long long sum=0;
    set<long long> l;
    while (sum < all/2) l.insert(c), sum += c++;
    l.erase(sum-all/2);
    
    cout << "YES\n";
    cout << l.size() << '\n';
    for (int i=1;i<=n;i++) if (l.contains(i)) cout << i << ' ';
    cout << '\n';
    cout << n-l.size() << '\n';
    for (int i=1;i<=n;i++) if (!l.contains(i)) cout << i << ' ';
    cout << '\n';

    return 0;
}