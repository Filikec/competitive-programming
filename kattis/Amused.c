#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Entry{
    char name[21];
    int timestamp;
    float money;
} Entry;

Entry Log[20];
int names[20], I;

void day(void);
int get_index(char *);
int compare_entry(const void *, const void *);

int main(int argc, char **argv){
    char open[6];
    int i, day_n;
    
    day_n = 1;

    while (scanf("%s",open) == 1){
        day();
        printf("Day %d\n",day_n++);

        for (i=0;i<I;i++){
            names[i] = i;
        }

        qsort(names,I,sizeof(int),compare_entry);

        for (i=0;i<I;i++){
            printf("%s $%0.2f\n",Log[names[i]].name,Log[names[i]].money);
            strcpy(Log[names[i]].name,"");
        }
        printf("\n");

        I = 0;
    }
    return 0;
}


void day(void){
    char name[21], action[6];
    int time, index;

    
    if (scanf("%s",action)){
        while (strcmp(action,"CLOSE")){   
            scanf("%s %d",name,&time);
            index = get_index(name);
            if (index == -1){
                strcpy(Log[I].name,name);
                Log[I].timestamp = time;
                Log[I].money = 0;
                I++;
            }else{
                if (!strcmp(action,"ENTER")){
                    Log[index].timestamp = time;
                }else{
                    Log[index].money += (time-Log[index].timestamp)*0.1;
                }
            }
            scanf("%s",action);
        }
    }
}

int get_index(char *name){
    int i;

    for (i=0;i<I;i++){
        if (!strcmp(Log[i].name,name)){
            return i;
        }
    }

    return -1;
}

int compare_entry(const void *n1, const void *n2){
    int *i1, *i2, i, count;
    i1 = (int *) n1;
    i2 = (int *) n2;

    count = 0;

    for (i=0;i<20;i++){
        
        count += tolower(Log[*i1].name[i]) - tolower(Log[*i2].name[i]);

        if (count){
            return count;
        } 
    }
    
    return 0;
}

