#include <iostream>
#include <list>

using namespace std;

int Graph[26][26], Visited[26];
char Prev[700];

int main(){
    int n,m,k;

    cin >> n >> m >> k;
    getchar();
    
    for (int i=0;i<n;i++){  
        for (int j=0;j<m;j++){
            char c = getchar();
            if (Prev[j] && Prev[j]!=c && !Graph[Prev[j]-'A'][c-'A']){
                Graph[Prev[j]-'A'][c-'A'] = 1;
                Graph[c-'A'][Prev[j]-'A'] = 1;
            }
            Prev[j] = c;
        }
        getchar();
    }

    int count = 0;
    for (int i=0;i<k;i++){
        if (Visited[i]) continue;
        count++;
        list<int> queue;
        queue.push_back(i);
        while (!queue.empty()){
            int curr = queue.front();
            queue.pop_front();
            Visited[curr] = 1;
            
            for (int j=0;j<k;j++){
                if (Graph[curr][j] && !Visited[j]) queue.push_back(j), Visited[j]=1;
            }
        }
    }


    printf("%d\n",count);

    return 0;
}
