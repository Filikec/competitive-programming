#include <iostream>
#include <list>
#include <climits>
#include <cmath>

using namespace std;


long double getDist(int x1, int y1, int x2, int y2){
    int xD, yD;
    xD = x1-x2;
    yD = y1-y2;
    return sqrt(xD*xD+yD*yD);
}

pair<int,int> Stops[202];
long double Time[202][202], Solution[202];
int Used[202];

int main(){

    cin >> Stops[0].first >> Stops[0].second >> Stops[1].first >> Stops[1].second;

    for (int i=0;i<202;i++) for (int j=0;j<202;j++) Time[i][j] = -1;

    int curI = 1;
    while (!cin.eof()){
        curI++;
        cin >> Stops[curI].first >> Stops[curI].second;
        int x,y;
        cin >> x >> y;
        
        while (x != -1){
            Stops[++curI] = {x,y};
            Time[curI][curI-1] = Time[curI-1][curI] = getDist(x,y,Stops[curI-1].first,Stops[curI-1].second)/666.666666666;
            cin >> x >> y;
        }
    }
    

    for (int i=0;i<202;i++) 
        for (int j=0;j<202;j++) 
            if (Time[i][j]==-1) 
                Time[i][j] = getDist(Stops[i].first,Stops[i].second,Stops[j].first,Stops[j].second)/166.6666667;

    for (int i=1;i<202;i++){
        Solution[i] = INT32_MAX;
    }

    Used[0] = 1;
    list<int> queue;
    queue.push_back(0);


    while (queue.size()){
        int cur = queue.front();
        queue.pop_front();
        Used[cur] = 0;

        for (int i=0;i<202;i++){
            if (Solution[i] > Solution[cur]+Time[cur][i]){
                Solution[i] = Solution[cur]+Time[cur][i];
                if (!Used[i]) queue.push_back(i), Used[i] = 1;
            }
        }
    }

    cout << round(Solution[1]) << '\n';

    return 0;
}