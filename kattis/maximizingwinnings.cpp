#include <iostream>

#define INF 2147483647

using namespace std;


int Board[50][50], Maxi[50][5001], Mini[50][5001], Visited[50][5001];


int get_int(){
    int num=0;
    char c;

    while ((c=getchar())>='0'){
        num = num*10+c-'0';
    }
    return num;
}   
void solve(int n){
    int maximum = 0, minimum = INF;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            Board[i][j] = get_int();
        }
    }
    int turns;
    turns = get_int();
    if (!turns){
        cout << "0 0\n";
    }
    for (int i=0;i<n;i++){
        for (int j=1;j<=turns;j++){
            Maxi[i][j] = 0;
            Mini[i][j] = INF;
            Visited[i][j] = 0;
        }
    }

    Visited[0][0] = 1;
    Maxi[0][0] = 0;
    Mini[0][0] = 0;

    for (int t=1;t<=turns;t++){
        maximum = 0, minimum = INF;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (Visited[j][t-1]){
                    Maxi[i][t] = max(Maxi[i][t],Maxi[j][t-1]+Board[j][i]);
                    Mini[i][t] = min(Mini[i][t],Mini[j][t-1]+Board[j][i]);
                    Visited[i][t] = 1;
                }
            }
            maximum = max(maximum,Maxi[i][t]);
            minimum = min(minimum,Mini[i][t]);
        }
    }
    printf("%d %d\n",maximum,minimum);
}

int main(){
    int n;

    while ((n=get_int())){
        solve(n);
    }


    return 0;
}