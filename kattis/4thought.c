#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OPER_AMOUNT 4

typedef struct Node{
    long long int value;
    long long int value_count;
    long long int oper;
    struct Node *next;
    struct Node *next_count;
    struct Node *prev;
} Node;

typedef struct list{
    Node *head;
    Node *tail;
} List;



void print_symbol(long long int symbol){
    if (symbol == 0){
        printf("+");
    }else if (symbol == 1){
        printf("-");
    }else if (symbol == 2){
        printf("*");
    }else if (symbol == 3){
        printf("/");
    }
}

Node * add_node(List *list, long long int value, long long int oper){ /*appends a node to a given list, add value and oper to it*/
    Node *new;

    new = (Node *) malloc(sizeof(Node));
    new->value = value;
    new->oper = oper;
    new->next = NULL;
    new->prev = NULL;

    if (list->tail){
        list->tail->next = new;
        new->prev = list->tail;
    }

    if (!list->head){
        list->head = new;
    }
    list->tail = new;
    
    return new;
}

void free_list(List *list){
    Node *next;

    while(list->head){
        next = list->head->next;
        free(list->head);
        list->head = next;
    }

}

void add(List *list, int base){ /*list containing the code representing the combination of objects in list*/
    Node *next;
    long long int new_number = 0;

    /*parse the list into a decimal number*/
    next = list->head;
    
    while (next){
        new_number = new_number*base + next->value;
        next = next->next;
    }
    
    /*add 1 to the number*/
    new_number++;
    
    /*save the number into the list again*/
    next = list->tail;
    while (next){
        next->value = new_number%base;
        new_number /= base;
        next = next->prev;
    }
}

void compute(List *digits, List *operators, List *save){ /*calculates the value with given codes for digits and operatros and saves it in save*/
    Node *next_oper, *next_digit, *digit, *digit2, *data;
    long long int result, code = 0;

    
    /*assign each number (except the last one) an operator*/
    next_oper = operators->head;
    next_digit = digits->head;

    while (next_oper){
        next_digit->oper = next_oper->value;
        code = code*OPER_AMOUNT + next_oper->value;
        
        next_digit->value_count = next_digit->value + 1;
        next_digit->next_count =  next_digit->next;
        
        next_digit = next_digit->next;
        next_oper = next_oper->next;
    }
    next_digit->value_count = next_digit->value + 1;
    next_digit->next_count = NULL;

    /*first, calculate * and / */
    digit = digits->head;

    while(digit){
        if (digit->oper > 1){
            digit2 = digit->next_count;
            if (digit->oper == 2){
                digit->value_count = digit->value_count*digit2->value_count;
            }else{
                digit->value_count = digit->value_count/digit2->value_count;
            }
            digit->oper = digit2->oper;
            digit->next_count = digit2->next_count;
            result = digit->value_count;
        }else{
            digit = digit->next_count;
        } 
    }
    
    
    /*calculate + and -*/
    digit = digits->head;

    while(digit){
        if (digit->oper == 1 || digit->oper == 0){
            digit2 = digit->next_count;
            if (digit->oper == 0){
                digit->value_count = digit->value_count+digit2->value_count;
            }else{
                digit->value_count = digit->value_count-digit2->value_count;
            }
            digit->oper = digit2->oper;
            digit->next_count = digit2->next_count;
            result = digit->value_count;
        }else{
            digit = digit->next_count;
        } 
    }
    
    data = save->head;

    while (data){
        if (data->value == result){
            return;
        }
        data = data->next;
    }

    digit = digits->head;
    next_oper = operators->head;
    while (digit){
        printf("%lld ",digit->value+1);
        if (next_oper){
            print_symbol(next_oper->value);
            printf(" ");
            next_oper = next_oper->next;
        }
        digit = digit->next;
    }
    printf("= %lld\n",result);
    add_node(save,result,code);
}


int main(int argc, char **argv){ /*1st argument - the highest digit (max 9), 2nd argument - how many operations*/
    List possible, operators, digits, data;
    Node *next;
    int i, base, opers;
    long long int max_digits, max_operators, j,k;

    possible.head = NULL;
    possible.head = NULL;

    operators.tail = NULL;
    operators.head = NULL;

    digits.tail = NULL;
    digits.head = NULL;

    data.head = NULL;
    data.tail = NULL;

    if (argc != 3){
        fprintf(stderr,"Error: Wrong number of arguments\n");
        return 1;
    }
    
    if (argv[1][0]-'0'<0 || argv[1][0]-'0'>9){
        fprintf(stderr,"Error: Wrong argument\n");
        return 1;
    }

    base = argv[1][0]-'0';
    sscanf(argv[2],"%d",&opers);
    
    /*create appropriate lists for Code and Digits (1 more digit than operand)*/
    for (i=0;i<opers;i++){
        add_node(&operators,0,0);
        add_node(&digits,0,0);
    }
    add_node(&digits,0,-1);

    /*get max combinations for each iteration*/
    max_digits = (long long int) pow((double) base, (double) (opers+1)) - 1; /*max combination of digits*/
    max_operators = (long long int) pow((double) OPER_AMOUNT, (double) opers) - 1; /*max combination of operators*/

    /*compute for all digits*/
    for (i=0;i<max_digits;i++){
        /*compute for all operators*/
        for (j=0;j<max_operators;j++){
            compute(&digits,&operators,&data);
            add(&operators,base);
        }
        /*compute last operators' combination*/
        compute(&digits,&operators,&data);
        add(&digits,base);
    }

    /*compute last digits' combination*/
    for (j=0;j<max_operators;j++){
        compute(&digits,&operators,&data);
        add(&operators,base);
    }
    compute(&digits,&operators,&data);

    /*free*/
    free(&possible);
    free(&operators);
    free(&digits);
    free(&data);

    return 0;
}


