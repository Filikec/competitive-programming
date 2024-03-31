#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


void work(){
    int n;
    cin >> n;
    char t;
    cin >> t;

    ll trump = t-'A';
    map<ll,list<ll>> suits;

    for (int i=0;i<2*n;i++){
        char a,b;
        cin >> a >> b;
        suits[b-'A'].push_back(a-'0');
    }

    for (auto &p : suits) p.second.sort();

    list<pair<pll,pll>> rounds;
    bool impossible = false;
    for (auto &p : suits){
        if (p.first == trump) continue;
        if (p.second.size()%2){
            if (!suits[trump].size()){
                impossible = true;
                break;
            }
            rounds.push_back({{p.second.back(),p.first},{suits[trump].front(),trump}});
            suits[trump].pop_front();
            p.second.pop_back();
        }    

        for (auto it = p.second.begin(); it != p.second.end(); it++){
            rounds.push_back({{*it,p.first},{*next(it),p.first}});
            it++;
        }   
    }
    if (suits[trump].size()%2) impossible = true;
    else{
        for (auto it = suits[trump].begin(); it != suits[trump].end(); it++){
            rounds.push_back({{*it,trump},{*next(it),trump}});
            it++;
        }
    }

    if (impossible){
        cout << "IMPOSSIBLE\n";
    }else{
        for (auto r : rounds){
            cout << (char)(r.first.first+'0') << (char)(r.first.second+'A') << ' ' << (char)(r.second.first+'0') << (char)(r.second.second+'A') << '\n';
        }
    }

}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}