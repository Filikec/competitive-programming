#include <bits/stdc++.h>

#define INF 1000000

using namespace std;

typedef struct stone{
    int height, left_j, right_j, best;
    int left, right;
} Stone;

Stone Stones[1000000]; 

void find_best(int i){
    list<int> stack;
    
    stack.push_front(i);

    int jumps = -1;
    while (stack.size()){
        int current = stack.front();
        if (current == -1){
            jumps = INF;
            stack.pop_front();
            continue;
        }

        if (Stones[current].best != -1){
            jumps = Stones[current].best;
            stack.pop_front();
            continue;
        }

        if (jumps != -1){
            if (Stones[current].right_j == -1){
                Stones[current].right_j = jumps+1;
                jumps = -1;
                stack.push_front(Stones[current].left);
            }else{
                Stones[current].left_j = jumps+1;
                Stones[current].best = min(Stones[current].left_j,Stones[current].right_j);
                jumps = Stones[current].best;
                stack.pop_front();
            }
            continue;
        }

        if (Stones[current].left == -1 && Stones[current].right == -1){
            Stones[current].best = 0;
            jumps = 0;
            stack.pop_front();
            continue;
        }

        stack.push_front(Stones[current].right);
    }
}

int get_num(){
    char c;
    int num = 0;
    while ((c = getchar()) >= '0'){
        num *= 10;
        num += c-'0';
    }
    return num;
}

int main(){
    int n;

    n = get_num();

    for (int i=0;i<n;i++){
        Stones[i].height = get_num();
        Stones[i].left_j = -1;
        Stones[i].right_j = -1;
        Stones[i].right = -1;
        Stones[i].best = -1;
        Stones[i].left = -1;
    }

    list<int> queue;
    for (int i=0;i<n;i++){
        while (queue.size() && Stones[queue.front()].height <= Stones[i].height){
            queue.pop_front();
        }
        if (queue.size()){
            Stones[i].left = queue.front();
        }else{
            Stones[i].left = -1;
        }
        queue.push_front(i);
    }

    queue.clear();
    for (int i=n-1;i>=0;i--){
        while (queue.size() && Stones[queue.front()].height <= Stones[i].height){
            queue.pop_front();
        }
        if (queue.size()){
            Stones[i].right = queue.front();
        }else{
            Stones[i].right = -1;
        }
        queue.push_front(i);
    }

    for (int i=0;i<n;i++){
        find_best(i);
    }

    for (int i=0;i<n;i++){
        printf("%d ",Stones[i].best);
    }
    putchar('\n');

    return 0;
}

/*
5
9 6 5 4 7 5
0 1 2 2 1 2
*/
