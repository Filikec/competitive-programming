#include <bits/stdc++.h>

using namespace std;


bool pos(long long mid, list<long long> l, long long k){
    long long count=1;
    long long sum = 0;
    while (l.size()){
        if (sum + l.front() > mid){
            count++;
            sum=0;
        }else{
            sum += l.front();
            l.pop_front();
        }
    }
    return count <= k;
}

int main(){

    int n,k;
    cin >> n >> k;

    list<long long> l;
    for (int i=0;i<n;i++) {
        long long c;
        cin >> c;
        l.push_back(c);
    } 

    
    long long lo,hi;
    lo = *max_element(l.begin(),l.end()), hi = 1e15;
    while (lo<hi){
        long long mid = (lo+hi)/2;
        if (pos(mid,l,k)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << '\n';

    return 0;
}