#include <stdio.h>
#include <stdlib.h>

#define SIZE 1

char *First,*Second,*Result,*Temp;
char Alphabet[52];


void get_alphabet(){
    char c = 'a';
    for (int i=0;i<26;i++){
        Alphabet[i] = c++;
    }
    c = 'A';
    for (int i=26;i<52;i++){
        Alphabet[i] = c++;
    }
}

int is_alphabet(char c){
    return (c >= 'a' && c <='z' ) || (c>='A'&&c<='Z');
}

char * get_input(char *pointer){
    int len = SIZE, i=0;
    char c;

    pointer = (char *)malloc(SIZE);

    while (1){
        c = getchar();
        if (c == '\n'){
            break;
        }
        if (!is_alphabet(c)){
            return NULL;
        }
        if (i==len){
            pointer = realloc(pointer,++len);
        }
        pointer[i++] = c;
    }

    if (i==len){
        pointer = realloc(pointer,++len);
    }
    pointer[i] = '\0';
    
    return pointer;
}

char shift(char c, int d){
    int i;

    if (c>='a'){  // a = 97, A = 65
        i = c-'a';
    }else{
       i = c - 39;
    }
    
    i = (i+d)%52;

    return Alphabet[i];
}

int compare(char *s1, char *s2){
    int diff = 0;

    while (*s1){
        if (*s1++ != *s2++){
            diff++;
        }
    }
    return diff;
}

void switch_string(char *s1, char *s2, int d){
    while (*s1){
        *s2++ = shift(*s1++,d);
    }
    *s2 = '\0';
}

void copy_string(char *s1, char *s2){
    while (*s1){
        *s2++ = *s1++;
    }
    *s2 = '\0';
}

int get_str_len(char *s){
    int size = 0;

    while (s[size++]){
        ;
    }
    return size;
}
int main(){
    int best,comparison,size1,size2;
    get_alphabet();

    First = get_input(First);
    Second = get_input(Second);

    if (!First || !Second){
        sprintf(stderr,"Error: Chybny vstup!");
        return 100;
    }
    
    size1 = get_str_len(First);
    size2 = get_str_len(Second);
    
    if (size1 != size2){
        sprintf(stderr,"Error: Chybna delka vstupu!");
        return 101;
    }
    
    Result = (char *)malloc(sizeof(First)*size1);
    Temp = (char *)malloc(sizeof(Second)*size2);
    best = size1;
    

    for (int i=0;i<size1-1;i++){
        Temp[i] = '4';
    }
    Temp[size1-1] = '\0';


    for (int i=0;i<52;i++){
        switch_string(First,Temp,i);
        
        comparison = compare(Second,Temp);
        
        if (comparison<best){
            best = comparison;
            copy_string(Temp,Result);
        }
    }

    printf("%s\n",Result);

    free(First);
    free(Second);
    free(Temp);
    first(Result);
    return 0;
}