#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string,int> M;

int main(){

    int n,m;
    cin >> n >> m;

    int best = 1e9;

    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        M[s]++;
    }

    for (auto p : M) best = min(best,p.second);

    cout << n-best << '\n';



    return 0;
}