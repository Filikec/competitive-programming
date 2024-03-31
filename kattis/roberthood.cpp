#include <iostream>

using namespace std;

typedef struct point{
    int x,y;
} Point;

bool Arrow[2001][2001];
Point Points[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Points[i].x >> Points[i].y;
        Points[i].x += 1000;
        Points[i].y += 1000;

        Arrow[Points[i].x][Points[i].y] = 1;
    }



    int max_dist=0;

    for (int i=0;i<n;i++){
        for (int d=1;d<=4000&&d>max_dist;d++){
            int x,y;
            x = Points[i].x;
            y = Points[i].y;

                
        }
    }

    return 0;
}