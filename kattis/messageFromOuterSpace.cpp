#include <iostream>
#include <string>
#include <set>


using namespace std;

set<string> Strings;
int D[50001];

int main(){

    string s;

    while (cin >> s){
        if (s=="#") break;
        Strings.insert(s);
    }

    string prev;
    while (cin >> s){
        if (s=="#") break;
        
        prev += s;
        
        if (s.back() == '|'){
            prev.pop_back();
        }else{
            continue;
        }
        
        D[0] = 0;
        for (int i=0;i<prev.size();i++){
            if (i) D[i] = D[i-1];
            for (auto l : Strings){
                int size = l.size();    
                if (i-size+1>=0){
                    if (prev.substr(i-size+1,l.size()) == l){
                        int prev = 0;
                        if (i-size>=0){
                            prev = D[i-size];
                        }
                        D[i] = max(D[i],prev+1);
                    }
                }
            }
        }
        cout << D[prev.size()-1] << '\n';
        prev = "";
    }




    return 0;
}