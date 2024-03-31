#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int C;

long long most=0, least=0;

int getDiff(int a1, int b1, int a2, int b2){
    return abs(a1-a2)-C*abs(b1-b2);
}

int getN(){
    int n=0;
    char c;

    while ((c=getchar()) && c >= '0' && c <= '9') n = n*10+(c-'0');

    return n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    n = getN();
    C = getN();

    pair<int,int> least,most;
    least = most = {0,0};

    int fst;
    fst = getN();

    least = most = {fst,0};

    printf("0 ");

    for (int i=1;i<n;i++){  
        int cur=getN();

        if (least.first+(i-least.second)*C > cur){
            least = {cur,i};
        }

        if (most.first-(i-most.second)*C < cur){
            most = {cur,i};
        }
        printf("%d ",max(getDiff(cur,i,most.first,most.second),getDiff(cur,i,least.first,least.second)));
    }

    return 0;
}