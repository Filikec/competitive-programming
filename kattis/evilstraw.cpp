#include <iostream>
#include <unordered_map>

using namespace std;

void work(){

    unordered_map<char,int> Map;


    string s;

    cin >> s;

    for (auto c : s){
        if (Map.count(c)) Map[c]++;
        else Map[c]=1;
    }

    int once = 0;
    for (auto p : Map){
        
        if (p.second%2==0){
            ;
        }
        else{
            if (once++){
                cout << "impossible\n";
                return;
            }
        }
    }

    cout << s.size()*s.size() << '\n';

}


int main(){

    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++) work();


    return 0;
}