#include <stdio.h>
#include <stdlib.h>




long int get_int(char *);
int next_gen(int, int, int);

int main(int argc, char **argv){
    long int cell_n, gen, code;
    int *gen0, *gen1;
    int rules[8];
    int i, j;

    if (argc != 4){
        return -1;
    }

    cell_n = get_int(argv[1]);
    gen = get_int(argv[2]);
    code = get_int(argv[3]);
          
    if (cell_n<1 || gen < 1 || code < 0 || code > 255){
        
        return -1;
    }

    if (!(gen0 = (int *) calloc(cell_n,sizeof(int))) || !(gen1 = (int *) calloc(cell_n,sizeof(int)))){
        return -1;
    }
    

    for (i=0;i<8;i++){
        rules[7-i] = code%2;
        code /= 2;
    }

    gen0[(cell_n-1)/2] = 1;


    for (i=0;i<gen-1;i++){
        for (j=0;j<cell_n;j++){

            gen1[j] = rules[next_gen(gen0[j-1<0?cell_n-1:j-1],gen0[j],gen0[j+1==cell_n?0:j+1])];
            
            if (gen0[j]){
                printf("*");
            }else{
                printf(" ");
            }
            
        }

        printf("\n");

        for (j=0;j<cell_n;j++){
            gen0[j] = gen1[j];
        }
    }

    free(gen0);
    free(gen1);

    return 0;
}


long int get_int(char *string){
    long int n = 0;
    int i = 0;
    if (string[0] == '-'){
        return -1;
    }
    while (string[i]!='\0'){
        n = n*10 + string[i++] - '0';
    }
    
    return n;  

}


int next_gen(int l, int m, int r){
    int rule_i = 0;
    rule_i = !r;
    rule_i += !m*2;
    rule_i += !l*4;

    return rule_i;
}
