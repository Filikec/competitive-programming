#include <stdio.h>


int Dogs[101][101], Cats[101][101];
int Wanted[101], Unwanted[101];
int Satisfied;

int animal_num();
int replace(int [101][101], int [101][101], int, int, int);

int main(){
    int cases, cats_n, dogs_n, voters_n;
    int dog,cat,animal,c_voters,d_voters;
    int amount;
    int i, j, c;
    int (*more)[101],  (*less)[101];

    scanf("%d",&cases);

    for (c=0;c<cases;c++){
        scanf("%d %d %d",&cats_n, &dogs_n, &voters_n);
        c_voters = 0;
        d_voters = 0;
        Satisfied = 0;

        amount = dogs_n>cats_n?dogs_n:cats_n;
        amount++;


        for (i=0;i<voters_n;i++){

            animal = animal_num(&dog,&cat);
            animal_num(&dog,&cat);

            if (animal){
                Dogs[dog][cat]++;
                d_voters++;
            }else{
                Cats[cat][dog]++;
                c_voters++;
            }
        
        }

        
        if (d_voters>c_voters){
            more = Dogs;
            less = Cats;
            Satisfied += d_voters;
            /*printf("More: dogs\n");*/
            
        }else{
            more = Cats;
            less = Dogs;
            Satisfied += c_voters;
            /*printf("More: cats\n");*/
        }

        for (i=1;i<amount;i++){
            for (j=1;j<amount;j++){
                if (more[i][j]){
                    Wanted[i] += more[i][j];
                    Unwanted[j] += more[i][j];
                }
            }
        }
    


        for (i=1;i<amount;i++){
            for (j=1;j<amount;j++){
                if (more[i][j])
                    replace(more,less,i,j,amount);
                if (less[i][j] && !Wanted[j] && !Unwanted[i])
                    Satisfied += less[i][j];
            }
        }

        for (i=1;i<amount;i++){
            for (j=1;j<amount;j++){
                if (Dogs[i][j])
                    Dogs[i][j] = 0;
                if (Cats[i][j])
                    Cats[i][j] = 0;
            }
            Wanted[i] = 0;
            Unwanted[i] = 0;
        }
        
        printf("%d\n",Satisfied);
    }
}


int replace(int more[101][101], int less[101][101], int wanted, int unwanted, int amount){
    int count, add, satisfiable, satisfied;
    int i;

    count = 0;
    satisfiable = 0;
    satisfied = 0;

    for (i=1;i<amount;i++){

        if (less[i][wanted] && unwanted != i){
            add = more[wanted][unwanted] + less[i][wanted] - (Wanted[wanted]+Unwanted[i]); 
            satisfiable += less[i][wanted];
            count += add;
        }
        if (less[unwanted][i]){
            add = unwanted==i?less[unwanted][i]-Unwanted[unwanted]+more[wanted][unwanted]:less[unwanted][i]-(Wanted[i]+Unwanted[unwanted])+more[wanted][unwanted];
            count += add;
            satisfiable += less[unwanted][i];
        }
        
    }
    
    if (more[wanted][unwanted] < count){
        

        for (i=1;i<amount;i++){
            if (more[i][unwanted]){
                satisfied += more[i][unwanted];
                
            }
            if (more[wanted][i] && i!=wanted && unwanted!=i){
                satisfied += more[wanted][i];
               
            }
        }

        Satisfied += satisfiable-satisfied;

        return 1;
    }

    return 0;
}



int animal_num(int *dog, int *cat){
    int c, num, animal;

    num = 0;
    animal = 0;
    c = getchar();

    while (c != 'D' && c != 'C'){
        c = getchar();

    }

    if (c == 'D'){
        animal = 1;
    }

    c = getchar() - '0';

    while (c > -1 && c < 10){
        num = num*10 + c;
        c = getchar() - '0';
    }


    if (animal){
        *dog = num;
        return 1;
    }else{
        *cat = num;
         return 0;
    }
}


/*
3
10 10 16
C1 D2
C1 D2
C1 D2
C4 D4
C4 D4
C6 D8
C6 D8
C9 D5
C9 D5
D3 C1
D3 C1
D2 C2
D2 C2
D5 C6
D5 C6
D5 C6
10 10 15
C1 D2
C1 D2
C1 D2
D2 C3
D2 C3
D3 C1
D3 C1
D5 C6
D5 C6
D5 C6
C6 D6
C6 D6
C7 D5
C7 D5
C8 D8
5 5 15
C1 D3
C1 D1
C1 D1
C1 D1
C1 D1
C3 D3
C4 D4
C4 D4
D1 C2
D1 C2
D1 C2
D2 C1
D2 C1
D2 C3
D2 C5
*/