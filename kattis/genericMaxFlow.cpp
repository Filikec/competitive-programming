#include <iostream>
#include <climits>
#include <queue>
#include <forward_list>
#include <unordered_map>
#include <list>

using namespace std;

class MaxFlow{
    #define NODES 1000 //should be max number of possible vertices
    #define POW 1000000000

    public:

    forward_list<long long> Graph[NODES];
    long long Parent[NODES];
    unordered_map<unsigned long long, long long> Capacity;
    
    void clear(){
        for (int i=0;i<NODES;i++){
            Graph[i].clear();
        }
        Capacity.clear();
    }

    static unsigned long long encodeNodePair( long long n, long long m){
        return n*POW+m;
    }

    static pair<long long,long long> getPairFromEncoding(unsigned long long encoding){
        return {encoding/POW,encoding%POW};
    }
    

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
                unsigned long long encoding = encodeNodePair(cur,next);
                if (Parent[next] == -1 && Capacity[encoding] > 0) {
                    Parent[next] = cur;
                    long long new_flow = min(flow, Capacity[encoding]);
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
                Capacity[encodeNodePair(prev,cur)] -= new_flow;
                Capacity[encodeNodePair(cur,prev)] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }

    void addEdge(int n1, int n2, long long cap){
        unsigned long long encoded1 = encodeNodePair(n1,n2);
        if (Capacity.count(encoded1)){
            Capacity[encoded1] += cap;
        }else{
            Graph[n1].push_front(n2);
            Capacity[encoded1] = cap;
        }

        unsigned long long encoded2 = encodeNodePair(n2,n1);
        if (!Capacity.count(encoded2)){
            Graph[n2].push_front(n1);
            Capacity[encoded2] = 0;
        }
    }
};

MaxFlow maxFlow;
long long Original[1000][1000];

int main(){


    int n,m,s,t;

    cin >> n >> m >> s >> t;
    
    for (int i=0;i<m;i++){
        long long a,b,c;

        cin >> a >> b >> c;
        maxFlow.addEdge(a,b,c);
        Original[a][b] += c;
    }

    int flow = maxFlow.maxflow(s,t);

    list<pair<int,int>> edges;
    for (int a=0;a<n;a++){
        for (auto b:maxFlow.Graph[a]){
            if (Original[a][b]-maxFlow.Capacity[MaxFlow::encodeNodePair(a,b)]>0){
                if (Original[a][b]) edges.push_back({a,b});
            }
        }
        
    }

    cout << n << ' ' << flow <<  ' ' << edges.size() << "\n";

    for (auto e:edges){
        int a = e.first;
        int b = e.second;
        cout << e.first << ' ' << e.second << ' ' << abs(maxFlow.Capacity[MaxFlow::encodeNodePair(a,b)]-Original[a][b]) << '\n';
    }



    return 0;
}