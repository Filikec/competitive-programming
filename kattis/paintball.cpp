#include <iostream>
#include <climits>
#include <queue>
#include <forward_list>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>

using namespace std;

#define maxn 200000

struct Edge {
  int from, to, cap, flow;
  bool org;
  Edge(int u, int v, int c, int f, bool org) : from(u), to(v), cap(c), flow(f), org(org) {}
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
    edges.push_back(Edge(from, to, cap, 0, 1));
    edges.push_back(Edge(to, from, 0, 0, 0));
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

  void init(int n) {// must initiate with the exact number of used nodes
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

ISAP g;

int main(){


    int n,m;

    cin >> n >> m;

    g.init(2*n+2);

    for (int i=0;i<n;i++){
        g.AddEdge(2*n,i,1);
        g.AddEdge(n+i,2*n+1,1);
    }

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g.AddEdge(a,n+b,1);
        g.AddEdge(b,n+a,1);
    }

    auto f = g.Maxflow(2*n,2*n+1);

    if (f != n){
        cout << "Impossible\n";
        return 0;
    }

    list<pair<int,int>> pairs;
    for (auto e : g.edges){
        if (e.from < n && e.to < 2*n && e.org && e.flow) pairs.push_back({e.from,e.to});
    }

    pairs.sort([&](auto p1, auto p2){return p1.first < p2.first;});
    for (auto p : pairs){
        cout << p.second+1-n << '\n';
    }

    return 0;
}
