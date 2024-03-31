#include <iostream>
#include <unordered_map>


using namespace std;


int getNum(){
    int r=0;

    char c;
    while ((c=getchar()) && c >= '0') r = r*10+c-'0';
    return r;
}


void work(){

    int n;

    n = getNum();

    unordered_map<int,int> positions;   

    int best = 0;
    int prev = 0;
    for (int i=0;i<n;i++){
        int cur = getNum();
        int curDist = i - positions[cur] + 1;
        if (curDist > prev) prev++;
        else prev = curDist;
        best = max(best,prev);
        positions[cur] = i+1;
    }   
    printf("%d\n",best);
}

int main(){

    int cases;  
    cases = getNum();

    for (int i=0;i<cases;i++){
        work();
    }


    return 0;
}
