#include <bits/stdc++.h>

using namespace std;


char G[1000][1000];
bool V[1000][1000];
char P[1000][1000];

int n,m;

void bfs(int i,int j){
    list<pair<int,int>> q = {{i,j}};
    V[i][j] = 1;

    while (q.size()){
        auto cur = q.front();
        q.pop_front();

        if (cur.first && !V[cur.first-1][cur.second] && G[cur.first-1][cur.second] != '#') q.push_back({cur.first-1,cur.second}),V[cur.first-1][cur.second]=1, P[cur.first-1][cur.second]='U';
        if (cur.second && !V[cur.first][cur.second-1] && G[cur.first][cur.second-1] != '#') q.push_back({cur.first,cur.second-1}),V[cur.first][cur.second-1]=1, P[cur.first][cur.second-1]='L';

        if (cur.first+1<n && !V[cur.first+1][cur.second] && G[cur.first+1][cur.second] != '#') q.push_back({cur.first+1,cur.second}), V[cur.first+1][cur.second]=1,P[cur.first+1][cur.second]='D';
        if (cur.second+1<m && !V[cur.first][cur.second+1] && G[cur.first][cur.second+1] != '#') q.push_back({cur.first,cur.second+1}),V[cur.first][cur.second+1]=1,P[cur.first][cur.second+1]='R';
    }
}

int main(){
    cin >> n >> m;

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) cin >> G[i][j];


    long long count = 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (G[i][j] == 'A') bfs(i,j);

    pair<int,int> end;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (G[i][j] == 'B') end= {i,j};

    list<char> l;
    while (P[end.first][end.second]){
        l.push_front(P[end.first][end.second]);
        if (P[end.first][end.second] == 'L') end.second++;
        else if (P[end.first][end.second] == 'R') end.second--;
        else if (P[end.first][end.second] == 'U') end.first++;
        else end.first--;
    }
    
    for (auto c : l) cout << c;
    cout << '\n';

    return 0;
}