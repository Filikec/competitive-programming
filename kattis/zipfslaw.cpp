#include <iostream>
#include <map>
#include <ctype.h>
#include <list>
using namespace std;


void solve(int n){
    map<string,int> dict;
    list<string> result;
    string s;
    string name = "";
    
    while(getline(cin,s)){
        name = "";
        if (s == "EndOfText"){
            break;
        }
        for (auto c : s){
            c = tolower(c);

            if (isalpha(c)){
                name += c;
            }else if (name == ""){
                continue;
            }else if (dict.find(name) == dict.end()){
                dict.insert(make_pair(name,1));
                name = "";
            }else{
                dict[name]++;
                name = "";
            }
        }
        if (name == ""){
            continue;
        }else if (dict.find(name) == dict.end()){
            dict.insert(make_pair(name,1));
        }else{
            dict[name]++;
        }

    }

    for (auto s : dict){
        if (s.second == n){
            result.push_front(s.first);
        }
    }
    if (result.empty()){
        cout << "There is no such word.\n";
        return;
    } 

    result.sort();
    while (!result.empty()){
        cout << result.front() << "\n";
        result.pop_front();
    }
}

int main(){
    int n;
    while (true){
        cin >> n;
        if (cin.eof()){
            break;
        }
        solve(n);
    }
    
    return 0;
}