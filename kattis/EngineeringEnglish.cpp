#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    unordered_set<string> dic;

    while (cin>>word){
        string data;
        data = word;
        std::transform(data.begin(), data.end(), data.begin(), ::tolower);
        if (dic.count(data)){
            cout<<". ";
        }else{
            dic.insert(data);
            cout << word << ' ';
        }
    }


    return 0;
}