#include <iostream>
#include <list>
#include <vector>

using namespace std;


int Temps[201];
vector<pair<int,int>> Intervals;

int main(){
    int n;
    cin >> n;

    int maxim = 0;
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        Intervals.push_back({a,b});
        for (int j=a;j<=b;j++){
            Temps[j]++;
        }
        maxim = max(maxim,b);
    }

    int count = 0;
    while (Intervals.size()){
        count++;
        pair<int,int> best = {0,0};
        for (int i=0;i<=maxim;i++){
            if (best.first < Temps[i]) best = {Temps[i],i};
        }
        int tmp = best.second;x
        for (auto it=Intervals.begin();it!=Intervals.end();it++){
            if (it->first > tmp || it->second < tmp) continue;
            for (int j=it->first;j<=it->second;j++){
                Temps[j]--;
            }
            it = prev(it);
            Intervals.erase(next(it));
        }
    }

    cout << count << '\n';
}