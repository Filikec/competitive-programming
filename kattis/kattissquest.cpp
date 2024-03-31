#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> Heaps[100001];

bool cmp(int a, int b){
    return a < b;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        if (s == "add"){
            long long e, g;
            cin >> e >> g;
            
            Heaps[e].push_back(g);
            push_heap(Heaps[e].begin(),Heaps[e].end(),cmp);
        }else{
            long long energy,gold=0,dif=0;
            cin >> energy;
            while (energy-dif>-1){
                
                if (Heaps[energy-dif].size()){
                    int tmp = Heaps[energy-dif].front();
                    pop_heap(Heaps[energy-dif].begin(),Heaps[energy-dif].end(),cmp);
                    Heaps[energy-dif].pop_back();
                    energy -= energy-dif;
                    gold += tmp;
                    dif=0;
                }else{
                    dif++;
                }
            }
            cout << gold << '\n';
        }
    }

    return 0;
}