#include <iostream>
#include <climits>
#include <queue>
#include <forward_list>

#define NODES 10005 //should be max number of possible vertices

using namespace std;


forward_list<long long> Graph[NODES];
long long Parent[NODES];
long long Capacity[NODES][NODES];


long long bfs(long long s, long long t) {
    fill(Parent, Parent+NODES, -1);
    Parent[s] = -2;
    queue<pair<long long, long long>> q;
    q.push({s, LLONG_MAX});

    while (!q.empty()) {
        long long cur = q.front().first;
        long long flow = q.front().second;
        q.pop();
        for (long long next : Graph[cur]) {
            if (Parent[next] == -1 && Capacity[cur][next]) {
                Parent[next] = cur;
                long long new_flow = min(flow, Capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

long long maxflow(int s, int t) {
    long long flow = 0;
    long long new_flow;

    while ((new_flow = bfs(s, t))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = Parent[cur];
            Capacity[prev][cur] -= new_flow;
            Capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void addEdge(int n1, int n2, long long cap){
    if (Capacity[n1][n2]){
        return;
    }
    Graph[n1].push_front(n2);
    Capacity[n1][n2] = cap;

    Graph[n2].push_front(n1);
    Capacity[n2][n1] = 0;
}

int main(){


    return 0;
}
