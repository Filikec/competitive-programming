#include <iostream>
#include <list>
#include <set>



using namespace std;


list<pair<int,int>> Graph[12][12];



int getPlayer(int sum){
    if (!sum) return 0;
    sum--;
    return ((sum/2)%2);
}

bool bfs(pair<int,int> s, pair<int,int> t){
    list<pair<int,int>> queue;
    queue.push_back(s);

    set<pair<int,int>> used;

    while (queue.size()){
        auto cur = queue.front();
        queue.pop_front();

        if (used.count(cur)) continue;
        used.insert(cur);

        if (cur == t) return true;

        for (auto neigh : Graph[cur.first][cur.second]){
            queue.push_back(neigh);
        }
    }

    return false;
}



int main(){
    list<pair<int,int>> queue;
    set<pair<int,int>> visited;

    queue.push_back({0,0});

    while (queue.size()){
        auto cur = queue.front();
        queue.pop_front();

        if (cur.first == 11 || cur.second == 11 || visited.count(cur)) continue;
        visited.insert(cur);

        int curSum = cur.first + cur.second;

        int nextA = cur.first, nextB = cur.second;
        if (getPlayer(curSum) != getPlayer(curSum+1)){
            nextA = cur.second;
            nextB = cur.first; 
        }
        
        Graph[cur.first][cur.second].push_back({nextA+1,nextB});
        Graph[cur.first][cur.second].push_back({nextA,nextB+1});
        queue.push_back({nextA+1,nextB});
        queue.push_back({nextA,nextB+1});
    }


    int n;
    cin >> n;


    list<pair<int,int>> scores;


    for (int i=0;i<n;i++){
        int a,b;
        cin >> a;
        cin.get();
        cin >>b;
        scores.push_back({a,b});
    }
    
    pair<int,int> prev = {0,0};
    int i=0;
    for (auto s : scores){
        i++;
        if (!bfs(prev,s)){
            cout << "error " << i << '\n';
            return 0;
        }
        prev = s;
    }
    cout << "ok\n";

    return 0;
}