#include <stdio.h>
#include <ctype.h>

long int get_hex(void);
char hexa[9];

int main(int argc, char **argv){
    int c, i;
    long n;


    while ((c=getchar())!=EOF){
        if ((tolower(c)) == '0' && tolower(c=getchar())=='x'){
            printf("0%c",c);
            n = get_hex();
            for (i=0;hexa[i]!=-1;i++){
                printf("%c",hexa[i]);

            }
            printf(" %ld\n",n);
        }        
    }
    

    return 0;
}

long int get_hex(){
    int i, digit;
    long number = 0;
    
    for (i=0;i<8;i++){
        digit = getchar();
        if (digit == EOF){
            hexa[i] = -1;    
            return number;
        }
        hexa[i] = digit;
        digit = tolower(digit)-'0';
        if (digit < 0 || digit > 9){
            digit -= 39;
            if (digit < 10 || digit > 15){
                hexa[i] = -1;
                
                return number;
            }
        }
        
        number = number*16 + digit;
    }
    hexa[8] = -1;
    return number;
}