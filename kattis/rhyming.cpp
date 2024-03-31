#include <iostream>
#include <list>

using namespace std;



list<list<string>> Ends;
list<string> Results;
string Word;

bool has_end(string *w,string *end){
    int w_i = w->size()-1;
    int e_i = end->size()-1;
    
    while (w_i && e_i){
        if (w->at(w_i--) != end->at(e_i--)) return false;
    }

    return true;
}

void get_line(){
    char c;
    bool f = false;
    list<string> add;
    string curr;
    getchar();
    while (true){
        c = getchar();
        if (c == '\n') break;
        if (c == ' '){
            add.push_back(curr);
            if (!f && has_end(&Word,&curr)) f = true;
            curr.clear();
        }else{
            curr += c;
        }
    }
   
    add.push_back(curr);

    if (f){
        while (!add.empty()){
            Results.push_back(add.front());
            add.pop_front();
        }
    }else{
        Ends.push_back(add);
    }
    
    
}

int main(){
    cin >> Word;

    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        get_line();
    }
    
    bool f = false;
    while (!f){
        f = true;
        for (auto it = Ends.begin(); it != Ends.end(); it++){
            for (auto end1 : (*it)){
                for (auto end2 : Results){
                    if (has_end(&end1,&end2)){
                        f = false;
                        break;
                    }
                }
                if (!f) break;
            }
            if (!f){
                for (auto e : (*it)){
                    Results.push_back(e);
                }
                Ends.erase(it);
                break;
            }
        }
    }

    int cas;

    cin >> cas;
    getchar();
    for (int i=0;i<cas;i++){
        bool f = false;
        string line;
        getline(cin,line);
        for (auto end : Results){
            if (has_end(&line,&end)){
                f = true;
                break;
            }
        }
        if (f){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }


    return 0;
}

/*
drought
3
aught ought aut acht
ought oubt outte out oute
ears oute
5
tasty sprout
difficult route
worried and fraught
forever in doubt
apples and pears


*/