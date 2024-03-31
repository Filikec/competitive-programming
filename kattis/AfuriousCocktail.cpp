#include <iostream>
#include <algorithm>
#include <list>


using namespace std;


int main(){

    int n,t;


    cin >> n >> t;


    list<int> Potions;

    for (int i=0;i<n;i++){
        int tmp;
        cin>> tmp;

        Potions.push_back(tmp);
    }

    Potions.sort([&](int a, int b){return a>b;});


    int cur = 1000001;

    for (auto p : Potions){
        cur -= t;
        cur = min(cur,p);
    }

    if (cur > 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }


    return 0;
}
