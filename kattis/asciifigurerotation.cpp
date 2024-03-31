#include <iostream>


using namespace std;


string Sign[100];
string New[100];

void get(string *s){
    char c;
    while ((c=getchar())!='\n'){
        (*s) += c;
    }
}

void solve(int n,int f){
    int maxi = 0;
    getchar();
    for (int i=0;i<100;i++){
        Sign[i].clear();
    }
    for (int i=0;i<n;i++){
        get(&Sign[i]);
        maxi = max(maxi,(int)Sign[i].size());
        for (int j=0;j<Sign[i].size();j++){
            if (Sign[i][j] == '-'){
                Sign[i][j] = '|';
            }else if (Sign[i][j] == '|'){
                Sign[i][j] = '-';
            }
        }
    }   
    
    for (int i=0;i<maxi;i++){
        for (int j=0;j<n;j++){
            if (i < Sign[n-1-j].size()){
                New[i][j] = Sign[n-1-j][i];
            }else{
                New[i][j] = ' ';
            }
        }
    }
    if (f) cout << "\n";
    for (int i=0;i<maxi;i++){
        int j = n-1;  
        while (New[i][j]==' ') New[i][j--]='0';
        for (int j=0;j<n&&New[i][j]!='0';j++){
            cout << New[i][j];
        }
        cout << '\n';
    }
    
}

int main(){

    int n,f=0;

    while (cin >> n){
        if (!n) break;
        solve(n,f);
        f=1;
    }

    return 0;
}

/*
5
 +-+
-+ |
   +-+
 |   |
 +---+
*/