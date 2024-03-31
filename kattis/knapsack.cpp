#include <iostream>
#include <cmath>
#include <list>

using namespace std;

#define MIN -20000001

//at most 30 cases
int Dynamic[2001][2001];
bool Nums[2001][2001]; // 0 - no new num
int W[2000], V[2000];


int main(){
    int c,n;

    for (int i=1;i<2001;i++) Dynamic[0][i] = MIN;
    while (cin >> c >> n){
        for (int i=0;i<n;i++){
            cin >> V[i] >> W[i];
        }
        for (int i=1;i<=n;i++){
            for (int j=0;j<=c;j++){
                Dynamic[i][j] = Nums[i][j] = 0;
            }
        }
        pair<int,int> best = {0,0};
        for (int i=1;i<=n;i++){
            for (int j=0;j<=c;j++){
                if (j-W[i-1] >= 0 && Dynamic[i-1][j] < Dynamic[i-1][j-W[i-1]]+V[i-1]){
                    Dynamic[i][j] = Dynamic[i-1][j-W[i-1]]+V[i-1];
                    Nums[i][j] = true;
                }else{
                    Dynamic[i][j] = Dynamic[i-1][j];
                    Nums[i][j] = false;
                }
                if (Dynamic[i][j] > Dynamic[best.first][best.second]){
                    best = {i,j};
                }
            }
        }
        list<int> used;
        while (best.first){
            if (Nums[best.first][best.second]) used.push_front(best.first-1), best = {best.first-1,best.second-W[best.first-1]};
            else best = {best.first-1,best.second};
        }
        cout << used.size() << '\n';
        for (auto u : used) cout << u << ' ';
        cout << '\n';
    }
    
    return 0;
}