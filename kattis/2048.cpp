#include <iostream>

using namespace std;

int Board[4][4];

int main(){

    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            cin >> Board[i][j];
        }
    }
    int d;
    cin >> d;
    
    if (!d){
        for (int i=0;i<4;i++){
            for (int j=1;j<4;j++){
                int curr = j;
                while (curr-1>=0&&!Board[i][curr-1]){
                    Board[i][curr-1] = Board[i][curr];
                    Board[i][curr] = 0;
                    curr--;
                }
                if (curr-1 >= 0 && Board[i][curr-1]==Board[i][curr]){
                    Board[i][curr] = 0;
                    Board[i][curr-1] *= 2;
                }
            }
        }
    }else if (d==1){
        for (int i=0;i<4;i++){
            for (int j=1;j<4;j++){
                int curr = j;
                while (curr-1>=0&&!Board[curr-1][i]){
                    Board[curr-1][i] = Board[curr][i];
                    Board[curr][i] = 0;
                    curr--;
                }
                if (curr-1 >= 0 && Board[curr-1][i]==Board[curr][i]){
                    Board[curr][i] = 0;
                    Board[curr-1][i] *= 2;
                }
            }
        }
    }else if (d==2){
        for (int i=0;i<4;i++){
            for (int j=3;j>=0;j--){
                int curr = j;
                while (curr+1<4&&!Board[i][curr+1]){
                    Board[i][curr+1] = Board[i][curr];
                    Board[i][curr] = 0;
                    curr++;
                }
                if (curr+1 < 4 && Board[i][curr+1]==Board[i][curr]){
                    Board[i][curr] = 0;
                    Board[i][curr+1] *= 2;
                }
            }
        }

    }else{
        for (int i=0;i<4;i++){
            for (int j=3;j>=0;j--){
                int curr = j;
                while (curr+1<4&&!Board[curr+1][i]){
                    Board[curr+1][i] = Board[curr][i];
                    Board[curr][i] = 0;
                    curr++;
                }
                if (curr+1<4 && Board[curr+1][i]==Board[curr][i]){
                    Board[curr][i] = 0;
                    Board[curr+1][i] *= 2;
                }
            }
        }
    }


    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            cout << Board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}