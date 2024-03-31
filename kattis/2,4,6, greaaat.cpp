#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N,T;
pair<int,int> Cheers[501];
long double Costs[400001];

int main(){
    cin >> N >> T;

    Cheers[0] = {1,1};

    for (int i=1;i<=N;i++){
        cin >> Cheers[i].first >> Cheers[i].second;
    }


    


    return 0;
}
