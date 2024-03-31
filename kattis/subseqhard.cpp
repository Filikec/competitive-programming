
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;



void solve(){
    int n;
    unordered_map<long long,int> Count;

    cin >> n;

    long long sum=0,count=0;
    Count[0] = 1;
    for (int i=0;i<n;i++){
        long long tmp;
        cin >> tmp;
        sum += tmp;
        if (Count.count(sum-47)) count += Count[sum-47];
        Count[sum]++;
    }
    
    cout << count << '\n';

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int cases;

    cin >> cases;
    for (int c=0;c<cases;c++){
        solve();
    }
   
    return 0;
}


