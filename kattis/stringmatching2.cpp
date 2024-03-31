#include <iostream>
#include <list>

using namespace std;

string Pattern;
string Text;
list<int> Occurances;

int main(){

    while (getline(cin,Pattern)){
        getline(cin,Text);
        Occurances.clear();
        for (int i=0;i<Text.size();i++){
            if (Text[i] == Pattern[0]){
                int s = 1;
                int f = 1;
                while (s < Pattern.size()){
                    if (Pattern[s] != Text[s+i]){
                        f = 0;
                        break;
                    }
                    s++;
                }
                if (f){
                    Occurances.push_back(i);
                }
            }
        }
        for (auto e : Occurances){
            cout << e << ' ';
        }
        cout << "\n";
    }


    return 0;
}