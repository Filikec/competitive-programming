#include <iostream>
#include <set>

using namespace std;

typedef long long ll;



void work(ll s,ll x, ll y, ll dx, ll dy){
    set<pair<ll,ll>> used;

    pair<ll,ll> cur = {x,y};
    pair<ll,ll> pos = {x/s,y/s};
    bool white = ;
    ll j = 1;
    while (!used.count(cur) && !isOnWhite(cur,s)){
        used.insert(cur);

        cur = {(x+j*dx)%s,(y+j*dy)%s};
        if (isOnWhite(cur)){
            cout << "After " << j << " jumps the flea lands at (" <<  x+j*dx << ", " << y+j*dy << ").\n";
            return;
        }
        j++;
        
    }

    if (isOnWhite(cur,s)){
        cout << "After " << j << " jumps the flea lands at (" <<  x+j*dx << ", " << y+j*dy << ").\n";
        return;
    }


    cout << "The flea cannot escape from black squares.\n";




}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll s,x,y,dx,dy;

    while (cin >> s >> x >> y >> dx >> dy){
        if (s || x || y || dx || dy){
            work(s,x,y,dx,dy);
        }else{
            break;
        }
    }



    return 0;
}

