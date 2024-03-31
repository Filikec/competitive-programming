#include <iostream>
#include <set>

using namespace std;


pair<pair<int,int>,pair<int,int>> getD(int x, int y){
    pair<int,int> left = {x-min(x,y),y-min(x,y)};
    pair<int,int> right = {x-min(x,y),y+min(x,y)};
    return {left,right};
}

int main(){

    int n;

    cin >> n;

    set<pair<int,int>> usedL,usedR;
    set<int> usedX, usedY;

    for (int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        auto d = getD(x,y);
        if (usedX.count(x) || usedY.count(y) || usedL.count(d.first) || usedR.count(d.second)){
            cout << "INCORRECT\n";
            return 0;
        }
        usedX.insert(x);
        usedY.insert(y);
        usedL.insert(d.first);
        usedR.insert(d.second);
    }

    cout << "CORRECT\n";


    return 0;
}