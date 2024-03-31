#include <iostream>

using namespace std;

string String1,String2;
int Dynamic[100][100];
int Prev[100][100];

void init(){
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            Dynamic[i][j] = -1;
        }
    }
}

int dfs(int i, int j){
    if (Dynamic[i][j] != -1){
        return Dynamic[i][j];
    }

    if (i < 0 || j < 0){
        return 0;
    }

    if (String1[i] == String2[j]){
        Dynamic[i][j] = dfs(i-1,j-1)+1;
    }else{
        Dynamic[i][j] = max(dfs(i-1,j),dfs(i,j-1));
    }

    return Dynamic[i][j];
}

int main(){

    getline(cin,String1);
    getline(cin,String2);
    init();
    cout << dfs(String1.size()-1,String2.size()-1) << "\n";
    return 0;
}