#include <iostream>
#include <queue>

using namespace std;

char Graph[50][50];


void get_step(int n,int m){
    char New_graph[50][50];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            New_graph[i][j] = '.';
            if (Graph[i][j]=='X'){
                New_graph[i][j] = 'X';
                continue;
            }else if (Graph[i][j]=='*'){
                New_graph[i][j] = '*';
                continue;
            }else if (Graph[i][j]=='D'){
                New_graph[i][j] = 'D';
                continue;
            }
            if (i && Graph[i-1][j]=='*') New_graph[i][j] = '*';
            if (j && Graph[i][j-1]=='*') New_graph[i][j] = '*';
            if (i+1<n && Graph[i+1][j]=='*') New_graph[i][j] = '*';
            if (j+1<m && Graph[i][j+1]=='*') New_graph[i][j] = '*';
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            Graph[i][j] = New_graph[i][j];
        }
    }
}

typedef struct move{
    int n,m,move;
} Move;

void bfs(int end_n,int end_m,int start_n,int start_m, int n, int m){
    int moves = -1, step = -1;
    Move start = {start_n,start_m,0};
    queue<Move> queue;
    queue.push(start);
    int Used[50][50];
    for (int i =0;i<n;i++){
        for (int j=0;j<m;j++){
            Used[i][j] = 0;
        }
    }
    while (!queue.empty()){
        Move curr = queue.front();
        queue.pop();
        if (curr.move > step){
            step = curr.move;
            get_step(n,m);
        }
        if (curr.n == end_n && curr.m==end_m){
            moves = curr.move;
            break;
        }
        Move new_move;
        if (curr.n && !Used[curr.n-1][curr.m] && Graph[curr.n-1][curr.m]!='X' && Graph[curr.n-1][curr.m]!='*'){
            new_move = {curr.n-1,curr.m,curr.move+1};
            queue.push(new_move);
            Used[curr.n-1][curr.m] = 1;
        }
        if (curr.n+1 < n && !Used[curr.n+1][curr.m] && Graph[curr.n+1][curr.m]!='X' && Graph[curr.n+1][curr.m]!='*'){
            new_move = {curr.n+1,curr.m,curr.move+1};
            queue.push(new_move);
            Used[curr.n+1][curr.m] = 1;
        }
        if (curr.m && !Used[curr.n][curr.m-1] && Graph[curr.n][curr.m-1]!='X' && Graph[curr.n][curr.m-1]!='*'){
            new_move = {curr.n,curr.m-1,curr.move+1};
            queue.push(new_move);
            Used[curr.n][curr.m-1] = 1;
        }
        if (curr.m+1 < m && !Used[curr.n][curr.m+1] && Graph[curr.n][curr.m+1]!='X' && Graph[curr.n][curr.m+1]!='*'){
            new_move = {curr.n,curr.m+1,curr.move+1};
            queue.push(new_move);
            Used[curr.n][curr.m+1] = 1;
        }
    }
    if (moves==-1){
        cout << "KAKTUS\n";
    }else{
        cout << moves << "\n";
    }
}

int main(){
    
    int n,m;
    int end_n,end_m,start_n,start_m;

    cin >> n >> m;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> Graph[i][j];
            if (Graph[i][j] == 'D'){
                end_n = i;
                end_m = j;
            }else if(Graph[i][j]=='S'){
                start_n = i;
                start_m = j;
            }
        }
    }

    bfs(end_n,end_m,start_n,start_m,n,m);

    return 0;
}