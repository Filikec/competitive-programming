#include <stdio.h>
#include <stdlib.h>

typedef struct record{
    char name[32];
    int rank;
} Record;

Record ppl[100];



int compare(const void *a, const void *b){
    Record *p1, *p2;
    int rank1, rank2;
    char *name1, *name2;

    p1 = (Record *) a;
    p2 = (Record *) b;

    rank1 = p1->rank;
    rank2 = p2->rank;

    name1 = p1->name;
    name2 = p2->name;

    if (rank1 != rank2){
        return rank2-rank1;
    }

    while (*name1 && *name2){
        if (*name1 != *name2){
            return *name1-*name2;
        }else{
            name1++;
            name2++;
        }
    }

    return 0;

}

int get_num(char *name){
    int digit, inc = 1, num = 0, i = 0;
    
    do{ 
        if (*name == 'm'){
            digit = 1;
            name += 6;
        }else if (*name == 'u'){
            digit = 2;
            name += 5;
        }else {
            digit = 0;
            name += 5;
        }
        num += digit*inc;
        inc *= 3;
        i++;
    }while (*name++ == '-');
    
    while (i++ != 10){
        num = num*3 + 1;
    }
    return num;
}

int main(){
    int cases, people, i, j;
    char rank[100], *name;

    scanf("%d",&cases);

    for (j=0;j<cases;j++){
        scanf("%d",&people);
        for (i=0;i<people;i++){
            scanf("%s %s",ppl[i].name,rank);
            ppl[i].rank = get_num(rank);
            scanf("%s",rank);
        }

        qsort((void *)ppl,people,sizeof(Record),compare);

        for (i=0;i<people;i++){
            name = ppl[i].name;
            while (*name != ':'){
                printf("%c",*name++);
            }
            printf("\n");
        }
        printf("==============================\n");

    }
    
    return 0;
}

/*
2
5
mom: upper-upper-lower-middle class
dad: middle-middle-middle-lower-middle class
queenelizabeth: upper-upper-upper class
chair: lower-lower class
unclebob: middle-middle-lower-middle class
4
FILIP: upper-lower class
filip: lower-lower class
FiLip: lower class
afilip: middle-lower class

*/