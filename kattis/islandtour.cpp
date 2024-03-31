#include <bits/stdc++.h>


using namespace std;



long long Times[3][400][3][400],Time[3][400],Dist[400],Steps[3][400][400][2];

typedef struct{
    int person,position;
} Start;

bool cmp(Start a, Start b){
    return a.position < b.position;
}


int main(){

    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Dist[i];
    }

    for (int i=0;i<3;i++){
        for (int j=0;j<n;j++){
            cin >> Time[i][j];
        }
    }

    for (int p=0;p<3;p++){
        for (int i=0;i<n;i++){
            Steps[p][i][i][0] = 0;
            Steps[p][i][i][1] = Time[p][i];
            for (int j=1;j<n;j++){
                int curr = (i+j)%n;
                Steps[p][i][curr][0] = Steps[p][i][(curr-1+n)%n][1]+Dist[(curr-1+n)%n];
                Steps[p][i][curr][1] = Steps[p][i][curr][0] + Time[p][curr]; 
            }
        }
    }

    for (int p1=0;p1<3;p1++){
        for (int i=0;i<n;i++){
            for (int p2_i=1;p2_i<3;p2_i++){
                for (int j_i=1;j_i<n;j_i++){
                    int p2 = (p1+p2_i)%3;
                    int j = (i+j_i)%n;
                    bool f = true;
                    for (int step=0;step<n;step++){
                        if (Steps[p1][i][step][0] < Steps[p2][j][step][1] && Steps[p1][i][step][1] > Steps[p2][j][step][0]){
                            f = false;
                            break;
                        }   
                    }
                    Times[p1][i][p2][j] = f;
                }
            }
        }
    }


    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                Start sorted[] = {{0,i},{1,j},{2,k}};
                sort(sorted,sorted+3,cmp);  
                Start first = sorted[0], scnd = sorted[1], third = sorted[2];    
                if (i==j || i==k || j==k) continue;

                if (Times[first.person][first.position][scnd.person][scnd.position]){
                    if (Times[scnd.person][scnd.position][third.person][third.position]){
                        if (Times[third.person][third.position][first.person][first.position]){
                            cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "impossible\n";
    return 0;
}