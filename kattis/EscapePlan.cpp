#include <iostream>
#include <climits>
#include <queue>
#include <forward_list>
#include <unordered_map>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

#define maxn 402

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

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

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



double Distances[200][200];

void work(int m, int s){

    list<pair<double,double>> robots;

    for (int i=0;i<m;i++){
        double x,y;

        cin >> x >> y;

        robots.push_back({x,y});
    }


    int n;

    cin >> n;


    for (int i=0;i<n;i++){
        double x,y;

        cin >> x >> y;

        int j=0;
        for (auto r : robots){
            double difX = r.first-x, difY=r.second-y;
            Distances[j++][i] = sqrt(difX*difX+difY*difY);
        }
    }


    ISAP maxFlow;


    cout << "Scenario " << s << '\n';
    
    

    for (double t=5.0;t<=20.0;t*=2.0){
        maxFlow.init(m+n+2);
        for (int i=0;i<m;i++){ 
            for (int j=0;j<n;j++){
                if (Distances[i][j]/10.0 <= t){
                    maxFlow.AddEdge(i,m+j,1);
                }
            }
        }
        for (int j=0;j<n;j++){
            maxFlow.AddEdge(m+j,m+n+1,1);
        }
        for (int i=0;i<m;i++){
            maxFlow.AddEdge(m+n,i,1);
        }
        cout << "In " << t << " seconds " << maxFlow.Maxflow(m+n,m+n+1) << " robot(s) can escape\n";
    }
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;

    cin >> m;

    int s = 1;
    while (m){

        work(m,s++);


        cin >> m;
    }

    return 0;
}