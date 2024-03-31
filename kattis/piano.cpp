#include <bits/stdc++.h>

using namespace std;


typedef struct{
    int start, end;
} Interval;


Interval Pianos[1000];

bool cmp(Interval a, Interval b){
    return a.start < b.start;
}


void work(){
    int p, m;

    cin >> p >> m;

    m /= 2;

    for (int i=0;i<p;i++){
        cin >> Pianos[i].start >> Pianos[i].end;
    }

    sort(Pianos,Pianos+p,cmp);

    for (int i=0;i<p;i++){
        
    }



}


int main(){

    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        work();
    }



    return 0;
}