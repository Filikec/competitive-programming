#include <iostream>

using namespace std;


long long get_num(){
    char c;
    long long num = 0;
    while ((c=getchar())!='\n'){
        num = num*10+c-'0';       
    }
    return num;
}

void work(){
    int kids;
    long long amount, remainder=0;
    
    scanf("%d",&kids);
    getchar();
    
    for (int k=0;k<kids;k++){
        amount = get_num();
        remainder = (remainder + amount%kids)%kids;
    }
    if (remainder){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
}

int main(){
    
    int cases;
    scanf("%d",&cases);
    for (int c=0;c<cases;c++){
        work();
    }

    return 0;
}
