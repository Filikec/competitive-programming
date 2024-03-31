#include <stdio.h>
#include <string.h>

char get_min_base(char *, char *, char *);
int get_decimal(char *, char);
double calc(int,char,int);

int main(){
    int i, count, d1,d2, p, dr;
    char n1[101],n2[101],oper, equals[101], what, base, possible[50];
    count = 0;
    
    scanf("%d",&count);
    for (i=0;i<count;i++){
        scanf("%s %c %s %c %s",n1,&oper,n2,&what,equals);
        base = get_min_base(n1,n2,equals);
        p = 0;
        
        if (base == -1){
            printf("invalid\n");
            continue;
        }
        base = base==2?1:base;
        
        for (base = base;base<37;base++){
            d1 = get_decimal(n1,base);
            d2 = get_decimal(n2,base);
            dr = get_decimal(equals,base);
            if (d1 < 0 || d2 < 0 || dr < 0){
                continue; 
            }
            if (calc(d1,oper,d2) == dr){
                if (base == 36){
                    possible[p++] = 48;
                }else{
                    possible[p++] = base>9?base+87:base+48;
                }
                
            }
        }
        if (p!=0){
            possible[p] = '\0';
            printf("%s\n",possible);
        }else{
            printf("invalid\n");
        }
        

    }
    

    return 0;
}

double calc(int d1, char op, int d2){
    double n1, n2;
    n1 = d1;
    n2 = d2;
    if (op == '+'){
        return n1+n2;
    }else if (op == '-'){
        return n1-n2;
    }else if (op == '*'){
        return n1*n2;
    }else if (op == '/'){
        return n1/n2;
    }

    return -1;
}

int get_decimal(char *num, char base){
    int result, digit;
    result = 0;
    
    while (*num){
        digit = *num>'9'?*num++ - 87:*num++ - '0';
        if (base == 1 && !digit){
            return -1;
        }
        result = result*base + digit;
        
    }
    
    return result;
}

char get_min_base(char *n1, char *n2, char *equals){
    char max;
    max = 0;
    while (*n1){
        if (!(*n1  > 47 && *n1  < 58) && !( *n1 > 96 && *n1 < 123)){
            return -1;
        }
            
        if (*n1++ > max)
            max = *(n1-1);
        
    }
    
    while (*n2){
        if (!(*n2  > 47 && *n2  < 58) && !( *n2 > 96 && *n2 < 123)){
            return -1;
        }
            
        if (*n2++ > max)
            max = *(n2-1);
    }
    while (*equals){
        if (!(*equals > 47 && *equals  < 58) && !( *equals > 96 && *equals < 123)){
            return -1;
        }
        if (*equals++ > max)
            max = *(equals-1);
    }   
    
    max -= 47;
    max = max>10?max-39:max;
    return max;

}

