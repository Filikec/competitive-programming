#include <iostream>
#include <unordered_set>

using namespace std;

string Tones[] = {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
unordered_set<string> Sets[12];
int Bad[12];

void prepare(){
    for (int i=0;i<12;i++){
        Sets[i].insert(Tones[i]);
        Sets[i].insert(Tones[(i+2)%12]);
        Sets[i].insert(Tones[(i+4)%12]);
        Sets[i].insert(Tones[(i+5)%12]);
        Sets[i].insert(Tones[(i+7)%12]);
        Sets[i].insert(Tones[(i+9)%12]);
        Sets[i].insert(Tones[(i+11)%12]);
    }
}

int main(){
    int n;
    cin >> n;

    prepare();

    for (int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        for (int i=0;i<12;i++){
            if (!Sets[i].count(tmp)) Bad[i]=1;
        }
    }
    bool f = false;
    for (int i=0;i<12;i++){
        if (!Bad[i]) cout << Tones[i] << " ", f=true;
    }
    if(!f) cout << "none";
    cout << "\n";

    return 0;
}