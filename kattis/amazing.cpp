#include <iostream>
#include <list>

#define OFFSET 100

using namespace std;

int Visited[200][200], Used;

bool dfs(pair<int,int> curr, pair<int,int> prev){
    int x = curr.first, y = curr.second;
    string a;
    
    Visited[x][y] = 1;

    if (!Visited[x+1][y]){
        cout << "right\n" << flush;
        cin >> a;
        if (a == "solved"){
            return true;
        }else if (a == "ok"){
            if (dfs(make_pair(x+1,y),curr)) return true;
        }
    }

    if (!Visited[x-1][y]){
        cout << "left\n" << flush;
        cin >> a;
        if (a == "solved"){
            return true;
        }else if (a == "ok"){
            if (dfs(make_pair(x-1,y),curr)) return true;
        }
    }
    
    if (!Visited[x][y+1]){
        cout << "up\n" << flush;
        cin >> a;
        if (a == "solved"){
            return true;
        }else if (a == "ok"){
            if (dfs(make_pair(x,y+1),curr)) return true;
        }
    }
    
    if (!Visited[x][y-1]){
        cout << "down\n" << flush;
        cin >> a;
        if (a == "solved"){
            return true;
        }else if(a == "ok"){
            if (dfs(make_pair(x,y-1),curr)) return true;
        }
    }
    if (curr == prev) return false;
   
    if (curr.first != prev.first){
        if (curr.first > prev.first){
            cout << "left\n" << flush;
        }else{
            cout << "right\n" << flush;
        }
    }else{
        if (curr.second > prev.second){
            cout << "down\n" << flush;
        }else{
            cout << "up\n" << flush;
        }
    }

    cin >> a;

    return false;
}   


int main(){

    Visited[OFFSET][OFFSET] = 1;
    if (!dfs(make_pair(OFFSET,OFFSET),make_pair(OFFSET,OFFSET))) cout << "no way out\n";

    return 0;   
}