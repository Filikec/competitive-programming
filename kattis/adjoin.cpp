#include <iostream>
#include <list>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

unordered_map<string,int> Depths;
list<int> Graph[100000];
list<int> Bests;
int Visited[100000];
int Max[100000];



int dfs(int current,int parent){
    int most = 0;

    for (auto neigh : Graph[current]){
        if (neigh == parent){
            continue;
        }
        string edge = to_string(current) + "->"+to_string(neigh);
        if (Depths.count(edge) && Depths[edge] > most){
            most = Depths[edge];
        }else{
            int temp = dfs(neigh,current);
            if (temp > most){
                most = temp;
            }
            string edge = to_string(parent) + "->"+to_string(current);
            Depths[edge] = most+1;
        }
    }
    
    string edge = to_string(parent) + "->"+to_string(current);
    Depths[edge] = most+1;

    return most+1;
}

int find_least(int node, int *least, int best, int *Most){
    int most = 0;
    Visited[node] = 1;
    
    for (auto neigh : Graph[node]){
        string edge = to_string(node) + "->"+to_string(neigh); 
        if (Depths[edge] > most){
            most = Depths[edge];
        }
    }
    if (*Most < most){
        *Most = most;
    } 
    if (*least > most){
        *least = most;
        best = node;
    }

    for (auto neigh : Graph[node]){
        if (!Visited[neigh]) best = find_least(neigh,least,best,Most);
    }

    if (best == -1){
        best = node;
        *least = 0;
    }

    return best;
}

bool compare(int n1, int n2){
    return Max[n1] < Max[n2];
}

int main(){
    int n,m;

    cin >> n >> m;

    for (int i=0;i<m;i++){
        int v1,v2;

        cin >> v1 >> v2;

        Graph[v1].push_front(v2);
        Graph[v2].push_front(v1);
    }


    for (int i=0;i<n;i++){
        dfs(i,i);
    }

    

    int count = 0;
    int most = 0;
    for (int i=0;i<n;i++){
        int least = INT_MAX;
        int best;

        if (Visited[i]){
            continue;
        }

        best = find_least(i,&least,-1,&most);

        Max[best] = least;
        count++;

        Bests.push_front(best);
    }
    
    if (count == 1){
        cout << most << "\n";
        return 0;
    }

    if (count == 2){
        cout << max(Max[Bests.back()] + Max[Bests.front()] + 1,most) << "\n";
        return 0;
    }

    Bests.sort(compare);

    cout << max(max(Max[Bests.back()] +  1 + Max[*(prev(prev(Bests.end())))],Max[*(prev(prev(Bests.end())))] + 2 + Max[*(prev(prev(prev(Bests.end()))))]),most) << "\n";

    return 0;
}

