#include <iostream>
#include <unordered_set>



using namespace std;

int main(){

    char c;
    string word;
    bool c=0;
    unordered_set<string> commasP,commasS;

    while (c=cin.get()){
        if (c=='.'){
            c = 0;
            word = "";
        }else if(c == ','){
            c = 1;
        }else if(c == '.'){
            c = 0;
        }else{
            word+=c;
        }
    }


    return 0;
}