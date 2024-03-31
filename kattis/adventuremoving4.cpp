#include <bits/stdc++.h>

using namespace std;


typedef struct{
    int dist, price;

} Station;

#define INF 1073741824

int Dynamic[100][201];
Station Stations[100];


int main(){
    int k;

    cin >> k;

    int n, p;
    int s=0;

    
    while (cin >> Stations[s].dist >> Stations[s].price){
        s++;
    }

    if (Stations[0].dist > 100){
        cout << "Impossible\n";
        return 0;
    }

    for (int g=101-Stations[0].dist;g<=200;g++){
        Dynamic[0][g] = Dynamic[0][g-1]+Stations[0].price;
    }

    for (int i=1;i<s;i++){
        int dist = Stations[i].dist-Stations[i-1].dist;
        if (dist > 200){
            cout << "Impossible\n";
            return 0;
        }
        for (int g=0;g<201;g++){
            if (dist+g<=200){
                Dynamic[i][g] = Dynamic[i-1][dist+g];
            }else{
                Dynamic[i][g] = Dynamic[i-1][200]+(g-(200-dist))*Stations[i].price;
            }
            Dynamic[i][g] = min(Dynamic[i][g],Dynamic[i-1][dist]+g*Stations[i].price);
        }
    }

    int best = INF;
    for (int i=0;i<s;i++){
        if (k-Stations[i].dist+100 <= 200) best = min(best,Dynamic[i][k-Stations[i].dist+100]);
    }

    if (best == INF) cout << "Impossible\n";
    else cout << best;

    return 0;
}