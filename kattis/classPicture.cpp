#include <iostream>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string,unordered_set<string>> Dislikes;


list<string> getPerm(list<string> &l, list<string> &p){
    if (!l.size()){
        
    }
}
 

int main(){

    int n;

    while (cin >> n){
        Dislikes.clear();
        list<string> names;
        for (int i=0;i<n;i++){
            string tmp;
            cin >> tmp;
            names.push_back(tmp);
        }
        names.sort();

        int m;
        cin >> m;
        for (int i=0;i<m;i++){
            string a,b;
            cin >> a >> b;
            Dislikes[a].insert(b);
            Dislikes[b].insert(a);
        }
        
    }

    return 0;
}