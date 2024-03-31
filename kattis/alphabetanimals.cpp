#include <iostream>
#include <set>
#include <list>

using namespace std;

int Animals[27];
list<string> Animals_list;

int main(){
    int n;
    string before;
    cin >> before;
    char b = before.back();
    cin >> n;

    for (int i=0;i<n;i++){
        string animal;
        cin >> animal;
        Animals[animal.front()-'a']++;
        Animals_list.push_back(animal);
    }
    string first = "?";
    for (auto a : Animals_list){
        if (a.front() == b){
            if (first == "?") first = a;
            if (!Animals[a.back()-'a'] || (a.back() == a.front() && Animals[a.back()-'a']==1)){
                cout << a << "!\n";
                return 0;
            }
        }
    }

    cout << first << "\n";
    
    return 0;
}
