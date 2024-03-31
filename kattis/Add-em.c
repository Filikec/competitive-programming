#include <stdio.h>


int numbers_exist[100000001];
long int numbers[100000];

long int get_reverse(long int num){
    int digit;
    long int reversed = 0;

    while(num){
        digit = num%10;
        num /= 10;
        if (digit == 4 || digit == 7 || digit == 3){
            return 0;
        }
        if (digit == 9){
            digit = 6;
        }else if (digit == 6){
            digit = 9;
        }
        reversed = reversed*10 + digit;
    }

    return reversed;
}

int main(){
    long int number, amount, i, in=0, sum;
    int flag = 0;

    scanf("%ld",&amount);
    scanf("%ld",&sum);

    for (i=0;i<amount;i++){
        scanf("%ld",&number);
        numbers[in++] = number;
        numbers_exist[number] += 1;
        if (number != get_reverse(number)){
            if ((number = get_reverse(number)))
                numbers_exist[number] += 1;
        }

    }
    
    
    for (i=0;i<in;i++){
        number = numbers[i];
        
        if ((numbers_exist[number] < 2 && sum-number == number) || (numbers_exist[get_reverse(number)] < 2 && sum-number == get_reverse(number))){
            ;
        }else{
            if (numbers_exist[sum-number]){
                printf("YES\n");
                flag = 1;
                break; 
             
            }

        }
        

        number = get_reverse(number);

        if ((numbers_exist[number] < 2 && sum-number == number) || (numbers_exist[get_reverse(number)] < 2 && sum-number == get_reverse(number))){
            continue;
        }

        if (numbers_exist[sum-number]){
            printf("YES\n");
            flag = 1;
            break; 
             
        }
    }

    if (!flag){
        printf("NO\n");
    }

    return 0;
}