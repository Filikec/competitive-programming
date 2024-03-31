#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> Numbers;

int main(){
    int cases;
    cin >> cases;
    for (int c=0;c<cases;c++){
        Numbers.clear();
        int n, flag = 0;
        string number;
        cin >> n;
        getchar();
        for (int i=0;i<n;i++){
            getline(cin,number);
            Numbers.insert(number);
        }
        for (auto s : Numbers){
            string cmp = "";
            for (int i=0;i<s.size()-1;i++){
                cmp += s[i];
                if (Numbers.count(cmp)){
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        
        if (!flag){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

}