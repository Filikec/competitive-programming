#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;


void work(int c){
    bool end = false;

    long double MaxCost[200][200];
    unordered_map<string,int> MapStr;

    for (int i=0;i<c;i++){
        for (int j=0;j<c;j++){
            MaxCost[i][j] = -1;
        }
    }

    for (int i=0;i<c;i++){
        string s;
        cin >> s;
        MapStr[s] = i;
    }

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        
        string cur1, cur2;
        cin >> cur1 >> cur2;
        long double r1, r2;
        cin >> r1;
        cin.get();
        cin >> r2;
        
        int index1, index2;
        index1 = MapStr[cur1], index2 = MapStr[cur2];

        if (MaxCost[index1][index2] != -1 && MaxCost[index1][index2] != r2/r1) {
            end = true;
        }

        MaxCost[index1][index2] = r2/r1;
    }

    for (int i=0;i<c;i++){
        MaxCost[i][i] = 1;
    }
    if (end){
        cout << "Arbitrage<\n";
        
        return;
    }

    for (int i=0;i<c;i++){
        for (int j=0;j<c;j++){
            for (int k=0;k<c;k++){
                if (MaxCost[j][i] != -1 && MaxCost[i][k] != -1 && MaxCost[j][k] < MaxCost[j][i]*MaxCost[i][k]){
                    MaxCost[j][k] = MaxCost[j][i]*MaxCost[i][k];
                }
                if (j==k && MaxCost[j][k] != 1){
                    cout << "Arbitrage\n";
                    return;
                }
            }
        }
    }

    for (int i=0;i<c;i++){
        if (MaxCost[i][i] != 1){
            cout << "Arbitrage\n";
            return;
        }
    }

    cout << "Ok\n";
}

int main(){

    int c;

    while (true){
        cin >> c;
        if (!c) break;
        work(c);
    }

    return 0;
}