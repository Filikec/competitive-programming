#include <bits/stdc++.h>


using namespace std;


int Values[400000];
int Min[400000],Max[400000];

int get_num(){
    int result = 0;
    char c;
    while ((c=getchar())>='0'){
        result = result*10+c-'0';
    }
    return result;
}

int main(){
    int n,c;

    n = get_num();
    c = get_num();
    
    for (int i=0;i<n;i++){
        Values[i] = get_num();
    }

    
    int minim = 0, maxim = 0;
    printf("0 ");
    for (int i=1;i<n;i++){
        if (Values[minim]+c*(i-minim) > Values[i]){
            minim = i;
        }
        if (Values[maxim]-c*(i-maxim) < Values[i]){
            maxim = i;
        }
        
         printf("%d ",max(abs(Values[i]-Values[minim])-c*(i-minim),abs(Values[i]-Values[maxim])-c*(i-maxim)));
    }
    printf("\n");

    return 0;
}