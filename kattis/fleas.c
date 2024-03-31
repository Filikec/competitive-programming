#include <stdio.h>

int is_white(long long int x, long long int y, long long int S){
    return (x/S+y/S)%2 && x%S && y%S;
}

void solve(long long int S, long long int x, long long int dx, long long int y, long long int dy){
    long long int i, relative_x, relative_y, flag, relative_square;

    relative_x = x - (x/S)*S; // position relative to the square
    relative_y = y - (y/S)*S; // 
    relative_square = (x/S + y/S)%2;

    i = 0;
    flag = 0;

    while (!is_white(x,y,S)){
        if (x - (x/S)*S == relative_x && y - (y/S)*S == relative_y && i && (x/S+y/S)%2 == relative_square){ // if this relative position was already reached, not possible
            printf("The flea cannot escape from black squares.\n");
            flag = 1;
            break;
        }

        x += dx; // jump
        y += dy;
        i++;
    }

    if (!flag){
        printf("After %lld jumps the flea lands at (%lld, %lld).\n",i,x,y);
    }
        
}

int main(){
    long long int S,x,y,dx,dy;

    scanf("%lld %lld %lld %lld %lld",&S,&x,&y,&dx,&dy);

    while (S || x || dx || y || dy){
        solve(S,x,dx,y,dy);
        scanf("%lld %lld %lld %lld %lld",&S,&x,&y,&dx,&dy);
    }
    
    return 0;
}
