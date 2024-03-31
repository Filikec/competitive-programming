#include <bits/stdc++.h>


using namespace std;



list<int> Graph[200001];
int Partners[200001][2]; // 0 - how many at start, 1 - how many lost
int Left[200001]; // 0 - didn't leave union, 1 - left union

int get_integer(){
    int result = 0;
    char c;

    while ((c = getchar())>='0'){
        result = result*10+c-'0';
    }
    return result;
}

int main(){
    int n, e, h, l;

    n = get_integer();
    e = get_integer();
    h = get_integer();
    l = get_integer();


    for (int i=0;i<e;i++){
        int a,b;
        a = get_integer();
        b = get_integer();

        Graph[a].push_back(b);
        Partners[a][0]++;
        Graph[b].push_back(a);
        Partners[b][0]++;
    }

    list<int> queue;
    queue.push_back(l);
    Left[l] = 1;

    while (queue.size()){
        int curr = queue.front();
        queue.pop_front();

        for (auto neigh : Graph[curr]){
            if (Left[neigh]) continue;

            Partners[neigh][1]++; // increment value of partners they lost
            if (Partners[neigh][0] <= Partners[neigh][1]*2) queue.push_back(neigh), Left[neigh] = 1;
        }
    }

    if (Left[h]){
        cout << "leave\n";
    }else{
        cout << "stay\n";
    }

    return 0;
}