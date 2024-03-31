#include <bits/stdc++.h>
#include <climits>

using namespace std;




unsigned long long Dynamic[1000001];
unsigned long long n, c, p;

unsigned long long dfs(int size){
    if (Dynamic[size] != ULLONG_MAX) return Dynamic[size];

    for (int i=1;i<=size;i++){
        Dynamic[size] = min(Dynamic[size],dfs((int)ceil(size/(i+1.0)))+i*p+c);
    }

    return Dynamic[size];
}


int main(){


    cin >> n >> c >> p;


    for (int i=0;i<=n;i++){
        Dynamic[i] = ULLONG_MAX;
    }
    Dynamic[0] = 0;
    Dynamic[1] = 0;

    cout << dfs(n);

    return 0;
}