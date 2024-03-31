#include <iostream>

using namespace std;

int M, N;

int find_prev(int &i){
    int tmp = M+1, prev = -M;
    for (i;i<N&&tmp!=M;i++){
        scanf("%d",&tmp);
        
        if (tmp < M){
            prev = -M;
        }else{
            prev += tmp;
        }
    }
    
    return prev;
}

int work(){
    int after = 0, biggest = 0, prev = 0, tmp;
    int i = 0;
    scanf("%d %d",&N,&M);
    prev = find_prev(i);
    for (i;i<N;i++){
        scanf("%d",&tmp);
        if (tmp < M){
            biggest = max(biggest,prev+after+M);
            after = 0;
            prev = find_prev(++i);
            i--;            
        }else if (tmp == M){
            biggest = max(biggest,prev+after+M);
            prev = after;   
            after = 0;
        }else{
            after += tmp;
        }
    }
    biggest = max(biggest,prev+after+M);
    return biggest;
}

int main(){

    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
       cout << work() << "\n";
    }


    return 0;
}