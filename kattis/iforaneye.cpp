#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string,string> Replaces;

void preprocess(){
    Replaces.insert({"at","@"});
    Replaces.insert({"and","&"});
    Replaces.insert({"one","1"});
    Replaces.insert({"won","1"});
    Replaces.insert({"to","2"});
    Replaces.insert({"too","2"});
    Replaces.insert({"two","2"});
    Replaces.insert({"for","4"});
    Replaces.insert({"four","4"});
    Replaces.insert({"be","b"});
    Replaces.insert({"bea","b"});
    Replaces.insert({"bee","b"});
    Replaces.insert({"see","c"});
    Replaces.insert({"sea","c"});
    Replaces.insert({"eye","i"});
    Replaces.insert({"oh","o"});
    Replaces.insert({"owe","o"});
    Replaces.insert({"are","r"});
    Replaces.insert({"you","u"});
    Replaces.insert({"why","y"});
}

void solve(){
    string line,new_line;
    
    getline(cin,line);

    for (int i=0;i<line.size();i++){
        string cur="",sub="";
        int skip=0;
        for (int j=i;j<line.size()&&j<i+2;j++){
            char c = line[j];
            if (c>='A'&&c<='Z'){
                c = c-'A'+'a';
            }
            cur += c;
        }
        if (Replaces.count(cur)){
            sub = Replaces[cur];
            skip = 1;
        }
        if (i+2<line.size()){
            cur += line[i+2];
            if (Replaces.count(cur)){
                sub = Replaces[cur];
                skip = 2;
            }
        }
        if (i+3<line.size()){
            cur += line[i+3];
            if (Replaces.count(cur)){
                sub = Replaces[cur];
                skip = 3;
            }
        }
        if (sub==""){
            new_line += line[i];
        }else{
            if (line[i]>='A'&&line[i]<='Z' && sub[0]>='a'&&sub[0]<='z'){
                sub[0] = sub[0]-'a'+'A';
            }
            new_line+=sub;
            i += skip;
        }
    }
    cout << new_line << '\n';
}

int main(){

    
    preprocess();

    int n;

    cin >> n;
    cin.get();  
    for (int i=0;i<n;i++){
        solve();
    }





    return 0;
}