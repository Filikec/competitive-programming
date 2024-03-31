#include <iostream>
#include <algorithm>
#include

using namespace std;

typedef struct rect{
    struct rect *parent;
    long long area;
    long long x,y,w,h;
} Rect;

Rect Stones[50000];
int S; 

bool are_connected(Rect *r1, Rect *r2){
    Rect *left, *right, *down, *up;

    if (r1->x < r2->x){
        left = r1;
        right = r2;
    }else{
        left = r2;
        right = r1;
    }

    if (r1->y < r2->y){
        down = r1;
        up = r2;
    }else{
        up = r1;
        down = r2;
    }

    if (left->x+left->w >= right->x && down->y+down->h >= up->y){
        return true;
    }
    return false;
}

Rect * get_parent(Rect *stone){
    Rect *parent = stone->parent;
    while (parent){
        stone = stone->parent;
        parent = stone->parent;
    }
    return stone;
}

bool compare(Rect r1, Rect r2){
    return r1.x < r2.x;
}


int main(){
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Stones[S].x >> Stones[S].y >> Stones[S].w >> Stones[S].h;
        Stones[S].parent = NULL;
        Stones[S].area = Stones[S].w*Stones[S].h;
        S++;
    }

    sort(Stones,Stones+S,compare);

    for (int i=0;i<n;i++){
        int tmp = Stones[i].x + Stones[i].w;
        for (int j=i+1;j<n && Stones[j].x <= tmp ;j++){
            if (are_connected(&Stones[i],&Stones[j])){
                Rect *p1 = get_parent(&Stones[i]);
                Rect *p2 = get_parent(&Stones[j]);
                if (p1 == p2){
                    continue;
                }
                p2->parent = p1;
                p1->area += p2->area;
            }
        }
    }


    long long maximum = 0;
    for (int i=0;i<n;i++){
        if (!Stones[i].parent){
            maximum = max(maximum,Stones[i].area);
        }
    }

    cout << maximum << "\n";
    return 0;
}