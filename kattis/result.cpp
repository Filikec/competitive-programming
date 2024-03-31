#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> Numbers, Expressions;

long long Dynamic_max[100][100], Dynamic_min[100][100];

long long dfs_max(int i, int j){
    if (i==j){
        return Numbers[i];
    }

    if (Dynamic_max[i][j] != -1){
        return Dynamic_max[i][j];
    }

    long long ret = 0;

    for (int k=i;k<j;k++){
        if (Expressions[k] == '+'){
            ret = max(ret,dfs_max(i,k)+dfs_max(k+1,j));
        }else{
            ret = max(ret,dfs_max(i,k)*dfs_max(k+1,j));
        }
    }

    Dynamic_max[i][j] = ret;

    return ret;
}

long long dfs_min(int i, int j){

    if (i==j){
        return Numbers[i];
    }

    if (Dynamic_min[i][j] != -1){
        return Dynamic_min[i][j];
    }

    long long ret = LLONG_MAX;

    for (int k=i;k<j;k++){
        if (Expressions[k] == '+'){
            ret = min(ret,dfs_min(i,k)+dfs_min(k+1,j));
        }else{
            ret = min(ret,dfs_min(i,k)*dfs_min(k+1,j));
        }
    }

    Dynamic_min[i][j] = ret;

    return ret;
}

void init(){
    for (int i=0;i<99;i++){
        for (int j=0;j<99;j++){
            Dynamic_max[i][j] = -1;
            Dynamic_min[i][j] = -1;
        }
    }
    Expressions.clear();
    Numbers.clear();
}

bool get_expression(){
    char c;
    int num = 0;
    while ((c=getchar())!='\n'){
        if (c=='E'){
            return false;
        }
        if (c=='+'||c=='*'){
            Numbers.push_back(num);
            Expressions.push_back(c);
            num = 0;
        }else{
            num = num*10+(c-'0');
        }
    }
    Numbers.push_back(num);
    return true;
}

int main(){
    init();
    while (get_expression()){
        cout << dfs_min(0,Numbers.size()-1) << " " <<  dfs_max(0,Numbers.size()-1) << "\n";
        init();
    }   

    return 0;
}