#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    
    int n;
    
    cin >> n;
    
    unordered_set<string> Assumptions;
    
    Assumptions.insert("");

    for (int i=0;i<n;i++){
        string s="";

        
        while (s != "->"){
            if (!Assumptions.count(s)){
                cout << i+1 << "\n";
                return 0;
            }
            cin >> s;
        }
        
        cin >> s;
        
        Assumptions.insert(s);
    }
    
    cout << "correct\n";
    
    return 0;
}