#include <bits/stdc++.h>

using namespace std;



#define MOD 1000000000

typedef unsigned long long ull;
ull Dynamic[300][301];
int N;
string Line;

int get_possible(int i, int j){
    if (Line[i] == '?'){
        if (Line[j] == '?'){
            return 3;
        }else{
            return Line[j] == '}' || Line[j] == ')' || Line[j] == ']';
        }
    }else if (Line[j] == '?'){
        return Line[i] == '{' || Line[i] == '(' || Line[i] == '[';
    }else if (Line[i] == '('){
        return Line[j] == ')';
    }else if (Line[i] == '{'){
        return Line[j] == '}';
    }else if (Line[i] == '['){
        return Line[j] == ']';
    }else{
        return 0;
    }
}

int main(){


    cin >> N;
    getchar();
    getline(cin,Line);

    for (int i=0;i<=N;i++){
        Dynamic[i][0] = 1;
    }

    int big = 0;

    for (int i=2;i<=N;i+=2){
        for (int j=0;j+i<=N;j++){
            ull result = 0;
            for (int k=j+1;k<j+i;k++){
                result += get_possible(j,k)*(Dynamic[j+1][k-(j+1)]*Dynamic[k+1][i-(k-j+1)]); 
                big = max(big,(int)log10(result));
            }
            Dynamic[j][i] = result%100000;
        }
    }

    list<int> num;

    int result = Dynamic[0][N];
    while (result){
        num.push_front(result%10);
        result /= 10;
    }
    while (num.size()<min(big,5)){
        num.push_front(0);
    }

    for (auto d : num){
        cout << d;
    }
    cout << '\n';

    return 0;
}