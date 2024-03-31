#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;


int Nums[200000];
list<int> Sorted;
unordered_map<int,int> Map, Cur;

int main(){
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Nums[i];
        Cur[Nums[i]] = i;
        Sorted.push_back(Nums[i]);
    }

    Sorted.sort();

    int ix = 0;
    for (auto el : Sorted) Map[el] = ix++;

    int q;
    cin >> q;
    for (int i=0;i<n&&Cur[q]!=Map[q];i++){
        while (Map[Nums[i]] != i&&Cur[q]!=Map[q]){
            Cur[Nums[i]] = Map[Nums[i]];
            Cur[Nums[Map[Nums[i]]]] = i;
            swap(Nums[i],Nums[Map[Nums[i]]]);
        }
    }

    for (int i=0;i<n;i++) cout << Nums[i] << ' ';
    cout << '\n';
    

    return 0;
}
