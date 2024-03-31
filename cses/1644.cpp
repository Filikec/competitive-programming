#include <bits/stdc++.h>


using namespace std;

int main(){

    int n,a,b;
    cin >> n >> a >> b;

    long long best = -1e18;
    long long s=0;
    priority_queue<pair<long long, long long>,vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    list<long long> q = {0};
    for (int i=0;i<a-1;i++){
        long long c;
        cin >> c;
        s += c;
        q.push_back(s);
    }
    int cur=0;
    for (int i=a-1;i<n;i++){
        long long c;
        cin >> c;
        s += c;
        q.push_back(s);
        pq.push({q.front(),cur++});
        q.pop_front();
        while (pq.size() && i-pq.top().second+1 > b) pq.pop();
        best = max(best, s-pq.top().first);
    }

    cout << best << '\n';
    return 0;
}