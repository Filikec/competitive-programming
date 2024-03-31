#include <iostream>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    
    unordered_map<string,int> Dict;
    unordered_map<int,string> Word;

    while (cin >> s){
        if (s == "def"){
            string v;
            int n;
            cin >> v >> n;
            if (Dict.count(v)) Word.erase(Dict[v]);
            Dict[v] = n;
            Word[n] = v;
        }else if (s == "calc"){
            string c;
            int sum = 0, sign = 1; //0 - minus
            bool f = false;
            while (true){
                cin >> c;
                cout << c << " ";
                if (c == "=") break;
                if (c == "-"){
                    sign = 0;
                }else if (c == "+"){
                    sign = 1;
                }else if (Dict.count(c)){
                    if (sign){
                        sum += Dict[c];
                    }else{
                        sum -= Dict[c];
                    }
                }else{
                    f = true;
                }
            }
            if (f || !Word.count(sum)){
                cout << "unknown\n";
            }else{
                cout <<  Word[sum] << "\n";
            }
        }else{
            Dict.clear();
            Word.clear();
        }
    }



    return 0;
}
