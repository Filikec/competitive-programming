#include <iostream>
#include <unordered_map>

using namespace std;


unordered_map<string,int> Votes;


int main(){
    string s;

    while (getline(cin,s)){
        if (s=="***") break;
        Votes[s]++;
    }

    int most = 0, same = 0;
    string voter;
    for (auto name:Votes){
        if (name.second>most){
            most = name.second;
            voter = name.first;
        }else if (name.second==most){
            same = 1;
            voter = "Runoff!";
        }
    }

    cout << voter << "\n";

}