#include <iostream>
#include <algorithm>

using namespace std;

long long Dynamic[51][3001];
long long Stacks[51][31];

int k;

long long dp(int s, int p){
    if (s < 1 || p < 1) return 0;

    if (Dynamic[s][p] || s == 1){
        return Dynamic[s][p];
    } 

    long long maximum = 0;
    for (int i=1;i<=k;i++){
        maximum = max(maximum,max(dp(s-1,p-i)+Stacks[s][i],dp(s-1,p)));
    }
    Dynamic[s][p] = maximum;
    return Dynamic[s][p];

}

int main(){
    int cases;
    
    cin >> cases;
        
    for (int c=0;c<cases;c++){
        int n,p;
        
        cin >> n >> k >> p;

        for (int i=1;i<=n;i++){
            long long value = 0;
            for (int j=1;j<=k;j++){
                long long tmp;
                cin >> tmp;
                value += tmp;
                Stacks[i][j] = value;
            }
        }
        for (int i=0;i<51;i++){
            for (int j=0;j<3001;j++){
                Dynamic[i][j] = 0;
            }
        }
        for (int i=1;i<=k;i++){
            Dynamic[1][i] = Stacks[1][i];
        }
        cout << "Case #" << c+1 << ": " << dp(n,p) << "\n";
    }
    
    
    return 0;
}