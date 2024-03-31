#include <bits/stdc++.h>


using namespace std;

char and_(char a, char b){
    if (a == '0' || b == '0') return '0';
    
    if (a == '?' || b == '?') return '?';

    return '1';
}

char or_(char a, char b){
    if (a == '1' || b == '1') return '1';
    
    if (a == '?' || b == '?') return '?';

    return '0';
}

bool work(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    
    if (!n) return false;

    char mem[32];

    for (int i=0;i<32;i++){
        mem[i] = '?';
    }

    for (int i=0;i<n;i++){
        string s;
        int index;
        cin >> s >> index;
        index = 31 - index;
        if (s == "SET"){
            mem[index] = '1';
        }else if (s == "CLEAR"){
            mem[index] = '0';
        }else{
            int index2;
            cin >> index2;
            index2 = 31 - index2;
            if (s == "AND"){
                mem[index] = and_(mem[index],mem[index2]);
            }else{
                mem[index] = or_(mem[index],mem[index2]);
            }
        }
    }

    for (int i=0;i<32;i++){
        cout << mem[i];
    }
    cout << '\n';

    return true;
}

int main(){

    while (work()) ;

    return 0;
}