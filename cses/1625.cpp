#include <bits/stdc++.h>

using namespace std;

int V[7][7];

int r(pair<int,int> cur, int i, string &s){

    if (6 - cur.first + cur.second > s.size()-i) return 0;
    if (cur == make_pair(6,0)) return i == s.size();
    if (i == s.size()) return 0;

    int res=0;
    if ((s[i] == 'D' || s[i] == '?') && cur.first+1<7 && !V[cur.first+1][cur.second]){
        V[cur.first+1][cur.second]=1;
        res += r({cur.first+1,cur.second},i+1,s);
        V[cur.first+1][cur.second]=0;
    }

    if ((s[i] == 'U' || s[i] == '?') && cur.first && !V[cur.first-1][cur.second]){
        V[cur.first-1][cur.second]=1;
        res += r({cur.first-1,cur.second},i+1,s);
        V[cur.first-1][cur.second]=0;
    }

    if ((s[i] == 'L' || s[i] == '?') && cur.second && !V[cur.first][cur.second-1]){
        V[cur.first][cur.second-1]=1;
        res += r({cur.first,cur.second-1},i+1,s);
        V[cur.first][cur.second-1]=0;
    }

    if ((s[i] == 'R' || s[i] == '?') && cur.second+1<7 && !V[cur.first][cur.second+1]){
        V[cur.first][cur.second+1]=1;
        res += r({cur.first,cur.second+1},i+1,s);
        V[cur.first][cur.second+1]=0;
    }

    return res;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;   

    cout << r({0,0},0,s) << '\n';
    

    
}