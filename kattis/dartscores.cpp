#include <iostream>
#include <cmath>

using namespace std;


int main(){

    int cases;

    scanf("%d",&cases);

    for (int c=0;c<cases;c++){
        int n,score=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            int x,y;
            double dist;
            scanf("%d %d",&x,&y);
            dist = sqrt(x*x+y*y);
            if (dist>200) continue;
            if (dist/20==(int)(dist/20)&&dist) score++;
            score += 10-(int)((dist)/20);
        }
        printf("%d\n",score);
    }



    return 0;
}