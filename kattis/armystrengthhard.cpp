#include <iostream>
#include <list>
#include <algorithm>

using namespace std;



bool cmp(int a, int b){
    return a < b;
}

void solve(){
    int g,m;
    list<int> Godzilla, Mecha;

    cin >> g >> m;

    for (int i=0;i<g;i++){
        int tmp;
        cin >> tmp;
        Godzilla.push_back(tmp);
    }
    for (int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        Mecha.push_back(tmp);
    }

    Godzilla.sort(cmp);
    Mecha.sort(cmp);

    while (!Godzilla.empty()&&!Mecha.empty()){
        if (Godzilla.front() < Mecha.front()) Godzilla.pop_front();
        else if (Godzilla.front() > Mecha.front()) Mecha.pop_front();
        else Mecha.pop_front();
    }

    if (Mecha.empty()) cout << "Godzilla\n";
    else cout << "MechaGodzilla\n";

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cases;

    cin >> cases;
    for (int c=0;c<cases;c++){
        solve();
    }



    return 0;
}