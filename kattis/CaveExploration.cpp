#include <iostream>
#include <list>
#include <set>


using namespace std;

int Height[100][100];
int N;

int possible(int i,int j, int height){
    return  i>=0 && j >= 0 && i<N && j <N && Height[i][j] < height;
}

int getIndex(int i, int j){
    return i*100+j;
}

bool can(int maxHeight){

    list<int> queue;
    queue.push_back(0);
    set<int> Visited;

    while (queue.size()){
        auto cur = queue.front();
        queue.pop_front();
        if (Visited.count(cur)) continue;
        Visited.insert(cur);
        int i = cur/100, j = cur%100;
        if (i==N-1 && j == N-1) return true;
        if (possible(i-1,j,maxHeight)){
            queue.push_back(getIndex(i-1,j));
        }

        if (possible(i+1,j,maxHeight)){
            queue.push_back(getIndex(i+1,j));
        }

        if (possible(i,j-1,maxHeight)){
            queue.push_back(getIndex(i,j-1));
        }

        if (possible(i,j+1,maxHeight)){
            queue.push_back(getIndex(i,j+1));
        }


    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d",&N);

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf("%d",&Height[i][j]);
        }
    }

    int a=1,b=100000000;

    while (a<b){
        int mid = (a+b)/2;
        if (can(mid)){
            b = mid;
        }else{
            a = mid+1;
        }
    }

    printf("%d\n",a-1);

    return 0;
}