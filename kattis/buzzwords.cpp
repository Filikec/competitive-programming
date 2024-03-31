#include <iostream>
#include <map>

using namespace std;


void solve(string *s){
    for (int l=1;l<=s->size();l++){
        map<string,int> Dict;
        for (int i=0;i+l<=s->size();i++){
            string word;
            for (int w=0;w<l;w++){
                word += s->at(i+w);
            }
            if (Dict.count(word)){
                Dict[word]++;
            }else{
                Dict[word] = 1;
            }
        }
        int biggest = 0;
        for (auto e : Dict){
            if (e.second > biggest){
                biggest = e.second;
            }
        }
        if (biggest > 1){
            cout << biggest << '\n';
        }else{
            break;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    while (true){
        string line="";
        char c;
        while ((c=getchar())!='\n'){
            if (c!=' ') line+=c;
        }
        if (line=="") break;
        solve(&line);
        cout << '\n';

    }




    return 0;
}