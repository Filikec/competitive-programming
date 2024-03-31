#include <iostream>
#include <climits>
#include <queue>
#include <forward_list>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

#define maxn 500

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

bool operator<(const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct ISAP {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool vis[maxn];
  int d[maxn];
  int cur[maxn];
  int p[maxn];
  int num[maxn];

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool BFS() {
    fill(vis,vis+maxn,0);
    queue<int> Q;
    Q.push(t);
    vis[t] = 1;
    d[t] = 0;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (unsigned int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i] ^ 1];
        if (!vis[e.from] && e.cap > e.flow) {
          vis[e.from] = 1;
          d[e.from] = d[x] + 1;
          Q.push(e.from);
        }
      }
    }
    return vis[s];
  }

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  int Augment() {
    int x = t, a = INT_MAX;
    while (x != s) {
      Edge& e = edges[p[x]];
      a = min(a, e.cap - e.flow);
      x = edges[p[x]].from;
    }
    x = t;
    while (x != s) {
      edges[p[x]].flow += a;
      edges[p[x] ^ 1].flow -= a;
      x = edges[p[x]].from;
    }
    return a;
  }

  int Maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    int flow = 0;
    BFS();
    fill(num,num+maxn,0);
    for (int i = 0; i < n; i++) num[d[i]]++;
    int x = s;
    fill(cur,cur+maxn,0);
    while (d[s] < n) {
      if (x == t) {
        flow += Augment();
        x = s;
      }
      int ok = 0;
      for (unsigned int i = cur[x]; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (e.cap > e.flow && d[x] == d[e.to] + 1) {
          ok = 1;
          p[e.to] = G[x][i];
          cur[x] = i;
          x = e.to;
          break;
        }
      }
      if (!ok) {
        int m = n - 1;
        for (unsigned int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if (e.cap > e.flow) m = min(m, d[e.to]);
        }
        if (--num[d[x]] == 0) break;
        num[d[x] = m + 1]++;
        cur[x] = 0;
        if (x != s) x = edges[p[x]].from;
      }
    }
    return flow;
  }
};

struct Point{
    long double x,y;
};


Point Gophers[99], Holes[99];
ISAP maxFlow;

long double dist(Point &a ,Point &b){
    long double x = a.x-b.x, y = a.y-b.y;

    return sqrt(x*x+y*y); 
}

long double Dist[198][198];

int main(){
    int n,m;
    long double s,v;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m >> s >> v){
        int nodes = n+m;
        for (int i=0;i<nodes;i++){
            for (int j=0;j<nodes;j++){
                Dist[i][j] = 10000000000.0;
            }
            Dist[i][i] = 0;
        }

        for (int i=0;i<n;i++){
            long double x,y;
            cin >> x >> y;
            Gophers[i] = {x,y};
        }

        for (int i=0;i<m;i++){
            long double x,y;
            cin >> x >> y;
            Holes[i] = {x,y};
            for (int g=0;g<n;g++){
                Dist[g][n+i] = dist(Holes[i],Gophers[g]);
                Dist[n+i][g] = dist(Holes[i],Gophers[g]);
            }
        }

        maxFlow.init(nodes+2);

        for (int i=0;i<n;i++){
            for (int j=n;j<nodes;j++){
                if (Dist[i][j]/v <= s){
                    maxFlow.AddEdge(i,j,n);
                    //cout << i << "->" << j << ":" << n << "\n";
                }
            }
        }

        for (int i=0;i<n;i++){
            //cout << 198 << "->" << i << ":" << 1 << "\n";
            maxFlow.AddEdge(nodes,i,1);
        }

        for (int i=n;i<n+m;i++){
            //cout << i << "->" << 199 << ":" << 1 << "\n";
            maxFlow.AddEdge(i,nodes+1,1);
        }

        cout << n-maxFlow.Maxflow(nodes,nodes+1) << '\n';

    }
    


}