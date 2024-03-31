#include <iostream>
#include <list>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

int Graph[4000][4000], TransG[4000][4000], ComplG[4000][4000];
bool Compl, Trans;


int main(){
    int v,e,q;

    scanf("%d %d %d",&v,&e,&q);

    for (int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        Graph[a][b] = 1;
    }

    for (int i=0;i<q;i++){
        int type, a, b;
        scanf("%d",&type);
        if (type==1){
            v++;
            if (Compl){
                for (int i=0;i<v-1;i++){
                    Graph[i][v-1] = 1;
                    Graph[v-1][i] = 1;
                }
            }
        }else if (type==2){
           scanf("%d %d",&a, &b);
           if (Trans) swap(a,b);
           if (Compl) Graph[a][b] = 0;
           else Graph[a][b] = 1;
        }else if (type==3){
            scanf("%d",&a);
            if (Compl){
                for (int i=0;i<v;i++){
                    if (i != a){
                        Graph[a][i] = 1;
                        Graph[i][a] = 1;
                    }
                }
            }else{
                for (int i=0;i<v;i++) Graph[i][a] = 0, Graph[a][i] = 0;
            }
        }else if (type==4){
            scanf("%d %d",&a, &b);
            if (Trans) swap(a,b);
            if (Compl) Graph[a][b] = 1;
            else Graph[a][b] = 0;
        }else if (type == 5){
            Trans = !Trans;
        }else{
            Compl = !Compl;
        }
    }

    printf("%d\n",v);

    if (Trans){
        for (int i=0;i<v;i++){
            for (int j=0;j<v;j++){
                if (j==i) continue;
                if (Graph[i][j]) TransG[j][i] = 1;
            }
        }
    }
    if (Compl){
        auto *g = Graph;
        if (Trans) g = TransG;
        for (int i=0;i<v;i++){
            for (int j=0;j<v;j++){
                if (j==i) continue;
                if (!g[i][j]) ComplG[i][j] = 1;
            }
        }
    }

    auto *finalG = Graph;

    if (Compl){
        finalG = ComplG;
    }else if (Trans) finalG = TransG;

    for (int i=0;i<v;i++){
        long long h = 0;
        long long sevenP = 1;
        long long count = 0;
        for (int j=0;j<v;j++){
            if (j == i || finalG[i][j]==0) continue;
            count++;
            h = (h + sevenP * j) % 1000000007;
            sevenP = (sevenP*7) % 1000000007;
        }
         printf("%lld %lld\n",count,h);
    }
    

    return 0;
}