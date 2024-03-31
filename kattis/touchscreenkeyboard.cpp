#include <iostream>
#include <list>

using namespace std;


string Keyboard[3] = {"qwertyuiop","asdfghjkl ","zxcvbnm   "};

int get_len(char c1, char c2){
    pair<int,int> pos1,pos2;
    for (int i=0;i<3;i++){
        for (int j=0;j<10;j++){
            if (Keyboard[i][j] == c1){
                pos1 = {i,j};
            }
            if (Keyboard[i][j] == c2){
                pos2 = {i,j};
            }
        }
    }

    return abs(pos1.first-pos2.first) + abs(pos1.second-pos2.second);
}

int get_len_word(string s1, string s2){
    int l = 0;
    for (int i=0;i<s1.size();i++){
        l += get_len(s1[i],s2[i]);
    }
    return l;
}


bool cmp(pair<string,int> a,pair<string,int> b){
    if (a.second < b.second){
        return true;
    }else if (a.second == b.second){
        return a.first<b.first;
    }
    return false;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cases;

    cin >> cases;

    for (int i=0;i<cases;++i){
        string word;
        int matches;
        cin >> word >> matches;
        list<pair<string,int>> m;
        for (int j=0;j<matches;j++){
            string ma;
            cin >> ma;
            m.push_back({ma,get_len_word(word,ma)});
        }
        m.sort(cmp);
        for (auto e : m){
            cout << e.first << ' ' << e.second << "\n";
        }
    }



    return 0;
}