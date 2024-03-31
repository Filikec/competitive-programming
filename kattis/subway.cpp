#include <bits/stdc++.h>

using namespace std;

list<int> Graph1[3001], Graph2[3001];
void get_graph(list<int>* graph,string *p_line){
    auto line = *p_line;

    list<int> prev;
    prev.push_front(0);
    int next = 1;
    for (int i=0;i<line.size();i++){
        if (line[i] == '0'){
            graph[prev.front()].push_back(next);
            graph[next].push_back(prev.front());
            prev.push_front(next++);
        }else{
            prev.pop_front();
        }
    }
    
}

list<int> bfs(list<int> *graph){
    list<int> result,queue;
    int visited[3001];
    
    for (int i=0;i<3001;i++) visited[i] = 0;
    queue.push_back(0);
    visited[0] = 1;

    while (queue.size()){
        auto cur = queue.front();
        queue.pop_front();

        result.push_back(cur);

        for (auto neigh : graph[cur]){
            if (!visited[neigh]) queue.push_back(neigh), visited[neigh] = 1;
        }
    }

    
    return result;
}

bool validate(int node1, int node2, unordered_set<int> *visited1, unordered_set<int> *visited2){
    if (Graph1[node1].size() != Graph2[node2].size()){
        return false;
    }
    if (!Graph1[node1].size() && !Graph2[node2].size()){
        return true;
    }

    unordered_set<int> used;
    visited1->insert(node1);
    visited2->insert(node2);
    
    for (auto child1 : Graph1[node1]){
        bool found = false;
        if (visited1->find(child1) != visited1->end()) continue;
        for (auto child2 : Graph2[node2]){
            if (used.find(child2) == used.end() && visited2->find(child2) == visited2->end() && validate(child1,child2,visited1,visited2)){
                used.insert(child2);
                found = true;
                break;
            }   
        }
        if (!found){
            visited1->erase(node1);
            visited2->erase(node2);
            return false;
        }
    }
    visited1->erase(node1);
    visited2->erase(node2);

    return true;
}

void work(){
    string line;
    for (int i=0;i<3001;i++){
        Graph1[i].clear();
        Graph2[i].clear();
    }
    
    getline(cin,line);
    get_graph(Graph1,&line);
    getline(cin,line);
    get_graph(Graph2,&line);
    
    list<int> one = bfs(Graph1), two = bfs(Graph2);
    unordered_set<int> visited1, visited2;

    if (validate(0,0,&visited1,&visited2)){
        cout << "same\n";
    }else{
        cout << "different\n";
    }
}


int main(){

    int cases;

    cin >> cases;
    cin.get();

    for (int c=0;c<cases;c++){
        work();
    }


    return 0;
}


/*
1
0010011101001011
0100011011001011

1
0100101100100111
0011000111010101

1
001001011001001111
000100111010010111

1
001001011000101111
000100111010010111
*/