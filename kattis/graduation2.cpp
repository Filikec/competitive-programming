#include <iostream>

using namespace std;



typedef struct set{
    struct set *parent;
} Set;

Set Sets[26];
char Prev[700];

Set *get_parent(Set *s){
    while (s->parent){
        s = s->parent;
    }
    return s;
}

int main(){
    int n,m,k;

    scanf("%d %d %d",&n,&m,&k);

    for (int i=0;i<k;i++){
        Sets[i].parent = NULL;
    }

    getchar();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c = getchar();
            Set *p1,*p2;
            
            if (Prev[j]==c||!Prev[j]){
                Prev[j] = c;
                continue;
            }
            p1 = get_parent(&Sets[Prev[j]-'A']), p2 = get_parent(&Sets[c-'A']);
            
            if (p1!=p2 || !p1){
                p2->parent = p1;
            }
            Prev[j] = c;
        }   
        getchar();
    }

    int count = 0;
    for (int i=0;i<k;i++){
        if (!Sets[i].parent) count++;
    }

    printf("%d\n",count);


    return 0;
}