#include <iostream>
#include <cmath>
#include <list>

using namespace std;


int Dynamic[100001], Prev[100001], Nums[100001];
int N,L;



void solve(){
    L=0;
    
    for (int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        Nums[i] = tmp;

        int lo=0,hi=L;

        while (lo<hi){
            int search = ceil((lo+hi)/2.0);
            if (Nums[Dynamic[search]] < tmp){
                lo = search;
            }else{
                hi = search-1;
            }
        }

        if (Nums[Dynamic[lo+1]] > tmp || lo+1 > L){
            Dynamic[lo+1] = i;
            Prev[i] = Dynamic[lo];
            if (lo+1>L){
                L = lo+1;
            }
        }   
    }
    int curr = Dynamic[L];
    list<int> stack;
    while (curr!=-1){
        stack.push_front(curr);
        curr = Prev[curr];
    }
    cout << stack.size() << "\n";
    for (auto e : stack){
        cout << e << ' ';
    }

    cout << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Dynamic[0] = -1;

    
    while (cin>>N){
        solve();
    }




    return 0;
}