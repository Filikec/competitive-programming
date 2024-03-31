#include <iostream>
#include <queue>
#include <list>

#define INF 1000001

using namespace std;

typedef struct state{
    int x,y,step;
} State;

int Board[22][50][50];
int States[22][50][50];
int Max_steps,X,Y,Goal,Start;

void process(){
    list<int> Rows[22];

    for (int i=0;i<X;i++){
        for (int j=0;j<Y;j++){
            Rows[i].push_back(Board[i][j][0]);
        }
    }
    
    for (int i=1;i<Y;i++){
        for (int j=X-2;j>=0;j--){
            if (j%2==(X-2)%2){
                int tmp = Rows[j].back();
                Rows[j].pop_back();
                Rows[j].push_front(tmp);
            }else{
                int tmp = Rows[j].front();
                Rows[j].pop_front();
                Rows[j].push_back(tmp);
            }
            int k=0;
            for (auto el : Rows[j]){
                Board[j][k++][i] = el;
            }
        }
    }
}

bool is_safe(int x, int y, int delta){
    if (x<0 || x >= X || y < 0 || y >= Y) return false;
    return !Board[x][y][delta%Y];

}

void bfs(){
    queue<State> queue;
    State start;
    start.step = 0;
    start.x = X-1;
    start.y = Start;
    queue.push(start);

    while (!queue.empty()){
        State current = queue.front();
        queue.pop();
       
        if (!current.x && current.y == Goal){
            cout << "The minimum number of turns is "<< current.step << ".\n";
            return;
        }   
        
        if (current.step == Max_steps) continue;
        
        State new_state;
        new_state.step = current.step+1;
        if (is_safe(current.x,current.y,new_state.step) && States[current.x][current.y][new_state.step%Y] > new_state.step){
            new_state.x = current.x;
            new_state.y = current.y;
            //cout << new_state.x << " " << new_state.y << " " << new_state.step << "<\n";
            queue.push(new_state);
        }
        if (is_safe(current.x+1,current.y,new_state.step) && States[current.x+1][current.y][new_state.step%Y] > new_state.step){
            States[current.x+1][current.y][new_state.step%Y] = new_state.step;
            new_state.x = current.x+1;
            new_state.y = current.y;
            //cout << new_state.x << " " << new_state.y << " " << new_state.step << "<\n";
            queue.push(new_state);
        }
        if (is_safe(current.x-1,current.y,new_state.step) && States[current.x-1][current.y][new_state.step%Y] > new_state.step){
            States[current.x-1][current.y][new_state.step%Y] = new_state.step;
            new_state.x = current.x-1;
            new_state.y = current.y;
            //cout << new_state.x << " " << new_state.y << " " << new_state.step << "<\n";
            queue.push(new_state);
        }
        if (is_safe(current.x,current.y+1,new_state.step) && States[current.x][current.y+1][new_state.step%Y] > new_state.step){
            States[current.x][current.y+1][new_state.step%Y] = new_state.step;
            new_state.x = current.x;
            new_state.y = current.y+1;
            //cout << new_state.x << " " << new_state.y << " " << new_state.step << "<\n";
            queue.push(new_state);
        }
        if (is_safe(current.x,current.y-1,new_state.step) && States[current.x][current.y-1][new_state.step%Y] > new_state.step){
            States[current.x][current.y-1][new_state.step%Y] = new_state.step;
            new_state.x = current.x;
            new_state.y = current.y-1;
            //cout << new_state.x << " " << new_state.y << " " << new_state.step << "<\n";
            queue.push(new_state);
        }

    }

    cout << "The problem has no solution.\n";

}

void work(){
    cin >> Max_steps;

    cin >> X >> Y;
    X += 2;
    getchar();
    for (int i=0;i<X;i++){
        for (int j=0;j<Y;j++){
            for (int k=0;k<Y;k++){
                States[i][j][k] = INF;
                Board[i][j][k] = 0;
            }
            char tmp = getchar();
            
            if (tmp == 'X'){
                Board[i][j][0] = 1;
            }else if (tmp == 'G'){
                Goal = j;
            }else if(tmp == 'F'){
                Start = j;
            }
        }
        getchar();
    }

    for (int i=0;i<Y;i++){
        States[X-1][Start][i] = 0;
    }

    process();
    bfs();

}

int main(){
    int cases;

    cin >>cases;

    for (int c=0;c<cases;c++){
        work();
    }

}