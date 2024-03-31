#include <iostream>
#include <list>
#include <climits>

using namespace std;


int loadSide(list<pair<int,int>> *side, int time, int cap, list<pair<int,int>> *loaded){
    int n=0;
    while (side->size() && side->front().first <= time && n < cap){
        auto cur = side->front();
        side->pop_front();
        loaded->push_back({cur.second,time});
        n++;
    }

    return n;
}


int getTime(list<pair<int,int>> *side){
    if (side->empty()) return INT_MAX;
    return side->front().first;
}

void work(){
    int n,t,m;

    cin >> n >> t >> m;

    list<pair<int,int>> left,right;

    for (int i=0;i<m;i++){
        int time;
        string side;
        cin >> time >> side;

        if (side == "left"){
            left.push_back({time,i});
        }else{
            right.push_back({time,i});
        }
    }

    auto curSide = &left, difSide = &right; 
    int curTime = 0, carrying=0;

    list<pair<int,int>> loaded;

    while (left.size() || right.size()){
        carrying = 0;
        if ((carrying = loadSide(curSide,curTime,n,&loaded))){
            curTime += t;
        }else if (getTime(curSide) < getTime(difSide)){
            carrying = loadSide(curSide,curTime,n,&loaded);
            if (!carrying) curTime = getTime(curSide), carrying = loadSide(curSide,curTime,n,&loaded);
            curTime += t;
        }else{
            curTime = getTime(difSide) + t;
        }
        auto tmp = curSide;
        curSide = difSide;
        difSide = tmp;
    }

    loaded.sort([&] (pair<int,int> p1, pair<int,int> p2){ return p1.first < p2.first;});
    for (auto c : loaded) cout << c.second+t << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        if (i) cout << "\n";
        work();
    }

    return 0;
}