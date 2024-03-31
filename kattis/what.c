#include <stdio.h>

int m=10,n,o;
int *z=&m;
#define N 10000
int numbers[N];
void quicksort(int *,int,int);
void reorder(int *, int, int, int *);
void swap(int *, int, int);

int main(){
    int n, i;
    printf("Input the number of elements to store in the array : ");
    scanf("%d",&n);
    printf("Input %d elements in the array :\n",n);


    for (i=0;i<n;i++){
        printf("element - %d : ",i+1);
        scanf("%d",&numbers[i]);
    }
    printf("\nThe elements in the array after sorting :\n");

    

    quicksort(numbers,0,n-1);

    for (i=0;i<n;i++){
        printf("element - %d : %d\n",i+1,numbers[i]);
    }
    
    return 0;
}


void quicksort(int *array, int start, int end){
    int new;
    int *point;
    point = &new;

    if (start < end){
        reorder(array,start,end,point);
        quicksort(array,start,new);
        quicksort(array,new+1,end);
    }

    
}

void reorder(int *array, int start, int end, int *new){
    int pivot = array[(end+start)/2];
    int i, j;
    
    i = start - 1;
    j = end + 1;

    while (1){
        do{
            i++;
        }
        while (array[i] < pivot);

        do{
            j--;
        }
        while (array[j] > pivot);

        if (i >= j){
            *new = j;
            break;
        }
        swap(array,i,j);
    }

}


void swap(int *array,int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}