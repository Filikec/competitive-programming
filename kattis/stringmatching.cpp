#include <iostream>
#include <vector>
#include <list>

using namespace std;

string Pattern;
string Text;
vector<int> Index;
list<int> Occurances;

void get_indexes(){
    Index[0] = 0;
    for (int i=1;i<Pattern.size();i++){
        if (Pattern[i] == Pattern[Index[i-1]]){
            Index[i] = Index[i-1]+1;
        }else{
            Index[i] = 0;
        }
    }
}

void get_file(){
    char c;
    while ((c=getchar())!=EOF){
        Text.push_back(c);
    }
}

int main(){
    int r = 0;
    Index.reserve(100000);

    getline(cin,Pattern);
    get_indexes();
    get_file();

    int p = 0;
    for (int i=0;i<Text.size();){
        while (p < Pattern.size() && Text[i+p] == Pattern[p]){
            p++;
        }
        if (p==Pattern.size()){
            r++;
        }
        if(p){
            i += p-Index[p-1];
            p = Index[p-1];
        }else{
            i++;
            p = 0;
        }
    }
    cout << r <<"\n";

    
    
    
    return 0;
}