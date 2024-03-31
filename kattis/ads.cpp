#include <iostream>
#include <list>
#include <set>

using namespace std;


char Window[201][201];
bool Visited[201][201];
int W,H;


bool isAllowed(char c){
    if (c >='a' && c<='z') return true;
    if (c >='A' && c <= 'Z') return true;
    if (c >= '0' && c <= '9') return true;
    if (c == '?' || c == '!' || c == ',' || c== '.' || c == ' ' || c == '+') return true;


    return false;
}

bool inBounds(int i, int j){
    return (i>-1 && i<H && j>-1 && j<W);
}

void deleteImage(int i,int j){
    list<pair<int,int>> queue;

    queue.push_back({i,j});

    set<pair<int,int>> visited;
    visited.insert({i,j});

    int up=201,down=0,left=201,right=0;

    while (queue.size()){
        auto cur = queue.front();
        queue.pop_front();

        int curI = cur.first, curJ = cur.second;

        up = min(up,curI);
        down = max(down,curI);

        left = min(left,curJ);
        right = max(right,curJ);

        for (int k=-1;k<2;k++){
            for (int l=-1;l<2;l++){
                int nextI = curI+k, nextJ = curJ+l;
                if (inBounds(nextI,nextJ) && !visited.count({nextI,nextJ}) 
                && Window[nextI][nextJ] != '+'){
                    visited.insert({nextI,nextJ});
                    queue.push_back({nextI,nextJ});
                }
            }
        }
    }

    left--;
    right++;
    up--;
    down++;

    if (left<0||right>=W||up<0||down>=H){
        for (auto p : visited){
            Visited[p.first][p.second] = 1;
        }
    }

    for (int k=up;k<=down;k++){
        for (int l=left;l<=right;l++){
            Window[k][l] = ' ';
        }
        return;
    }
}

int main(){



    cin >> H >> W;

    
    
    for (int i=0;i<H;i++){
        cin.get();
        for (int j=0;j<W;j++){
            Window[i][j] = cin.get();
        }
        
    }
    
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            char c = Window[i][j];

            if (!isAllowed(c) && !Visited[i][j]){
                deleteImage(i,j);
            }

        }
    }

    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            cout << Window[i][j];
        }
        cout << '\n';
    }
    cout << '\n';


    return 0;
}