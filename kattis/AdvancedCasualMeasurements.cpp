#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define INF 2000000

typedef long long ll;


pair<ll,ll> addPoint(pair<ll,ll> p, ll t){
    return {t,p.first-t+p.second};
}

bool covers(pair<ll,ll> c, pair<ll,ll> e){
    return e.first>=c.first+abs(c.second-e.second);
}

bool possible(ll t, vector<pair<ll,ll>> &points, ll m){
    pair<ll,ll> cause = addPoint(points.front(),t);
    int count = 1;
    for (auto e : points){
        if (!covers(cause,e)){
            if (e.second < cause.second){
                cause = addPoint(e,t);
                continue;
            }
            count++;
            if (count > m) return false;
            cause = addPoint(e,t);
        }
    }
    return true;
}

void work(ll caseN){
    ll n,m;
    cin >> n >> m;

    vector<pair<ll,ll>> points;

    ll smallest = INF;
    for (ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        points.push_back({a,b});
        smallest = min(smallest,a);
    }

    sort(points.begin(), points.end(), [&](pair<ll,ll> a, pair<ll,ll> b){return a.second < b.second;});

    ll lo=-INF,hi=smallest;

    while (lo<hi){
        ll mid = ceil((lo+hi)/2.0);
        if (possible(mid,points,m)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }

    cout << "Case " << caseN << ": " << lo << '\n';
}

int main(){
    ll t;
    cin >> t;
    for (ll i=0;i<t;i++) work(i+1);
}