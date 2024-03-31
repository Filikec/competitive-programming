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


#include <unordered_map>

unordered_map<long long,long long> map; // results to vertices
unordered_map<long long,long long> map_r; // vertices to results
unordered_map<long long,long long> number1; // first number from input
unordered_map<long long,long long> number2; // second number from input

int main(){
    long long n,v1,v2;

    cin >> n;

    for (int i=1;i<=n;i++){
        cin >> v1 >> v2;

        number1.emplace(4*i,v1);
        number2.emplace(4*i,v2);
        
        if (!map.count(v1+v2)){
            map.emplace(v1+v2,i*4+1);
            map_r.emplace(i*4+1,v1+v2);
        }


        if (!map.count(v1*v2)){
            map.emplace(v1*v2,i*4+2);
            map_r.emplace(i*4+2,v1*v2);
        }

        if (!map.count(v1-v2)){
            map.emplace(v1-v2,i*4+3);
            map_r.emplace(i*4+3,v1-v2);
        }

        addEdge(0,4*i,1);
        
        addEdge(4*i,map[v1+v2],1);
        addEdge(4*i,map[v1*v2],1);
        addEdge(4*i,map[v1-v2],1);

        addEdge(map[v1+v2],4*n+4,1);
        addEdge(map[v1*v2],4*n+4,1);
        addEdge(map[v1-v2],4*n+4,1);
    }

    if (maxflow(0,4*n+4) < n){
        cout << "impossible\n";
        return 0;
    }

    for (int i=4;i<4*n+4;i+=4){ //nodes on 'left side' are multiples of 4
        for (auto e : Graph[i]){
            if (!Capacity[i][e]){
                long long num1, num2;
                char sign;

                num1 = number1[i];
                num2 = number2[i];
            
                if (num1+num2 == map_r[e]){
                    sign = '+';
                }else if(num1*num2 == map_r[e]){
                    sign = '*';
                }else{
                    sign = '-';
                }

                cout << num1 << " " << sign << " " << num2 << " = " << map_r[e] << "\n";
            }
        }
    }

  return 0;    

}
