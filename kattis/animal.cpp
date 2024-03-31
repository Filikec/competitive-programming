#include <iostream>
#include <unordered_set>
#include <list>

using namespace std;

unordered_set<string> Subsets;
int Count,Used;

void parse_tree(string *line){
    int right=0,left,index=0;

    while (line->at(index) != ')'){
        index++;
    }

    left = right-1;
}

int main(){
    int n, index=0;
    cin >> n;
    getchar();
    string s;
    getline(cin,s);
    parse_tree(&s);



    cout << Count+n << '\n';

    return 0;
}
