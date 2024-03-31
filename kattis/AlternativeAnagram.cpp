#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_set<string> used;
unordered_map<char,int> uc;

int main(){
    string n;

    cin >> n;
    for (auto c : n) uc[c]++;
    if (uc.size() == 1){
        cout << "-1\n";
        return 0;
    }
    sort(n.begin(),n.end());
    
    if (uc[n.front()] > n.size()/2){
        swap(n.back(),n[n.size()/2-1]);
    }else{
        swap(n.front(),n[n.size()/2-1]);
    }
    
    
    cout << n << '\n';

    return 0;
}