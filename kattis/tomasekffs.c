/*
 * || Caesar cipher ||
 * program gets 2 input 
 * first is ciphered message
 * second is somewhat decoded message
 * program returns the most probable answer based on the same characters in inputs
 * NOTE - with final look of this program (just look) I had help, I hope the coding style will be appreated becase it
 * took me over 16 hours to write this program 
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define SIZE 100
#define LENGHT_OF_ALPHABET 52

char *First,*Second,*Result,*Temp; // preparing pointer for future
char Alphabet[LENGHT_OF_ALPHABET];

/*
 * || Get Alphabet ||
 * generates letters from English alphabet  
 * first lowercase letters than uppercase letters
 * saves letters into array "Alphabet"
*/
void get_alphabet(){
  
  int count = 0; // counts index in Alphabet array //
  
  // put lower letters from 'a' to 'z' into Alphabet array //
  for (int i = 'a'; i <= 'z'; ++i){
    Alphabet[count] = i; 
    count ++; // increase index by 1 //
  }
  
  // put upper letters from 'A' to 'Z' into Alphabet array //
  for (int i = 'A'; i <= 'Z'; ++i){
    Alphabet[count] = i; 
    count ++; // increase index by 1 //
  }
}

// return True or False based on presence of given char in alphabet //
int is_alphabet(char c){
    int rtn; // return value //
    if((c >= 'a' && c <='z' ) || (c>='A'&&c<='Z')){ // if the char is between these letters return true //
        rtn = TRUE;
    }
    else{ // if there is other character return false // 
        rtn = FALSE;
    }    
    return rtn; // final return //
}

// function reads input one letter by one letter and if needed alocate memory //
char * get_input(char *pointer){  
    int len = SIZE, i=0;
    char c; // temporary variable to load letter by letter //

    pointer = (char *)malloc(SIZE); // creates pointer using malloc with defined SIZE //

    // NOTE i did not come up with better solution // 
    while (1){ // function is ended by break in first condition (end of the input) or by return (nonsupported character in input)
        c = getchar();
        if (c == '\n'){ // if there is end of the line stop //
            break;
        }
        if (is_alphabet(c) == FALSE){ // if there is character that is not allowed //
            free(pointer); //in case it fails, free the memory
            return NULL; 
        }
        if (i==len){ // if there isn't enough space realloc more space //
            pointer = realloc(pointer,++len); // add to the lenght and reallocate//
        }
        pointer[i++] = c; // write value to array //
    }

    if (i==len){
        pointer = realloc(pointer,++len); // reallocate space for potencial need to end string //
    }
    pointer[i] = '\0'; // adds end to the end of the string
    
    return pointer;
}

int diff_between_ASSII_and_our_alphabet = 39; // 'A' in ASCII = 65 | in our case uppercase letters starts in 26 => diffence is 39 //
// function shifts with character by given value d //
char shift(char c, int d){ 
    int i; // temporary variable for indexing //

    if (c>='a'){ // 'a' in ASCII = 97 | getting index from values in ASCII to our Alphabet //
        i = c-'a'; 
    }
    else{
       i = c - diff_between_ASSII_and_our_alphabet; // 'A' in ASCII = 65 | in our case uppercase letters starts in 26 => diffence is 39 //
    }
    
    i = (i+d)%LENGHT_OF_ALPHABET; // final index could be out of range of the array | modulo of the whole array for getting //

    return Alphabet[i]; // takes index and findes letter in Alphabet //
}

// function takes 2 words and return how many different letter there is in each of the word //
int compare(char *s1, char *s2){
    int diff = 0; // set counter to 0

    while (*s1){ // until the end of the first word //
        if (*s1++ != *s2++){ // every iteration add one to both elements and if the letters are different add to counter //
            diff++; //add to the counter //
        }
    }
    return diff; //return how many different letters there were
}

// creates shifted string using function shift //
void switch_string(char *s1, char *s2, int d){
    while (*s1){
        *s2++ = shift(*s1++,d); // creates shifted variant of given string //
    }
    *s2 = '\0'; // adds end of the string //
}

// function is used for copying and characters to the result array //
void copy_string(char *s1, char *s2){
    while (*s1){ // while there are char in string one //
        *s2++ = *s1++; // compare and adds one to the pointers //
    }
    *s2 = '\0'; // add end of the string //
}

// function get lenght of the string //
int get_str_len(char *s){
    int size = 0; // temporary saves it to size //

    while (s[size++]){ // until its possible add one to the size counter //
        ;
    }
    return size; // return calculated value //
}
int main(){
    int best,comparison,size1,size2; // sets integers for later use //
    get_alphabet(); // generates array of letters in alphabet order times 2 | first lowercase letters than uppercase letters // 

    First = get_input(First); // loads input into variable based on lenght of the input //
    Second = get_input(Second); // -||- //

    if (First == NULL || Second == NULL){ // if the function returned value that is null = there is non supported character in input //
        fprintf(stderr,"Error: Chybny vstup!\n");
        free(First); // free functions to deallocate allocated memory //
        free(Second);
        return 100;
    }

    size1 = get_str_len(First); // saves sizes of given words into variables //
    size2 = get_str_len(Second);
    

    if (size1 != size2){ // compares sizes and return error value //
        fprintf(stderr,"Error: Chybna delka vstupu!\n");
        free(First); // free functions to deallocate allocated memory //
        free(Second);
        return 101;
    }
    
    Result = (char*) malloc(sizeof(First)*size1);// creates alocated space for result //
    Temp = (char*) malloc(sizeof(Second)*size2); // creates alocated space for result //
    best = size1; // the most possible different letters //
    
    for (int i=0;i<LENGHT_OF_ALPHABET;i++){ // goes though the whole alphabet 
        switch_string(First,Temp,i); // creates shifted variant of the existing string //
        comparison = compare(Second,Temp); // compares two string and return number of different letters //
        
        if (comparison<best){ // if there is better number saves that number and its string //
            best = comparison; // creates new best possible different letters //
            copy_string(Temp,Result); // saves temporary string into in this state temporary result array //
        }
        
    }

    printf("%s\n",Result); // prints result //
    
    free(First); // free functions to deallocate allocated memory //
    free(Second);
    free(Temp);
    free(Result);
    
    return 0;
}
