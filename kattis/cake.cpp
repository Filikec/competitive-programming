#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


typedef struct rect{
    int x1,y1,x2,y2;
} Rect;

int P, Q, N, R;
Rect Rectangles[100000001];
vector<int> Rows[10001];

bool compare(int r1, int r2){
    return Rectangles[r1].y1 > Rectangles[r2].y1;
}

int main(){
    cin >> P >> Q >> N;

    for (int i=0;i<N;i++){
        int x, y;
        scanf("%d %d",&x,&y);
        Rectangles[R].x1 = x;
        Rectangles[R].x2 = x;
        Rectangles[R].y1 = y;
        Rectangles[R].y2 = y;
        Rows[x].push_back(R++);
    }

    bool placed = false;

    for (int i=1;i<=P;i++){
        if (Rows[i].size()){
            sort(Rows[i].begin(),Rows[i].end(),compare);
            Rectangles[Rows[i].back()].y1 = 1;
            if (!placed){
                placed = true;
                Rectangles[Rows[i].back()].x1 = 1;
            }
        }
        while (Rows[i].size()){
            int r = Rows[i].back();
            Rows[i].pop_back();

            if (Rows[i].size()){
                Rectangles[r].y2 = Rectangles[Rows[i].back()].y1-1;
                Rectangles[Rows[i].back()].x1 = Rectangles[r].x1;
            }else{
                Rectangles[r].y2 = Q;
            }
            int x2 = i+1;
            while (!Rows[x2].size() && x2 <= P){
                x2++;
            }
            x2--;
            Rectangles[r].x2 = x2;
        }
        
    }

    
    for (int i=0;i<N;i++){
        printf("%d %d %d %d\n",Rectangles[i].x1,Rectangles[i].y1,Rectangles[i].x2,Rectangles[i].y2);
    }
    cout << 0 << "\n";


    return 0;
}