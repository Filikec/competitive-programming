#include <bits/stdc++.h>

using namespace std;


string Dynamic[41][16001];
pair<int,int> Prev[41][16001];
string Strings[40];


bool le(string *a, string *b){ // a <= b
    for (int i=0;i<a->size();i++){
        if (a->at(i) > b->at(i)) return false;
        if (b->at(i) > a->at(i)) return true;
    }
    return true;
}

string replace_digit(string *s, string *r, int p){
    for (int i=0;i<s->size();i++){
        if (s->at(i) != '0'){
            s->at(i) = '0';
            return true;
        }
    }
    return false;
}

int get_smallest_bigger(string &a, string &b){
    for ()
}

int main(){

    int n, l;
    
    cin >> n >> l;


    for (int i=0;i<41;i++){
        for (int j=0;j<16001;j++){
            Prev[i][j] = make_pair(-1,-1);
        }
    }

    for (int i=0;i<n;i++){
        cin >> Strings[i];
    }

    Dynamic[1][0] = Strings[0];
    int i = 1;
    while (replace_digit(&Strings[0])){
        Dynamic[1][i++] = Strings[0];
    }


    for (int i=2;i<=n;i++){
        for (int j=0;j<=16000;j++){
            if (Dynamic[i-1][j] == "") continue;
            string copy = Strings[i-1];
            if (le(&Dynamic[i-1][j],&copy)){
                Dynamic[i][j] = copy;
                Prev[i][j] = make_pair(i-1,j);
            }
            
            int k = j+1;
            while (replace_digit(&copy)){
                if (le(&Dynamic[i-1][j],&copy)){
                    Dynamic[i][k] = copy;
                    Prev[i][k] = make_pair(i-1,j);
                }
                k++;
            } 
        }
    }
    
    for (int i=1;i<=n;i++){
        for (int j=0;j<50;j++){
            if (Dynamic[i][j] != ""){
                cout << i << ' ' << j << ' ' <<  Dynamic[i][j] << "<<\n";
            }
        }
    }


    return 0;
}