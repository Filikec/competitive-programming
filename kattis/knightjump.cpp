#include <iostream>
#include <list>

using namespace std;

char Squares[100][100], Visited[100][100];
pair<int,int> Knight;
int N;

bool validate(int x, int y){
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    if (Squares[x][y] == '#' || Visited[x][y]) return false;
    return true;
}

int main(){

    cin >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> Squares[i][j];
            if (Squares[i][j] == 'K'){
                Knight.first = i;
                Knight.second = j;
            }
        }
    }


    list<pair<int,int>> queue;
    queue.push_back(Knight);
    Visited[Knight.first][Knight.second] = 1;


    while (!queue.empty()){
        auto curr = queue.front();
        queue.pop_front();


        if (validate(curr.first+1,curr.second+2)){
            queue.push_back(make_pair(curr.first+1,curr.second+2));
            Visited[curr.first+1][curr.second+2] = Visited[curr.first][curr.second]+1;
        }
        
        if (validate(curr.first+1,curr.second-2)){
            queue.push_back(make_pair(curr.first+1,curr.second-2));
            Visited[curr.first+1][curr.second-2] = Visited[curr.first][curr.second]+1;
        }

        
        if (validate(curr.first+2,curr.second+1)){
            queue.push_back(make_pair(curr.first+2,curr.second+1));
            Visited[curr.first+2][curr.second+1] = Visited[curr.first][curr.second]+1;
        }
        
        if (validate(curr.first+2,curr.second-1)){
            queue.push_back(make_pair(curr.first+2,curr.second-1));
            Visited[curr.first+2][curr.second-1] = Visited[curr.first][curr.second]+1;
        }
            //
        if (validate(curr.first-1,curr.second+2)){
            queue.push_back(make_pair(curr.first-1,curr.second+2));
            Visited[curr.first-1][curr.second+2] = Visited[curr.first][curr.second]+1;
        }
        
        if (validate(curr.first-1,curr.second-2)){
            queue.push_back(make_pair(curr.first-1,curr.second-2));
            Visited[curr.first-1][curr.second-2] = Visited[curr.first][curr.second]+1;
        }

        
        if (validate(curr.first-2,curr.second+1)){
            queue.push_back(make_pair(curr.first-2,curr.second+1));
            Visited[curr.first-2][curr.second+1] = Visited[curr.first][curr.second]+1;
        }
        
        if (validate(curr.first-2,curr.second-1)){
            queue.push_back(make_pair(curr.first-2,curr.second-1));
            Visited[curr.first-2][curr.second-1] = Visited[curr.first][curr.second]+1;
        }
    }

    if (!Visited[0][0]){
        cout << "-1\n";
    }else{
        cout << Visited[0][0]-1 << '\n';
    }

    return 0;
}