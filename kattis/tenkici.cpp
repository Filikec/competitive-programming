#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;


typedef struct tank{
    int row, col, num;
} Tank;

Tank Tanks[500];
int Rows[501], Cols[501], Past[500][501][501];
list<string> Directions;
list<int> Rows_more, Cols_more;
int Moves,N;

bool check(){
    for (int i=1;i<=N;i++){
        if (Rows[i]>1||Cols[i]>1) return false;
    }
    
    return true;
}

void fix(){
    while (!check()){
        for (int i=0;i<N;i++){
            int r,c;
            r = Tanks[i].row;
            c = Tanks[i].col;

            if (r+1 <= N && !Rows[r+1] && !Past[i][r+1][c]){
                Past[i][r][c] = 1;
                Rows[r+1]++;
                Rows[r]--;
                Moves++;
                Tanks[i].row++;
                cout << i+1 << " " << "D\n";
            }else if (r-1 >= 1 && !Rows[r-1] && !Past[i][r-1][c]){
                Past[i][r][c] = 1;
                Rows[r-1]++;
                Rows[r]--;
                Moves++;
                Tanks[i].row--;
                cout << i+1 << " " << "U\n";
            }else if (c+1 <= N && !Cols[c+1] && !Past[i][r][c+1]){
                Past[i][r][c] = 1;
                Cols[c+1]++;
                Cols[c]--;
                Moves++;
                Tanks[i].col++;
                cout << i+1 << " " << "R\n";
            }else if (c-1 >= 1 && !Cols[c-1] && !Past[i][r][c-1]){
                Past[i][r][c] = 1;
                Cols[c-1]++;
                Cols[c]--;
                Moves++;
                Tanks[i].col--;
                cout << i+1 << " " << "L\n";
            }
        }
    }
    cout << Moves << "\n";
}

int main(){
    cin >> N;

    for (int i=0;i<N;i++){
        cin >> Tanks[i].row >> Tanks[i].col;

        Rows[Tanks[i].row]++;
        Cols[Tanks[i].col]++;
    }


    fix();

    return 0;
}
