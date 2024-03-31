#include <iostream>
#include <list>

using namespace std;

int Rows[1000000];
int Cols[1000000];
list<int> Holes, Full_r, Full_l;


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;

    cin >> n;
    for (int i=0;i<n;i++){
        int r,c;
        cin >> r >> c;

        Rows[r-1]++;
        Cols[c-1]++;
    }

    int moves = 0;
    

    for (int i=0;i<n;i++){
        if (Rows[i]>1){
            Full_r.push_back(i);
        }
    }
    for (int i=0;i<n;i++){
        if (Rows[i]>1){
            Full_r.pop_front();
            Full_l.push_back(i);
        }else if (!Rows[i]){
            if (!Full_l.empty()){
                int curr = Full_l.back();
                Rows[curr]--;
                if (Rows[curr] == 1) Full_l.pop_back();
                moves += i-curr;
            }else{
                int curr = Full_r.front();
                Rows[curr]--;
                if (Rows[curr]==1) Full_r.pop_front();
                moves += curr-i;
            }
        }
    }

    for (int i=0;i<n;i++){
        if (Cols[i]>1){
            Full_r.push_back(i);
        }
    }
    for (int i=0;i<n;i++){
        if (Cols[i]>1){
            Full_r.pop_front();
            Full_l.push_back(i);
        }else if (!Cols[i]){
            if (!Full_l.empty()){
                int curr = Full_l.back();
                Cols[curr]--;
                if (Cols[curr] == 1) Full_l.pop_back();
                moves += i-curr;
            }else{
                int curr = Full_r.front();
                Cols[curr]--;
                if (Cols[curr]==1) Full_r.pop_front();
                moves += curr-i;
            }
        }
    }

    cout << moves << "\n";


    return 0;
}