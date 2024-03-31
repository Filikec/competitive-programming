#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef long long ll;


void work(){
    ll n,a,b,c,x,y;
    cin >> n >> a >> b >> c >> x >> y;

    list<ll> nums;
    nums.push_back(a);
    for (int i=1;i<n;i++){
        ll cur = (nums.back()*b+a)%c;
        nums.push_back(cur);
    }
    nums.sort();

    ll v=0;
    for (ll num : nums){
        v = (v*x + num) % y;
    }

    cout << v << "\n";
}

int main(){
    int tc;
    
    cin >> tc;
    
    for (int i=0;i<tc;i++) work();

    return 0;
}