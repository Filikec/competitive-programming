#include <bits/stdc++.h>

using namespace std;

list<int> Encodings;
int Possibilities[26];

typedef struct{
    int letter,  freq;
} Letter;

Letter Letters[26];

bool cmp(Letter a, Letter b){
    return a.freq > b.freq;
}


void preprocess(){
    Possibilities[0] = 1;
    Possibilities[1] = 1;
    Encodings.push_back(1);
    for (int size=2;size<10;size++){
        Possibilities[size] = Possibilities[size-1]+Possibilities[size-2];
        for (int i=0;i<Possibilities[size];i++){
            Encodings.push_back(size*2-1);
        }
    }
}

int main(){
    string s;
    preprocess();

    getline(cin,s);
    
    for (int i=0;i<s.length();i++){
        char c = tolower(s[i]);
        
        if (c >= 'a' && c <= 'z'){
            Letters[c-'a'].freq++;
            Letters[c-'a'].letter = c;
        }
    }

    sort(Letters,Letters+26,cmp);
    
    long long sum = 0;
    long long length = 0;
    for (int i=0;i<26;i++){
        if (!Letters[i].freq) break;
        int first = Encodings.front();
        Encodings.pop_front();
        sum += first*Letters[i].freq;
        length += Letters[i].freq;
    }

    cout << sum+3*(length-1) << "\n";

    return 0;
}