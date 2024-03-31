#include <iostream>
#include <unordered_set>

using namespace std;

int main(){

    int p,n;


    cin >> p >> n;
    
    unordered_set<string> parts;
    for (int i=0;i<n;i++){
        string w;

        cin>>w;

        parts.insert(w);
        if (parts.size() == p){
            cout << i+1 << '\n';
            return 0;
        }
    }

    cout << "paradox avoided\n";

    return 0;
}